#include "OpeningLevel.h"
#include "OpeningBackGround.h"
#include "UnityLogo.h"

OpeningLevel::OpeningLevel()
{
}

OpeningLevel::~OpeningLevel()
{
}

void OpeningLevel::Loading()
{
	CreateActor<OpeningBackGround>(0);
	CreateActor<UnityLogo>(1);
}

void OpeningLevel::Update()
{

}