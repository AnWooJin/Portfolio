#include "GameEngineLevel.h"
#include "GameEngineActor.h"
#include "GameEngineCollision.h"
#include "GameEngineRenderer.h"
#include <GameEngineBase/GameEngineDebug.h>

bool GameEngineLevel::IsDebug = false;

GameEngineLevel::GameEngineLevel()
	: CameraPos_(float4::ZERO)
	, IsReset(false)
{
}

GameEngineLevel::~GameEngineLevel()
{
	std::map<int, std::list<GameEngineActor*>>::iterator GroupStart = AllActor_.begin();
	std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd = AllActor_.end();

	for (; GroupStart != GroupEnd; ++GroupStart)
	{
		std::list<GameEngineActor*>& Group = GroupStart->second;

		std::list<GameEngineActor*>::iterator StartActor = Group.begin();
		std::list<GameEngineActor*>::iterator EndActor = Group.end();

		for (; StartActor != EndActor; ++StartActor)
		{
			if (nullptr == (*StartActor))
			{
				continue;
			}
			delete (*StartActor);
			(*StartActor) = nullptr;
		}
	}
}

void GameEngineLevel::Reset()
{
	{
		std::map<int, std::list<GameEngineRenderer*>>::iterator GroupStart = AllRenderer_.begin();
		std::map<int, std::list<GameEngineRenderer*>>::iterator GroupEnd = AllRenderer_.end();

		std::list<GameEngineRenderer*>::iterator StartRenderer;
		std::list<GameEngineRenderer*>::iterator EndRenderer;


		for (; GroupStart != GroupEnd; ++GroupStart)
		{
			std::list<GameEngineRenderer*>& Group = GroupStart->second;
			StartRenderer = Group.begin();
			EndRenderer = Group.end();
			for (; StartRenderer != EndRenderer; )
			{
				if (true == (*StartRenderer)->GetActor()->IsResetIgnore)
				{
					++StartRenderer;
					continue;
				}

				StartRenderer = Group.erase(StartRenderer);
			}
		}
	}

	// �ݸ����� ������ �����ϰ� �����Ƿ�
	{
		std::map<std::string, std::list<GameEngineCollision*>>::iterator GroupStart = AllCollision_.begin();
		std::map<std::string, std::list<GameEngineCollision*>>::iterator GroupEnd = AllCollision_.end();

		std::list<GameEngineCollision*>::iterator StartCollision;
		std::list<GameEngineCollision*>::iterator EndCollision;


		for (; GroupStart != GroupEnd; ++GroupStart)
		{
			std::list<GameEngineCollision*>& Group = GroupStart->second;
			StartCollision = Group.begin();
			EndCollision = Group.end();
			for (; StartCollision != EndCollision; )
			{
				if (true == (*StartCollision)->GetActor()->IsResetIgnore)
				{
					++StartCollision;
					continue;
				}

				StartCollision = Group.erase(StartCollision);
			}
		}

	}

	// ������ ����
	{
		std::map<int, std::list<GameEngineActor*>>::iterator GroupStart;
		std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd;

		std::list<GameEngineActor*>::iterator StartActor;
		std::list<GameEngineActor*>::iterator EndActor;

		GroupStart = AllActor_.begin();
		GroupEnd = AllActor_.end();

		for (; GroupStart != GroupEnd; ++GroupStart)
		{
			std::list<GameEngineActor*>& Group = GroupStart->second;

			StartActor = Group.begin();
			EndActor = Group.end();
			for (; StartActor != EndActor; )
			{
				if (false == (*StartActor)->IsResetIgnore)
				{
					delete* StartActor;
					StartActor = Group.erase(StartActor);
					continue;
				}
				++StartActor;
			}
		}
	}
}

