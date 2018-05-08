#include "SceneManager.h"
#include "TitleScene.h"
#include "MainMenuScene.h"
#include "SelectScenarioScene.h"
#include "SelectPrinceScene.h"
#include "WorldMapScene.h"

IMPLEMENT_SINGLETON(SceneManager)

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::ChangeScene(SCENEID eID)
{
	mCurScene = eID;
	
	if (mPreScene != mCurScene)
	{
		if (mScene)
		{
			delete mScene;
			mScene = nullptr;
		}

		switch (mCurScene)
		{
		case Title:
			mScene = new TitleScene;
			break;
		case MainMenu:
			mScene = new MainMenuScene;
			break;
		case SelectScenario:
			mScene = new SelectScenarioScene;
			break;
		case SelectPrince:
			mScene = new SelectPrinceScene;
			break;
		case WorldMap:
			mScene = new WorldMapScene;
			break;			
		}
	}
	mScene->Initialize();
	mPreScene = mCurScene;
}

void SceneManager::Update()
{
	mScene->Update();
}

void SceneManager::Draw(HDC hDC, int x, int y)
{
	mScene->Draw(hDC, x, y);
}

void SceneManager::Release()
{
	if (mScene)
	{
		delete mScene;
		mScene = nullptr;
	}
}
