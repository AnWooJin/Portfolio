#pragma once
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImage.h>

struct TileIndex
{
public:
	int X;
	int Y;
};

class GameEngineImage;
class GameEngineRendererTileMap;
class Tile
{
	friend GameEngineRendererTileMap;
private:
	GameEngineRenderer* Renderer;

public:
	virtual ~Tile() = 0
	{

	}
};

class GameEngineImage;
class GameEngineRendererTileMap
{
	std::vector<std::vector<Tile*>> Tiles_;
	float4 TileSize_;
	float4 TileSizeHalf_;
	GameEngineActor* Master_;
public:
	// Ÿ�ϸ��� �� ��ü�� ����
	void TileRangeSetting(int _X, int _Y, float4 _TileSize)
	{
		if (0 >= _X)
		{
			MsgBoxAssert("0���� Ÿ�ϸ��� ���� �� �����ϴ�.");
			return;
		}

		if (0 >= _Y)
		{
			MsgBoxAssert("0���� Ÿ�ϸ��� ���� �� �����ϴ�.");
			return;
		}

		Tiles_.resize(_Y);

		for (size_t y = 0; y < Tiles_.size(); y++)
		{
			Tiles_[y].resize(_X);

			for (size_t x = 0; x < Tiles_[y].size(); x++)
			{
				Tiles_[y][x] = nullptr;
			}
		}

		TileSize_ = _TileSize;
		TileSizeHalf_ = _TileSize.Half();
	}
	
	template<typename TileType>
	TileType* GetTile(int _X, int _Y)
	{
		if (0 > _X)
		{
			MsgBoxAssert("0 ������ ���ؽ��� ������ �� �����ϴ�.");
		}

		if (0 > _Y)
		{
			MsgBoxAssert("0 ������ ���ؽ��� ������ �� �����ϴ�.");
		}


		if (_Y >= Tiles_.size())
		{
			MsgBoxAssert("������ �ѱ� �� �����ϴ�.");
		}


		if (_X >= Tiles_.size())
		{
			MsgBoxAssert("������ �ѱ� �� �����ϴ�.");
		}

		return reinterpret_cast<TileType*>(Tiles_[_Y][_X]);
	}

	bool IsTile(int _X, int _Y)
	{
		return GetTile<Tile>(_X, _Y) == nullptr;
	}

	template<typename TileType>
	TileType* CreateTile(const float4& _Pos, const std::string& _Image, int _Order = static_cast<int>(EngineMax::RENDERORDERMAX))
	{
		TileIndex Index = GetTileIndex(_Pos);
		return CreateTile<TileType>(Index.X, Index.Y, _Image);
	}

	// Ÿ�� �̹����� �������� ������
	template<typename TileType>
	TileType* CreateTile(int _X, int _Y, const std::string& _Image, int _Order = static_cast<int>(EngineMax::RENDERORDERMAX))
	{
		Tile* FindTile = GetTile<Tile>(_X, _Y);
		if (nullptr == FindTile)
		{
			FindTile = new TileType();
			FindTile->Renderer = Master_->CreateRenderer(_Image, _Order);
		}
		else
		{
			FindTile->Renderer->SetImage(_Image);
		}
		FindTile->Renderer->SetPivot(GetWorldPosition(_X, _Y));

		Tiles_[_Y][_X] = FindTile;

		return reinterpret_cast<TileType*>(FindTile);
	}

	// Ÿ�� �̹����� ������ ���ִµ� �� ���� ��
	template<typename TileType>
	TileType* CreateTile(int _X, int _Y, const std::string& _Image, int Index, int _Order)
	{
		TileType* Tile = CreateTile(_X, _Y, _Image);
		Tile->Renderer->SetIndex(Index);
		Tile->Renderer->SetPivot(GetWorldPosition(_X, _Y));
		return reinterpret_cast<TileType*>(Tile);
	}

	
	void DeleteTile(int _X, int _Y);

	// 0.0(����)�� �������� ��ġ�ϴ� ������
	float4 GetWorldPosition(int _X, int _Y);
	TileIndex GetTileIndex(const float4& _Pos);

public:
	GameEngineRendererTileMap(GameEngineActor* _Actor)
		: Master_(_Actor)
	{
	}

	virtual ~GameEngineRendererTileMap()
	{
	}
};