void GameEngineLevel::ActorUpdate()
{
	std::map<int, std::list<GameEngineActor*>>::iterator GroupStart;
	std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd;

	std::list<GameEngineActor*>::iterator StartActor;
	std::list<GameEngineActor*>::iterator EndActor;

	GroupStart = AllActor_.begin();
	GroupEnd = AllActor_.end();

	for (; GroupStart != GroupEnd; ++GroupStart)
	{
		std::list<GameEngineActor*>& Group = GroupStart->second;

		StartActor = Group.begin();
		EndActor = Group.end();

		for (; StartActor != EndActor; ++StartActor)
		{
			(*StartActor)->ReleaseUpdate();
			(*StartActor)->AddAccTime(GameEngineTime::GetDeltaTime());
			if (false == (*StartActor)->IsUpdate())
			{
				continue;
			}

			(*StartActor)->Update();
		}
	}

	for (size_t i = 0; i < ChangeOrderList.size(); i++)
	{
		ChangeOrderItem& Data = ChangeOrderList[i]; // ������ ����� ���Ϳ� ������ ������ �޴´�.
		AllActor_[Data.TargetObejct->GetOrder()].remove(Data.TargetObejct);  // ������ �����ϴ� AllAcotr_���� ������ ����� ���͸� �����Ѵ�.
		Data.TargetObejct->GameEngineUpdateObject::SetOrder(Data.ChangeOrder); // ������ ������ ����� ������ �ٲ۴�.
		AllActor_[Data.TargetObejct->GetOrder()].push_back(Data.TargetObejct); // ������ ������ ���͸� �ٽ� ������ �����ϴ� AllAcotr_�� ������Ѵ�.

	}
	ChangeOrderList.clear(); // ������ ���� �� ���� ����Ʈ�� ���� �����Ѵ�.
}

void GameEngineLevel::ActorLevelChangeStart(GameEngineLevel* _PrevLevel)
{
	{
		std::map<int, std::list<GameEngineActor*>>::iterator GroupStart;
		std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd;

		std::list<GameEngineActor*>::iterator StartActor;
		std::list<GameEngineActor*>::iterator EndActor;

		GroupStart = AllActor_.begin();
		GroupEnd = AllActor_.end();

		for (; GroupStart != GroupEnd; ++GroupStart)
		{
			std::list<GameEngineActor*>& Group = GroupStart->second;


			StartActor = Group.begin();
			EndActor = Group.end();

			for (; StartActor != EndActor; ++StartActor)
			{
				if (false == (*StartActor)->IsUpdate())
				{
					continue;
				}
				(*StartActor)->LevelChangeStart(_PrevLevel);
			}
		}
	}
}

GameEngineActor* GameEngineLevel::FindActor(const std::string& _Name)
{
	std::map<std::string, GameEngineActor*>::iterator FindIter = RegistActor_.find(_Name);

	if (RegistActor_.end() == FindIter)
	{
		return nullptr;
	}

	return FindIter->second;
}

void GameEngineLevel::RegistActor(const std::string& _Name, GameEngineActor* _Actor)
{
	if (RegistActor_.end() != RegistActor_.find(_Name))
	{
		MsgBoxAssert("�̹� �����ϴ� �̸����� �� ����Ϸ��� �߽��ϴ�.");
	}

	RegistActor_.insert(std::map<std::string, GameEngineActor*>::value_type(_Name, _Actor));
}

void GameEngineLevel::ActorLevelChangeEnd(GameEngineLevel* _NextLevel)
{
	{
		std::map<int, std::list<GameEngineActor*>>::iterator GroupStart;
		std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd;

		std::list<GameEngineActor*>::iterator StartActor;
		std::list<GameEngineActor*>::iterator EndActor;

		GroupStart = AllActor_.begin();
		GroupEnd = AllActor_.end();

		for (; GroupStart != GroupEnd; ++GroupStart)
		{
			std::list<GameEngineActor*>& Group = GroupStart->second;


			StartActor = Group.begin();
			EndActor = Group.end();

			for (; StartActor != EndActor; ++StartActor)
			{
				if (false == (*StartActor)->IsUpdate())
				{
					continue;
				}
				(*StartActor)->LevelChangeEnd(_NextLevel);
			}
		}
	}
}

bool SortY(GameEngineRenderer* _Left, GameEngineRenderer* _Right)
{
	return _Left->GetSortingPivot().y < _Right->GetSortingPivot().y;
}

void GameEngineLevel::ActorRender()
{
	// ������ ����
	{
		std::map<int, std::list<GameEngineRenderer*>>::iterator GroupStart = AllRenderer_.begin();
		std::map<int, std::list<GameEngineRenderer*>>::iterator GroupEnd = AllRenderer_.end();

		std::list<GameEngineRenderer*>::iterator StartRenderer;
		std::list<GameEngineRenderer*>::iterator EndRenderer;

		for (; GroupStart != GroupEnd; ++GroupStart)
		{
			std::list<GameEngineRenderer*>& Group = GroupStart->second;


			// �� �׷찣���� ������ �˴ϴ�
			if (IsYSort_.end() != IsYSort_.find(GroupStart->first))
			{
				Group.sort(SortY);
			}

			StartRenderer = Group.begin();
			EndRenderer = Group.end();
			for (; StartRenderer != EndRenderer; ++StartRenderer)
			{
				if (false == (*StartRenderer)->IsUpdate())
				{
					continue;
				}

				(*StartRenderer)->Render();
			}
		}
	}
	{
		std::map<int, std::list<GameEngineActor*>>::iterator GroupStart;
		std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd;

		std::list<GameEngineActor*>::iterator StartActor;
		std::list<GameEngineActor*>::iterator EndActor;

		GroupStart = AllActor_.begin();
		GroupEnd = AllActor_.end();

		for (; GroupStart != GroupEnd; ++GroupStart)
		{
			std::list<GameEngineActor*>& Group = GroupStart->second;


			StartActor = Group.begin();
			EndActor = Group.end();

			for (; StartActor != EndActor; ++StartActor)
			{
				if (false == (*StartActor)->IsUpdate())
				{
					continue;
				}
				(*StartActor)->Render();
			}
		}
	}
}

void GameEngineLevel::CollisionDebugRender()
{
	if (false == IsDebug)
	{
		return;
	}

	std::map<std::string, std::list<GameEngineCollision*>>::iterator GroupStart = AllCollision_.begin();
	std::map<std::string, std::list<GameEngineCollision*>>::iterator GroupEnd = AllCollision_.end();

	std::list<GameEngineCollision*>::iterator StartCollision;
	std::list<GameEngineCollision*>::iterator EndCollision;

	for (; GroupStart != GroupEnd; ++GroupStart)
	{
		std::list<GameEngineCollision*>& Group = GroupStart->second;

		StartCollision = Group.begin();
		EndCollision = Group.end();

		for (; StartCollision != EndCollision; ++StartCollision)
		{
			if (false == (*StartCollision)->IsUpdate())
			{
				continue;
			}

			(*StartCollision)->DebugRender();
		}
	}

}

void GameEngineLevel::ActorRelease()
{
	// ������ �������� �����ϹǷ� list���� �������� �����ش�, �ݸ����� ���������� delete�� �ؼ��� �ȵȴ�. 
	{
		std::map<int, std::list<GameEngineRenderer*>>::iterator GroupStart = AllRenderer_.begin();
		std::map<int, std::list<GameEngineRenderer*>>::iterator GroupEnd = AllRenderer_.end();

		std::list<GameEngineRenderer*>::iterator StartRenderer;
		std::list<GameEngineRenderer*>::iterator EndRenderer;

		for (; GroupStart != GroupEnd; ++GroupStart)
		{
			std::list<GameEngineRenderer*>& Group = GroupStart->second;
			StartRenderer = Group.begin();
			EndRenderer = Group.end();

			for (; StartRenderer != EndRenderer;)
			{
				if (false == (*StartRenderer)->IsDeath())
				{
					++StartRenderer;
					continue;
				}

				StartRenderer = Group.erase(StartRenderer);
			}
		}
	}


	// ������ �����ϴ� AllCollision_���� ������ �ݸ����� �����Ѵ�. ���� delete�� �����ؼ��� �ȵȴ�.
	{
		std::map<std::string, std::list<GameEngineCollision*>>::iterator GroupStart = AllCollision_.begin();
		std::map<std::string, std::list<GameEngineCollision*>>::iterator GroupEnd = AllCollision_.end();

		std::list<GameEngineCollision*>::iterator StartCollision;
		std::list<GameEngineCollision*>::iterator EndCollision;

		for (; GroupStart != GroupEnd; ++GroupStart)
		{
			std::list<GameEngineCollision*>& Group = GroupStart->second;
			StartCollision = Group.begin();
			EndCollision = Group.end();

			for (; StartCollision != EndCollision;)
			{
				if (false == (*StartCollision)->IsDeath())
				{
					++StartCollision;
					continue;
				}

				StartCollision = Group.erase(StartCollision);
			}
		}
	}

	// ������ ����
	{
		std::map<int, std::list<GameEngineActor*>>::iterator GroupStart;
		std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd;

		std::list<GameEngineActor*>::iterator StartActor;
		std::list<GameEngineActor*>::iterator EndActor;

		GroupStart = AllActor_.begin();
		GroupEnd = AllActor_.end();

		for (; GroupStart != GroupEnd; ++GroupStart)
		{
			std::list<GameEngineActor*>& Group = GroupStart->second;

			StartActor = Group.begin();
			EndActor = Group.end();

			for (; StartActor != EndActor;)
			{
				if (true == (*StartActor)->IsDeath())
				{
					delete (*StartActor);
					StartActor = Group.erase(StartActor);
					continue;
				}

				// ������ �ȉ�ٸ� �ݸ����̳� �������� Ȯ���Ѵ�.
				(*StartActor)->Release();

				++StartActor;
			}
		}
	}

	
}



void GameEngineLevel::AddRenderer(GameEngineRenderer* _Renderer)
{
	AllRenderer_[_Renderer->GetOrder()].push_back(_Renderer);
}

void GameEngineLevel::ChangeUpdateOrder(GameEngineActor* _Actor, int _NewOrder)
{
	if (_Actor->GetOrder() == _NewOrder)
	{
		return;
	}
	ChangeOrderList.push_back({ _Actor, _NewOrder });
}



void GameEngineLevel::ChangeRenderOrder(GameEngineRenderer* _Renderer, int _NewOrder)
{
	if (_Renderer->GetOrder() == _NewOrder)
	{
		return;
	}
	AllRenderer_[_Renderer->GetOrder()].remove(_Renderer);

	_Renderer->GameEngineUpdateObject::SetOrder(_NewOrder);

	AllRenderer_[_Renderer->GetOrder()].push_back(_Renderer);
}

void GameEngineLevel::AddCollision(const std::string& _GroupName, GameEngineCollision* _Collision)
{
	_Collision->CollisionName_ = _GroupName;
	AllCollision_[_GroupName].push_back(_Collision);
}

void GameEngineLevel::ObjectLevelMoveCheck(GameEngineLevel* _NextLevel)
{
	{
		std::map<int, std::list<GameEngineRenderer*>>::iterator GroupStart = AllRenderer_.begin();
		std::map<int, std::list<GameEngineRenderer*>>::iterator GroupEnd = AllRenderer_.end();

		std::list<GameEngineRenderer*>::iterator StartRenderer;
		std::list<GameEngineRenderer*>::iterator EndRenderer;

		for (; GroupStart != GroupEnd; ++GroupStart)
		{
			std::list<GameEngineRenderer*>& Group = GroupStart->second;
			StartRenderer = Group.begin();
			EndRenderer = Group.end();
			for (; StartRenderer != EndRenderer; )
			{
				if (false == (*StartRenderer)->GetActor()->NextLevelOn_)
				{
					++StartRenderer;
					continue;
				}

				GameEngineRenderer* Object = *StartRenderer;
				_NextLevel->AllRenderer_[Object->GetOrder()].push_back(Object);


				StartRenderer = Group.erase(StartRenderer);
			}
		}

	}

	{
		{
			std::map<std::string, std::list<GameEngineCollision*>>::iterator GroupStart = AllCollision_.begin();
			std::map<std::string, std::list<GameEngineCollision*>>::iterator GroupEnd = AllCollision_.end();

			std::list<GameEngineCollision*>::iterator StartCollision;
			std::list<GameEngineCollision*>::iterator EndCollision;


			for (; GroupStart != GroupEnd; ++GroupStart)
			{
				std::list<GameEngineCollision*>& Group = GroupStart->second;
				StartCollision = Group.begin();
				EndCollision = Group.end();
				for (; StartCollision != EndCollision; )
				{
					if (false == (*StartCollision)->GetActor()->NextLevelOn_)
					{
						++StartCollision;
						continue;
					}

					GameEngineCollision* Object = *StartCollision;
					_NextLevel->AllCollision_[Object->CollisionName_].push_back(Object);

					StartCollision = Group.erase(StartCollision);
				}
			}

		}
	}

	{
		{
			std::map<int, std::list<GameEngineActor*>>::iterator GroupStart;
			std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd;

			std::list<GameEngineActor*>::iterator StartActor;
			std::list<GameEngineActor*>::iterator EndActor;

			GroupStart = AllActor_.begin();
			GroupEnd = AllActor_.end();

			for (; GroupStart != GroupEnd; ++GroupStart)
			{
				std::list<GameEngineActor*>& Group = GroupStart->second;

				StartActor = Group.begin();
				EndActor = Group.end();
				for (; StartActor != EndActor; )
				{
					if (true == (*StartActor)->NextLevelOn_)
					{
						// ���⼭ �Űܰ���.
						GameEngineActor* Object = *StartActor;
						Object->SetLevel(_NextLevel);
						Object->NextLevelOff();
						_NextLevel->AllActor_[Object->GetOrder()].push_back(Object);

						StartActor = Group.erase(StartActor);
						continue;
					}

					++StartActor;
				}
			}
		}
	}
}