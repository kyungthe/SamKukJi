#include "MainMenuScene.h"
#include "BmpManager.h"
#include "SoundManager.h"
#include "Button.h"
#include "SceneManager.h"
#include "Key.h"
#include "ObjectManager.h"

MainMenuScene::~MainMenuScene()
{
	Release();
}

void MainMenuScene::Initialize()
{
	Bmp* mainMenu = new Bmp;
	mainMenu->LoadBmp(L"..\\Image\\MainMenu1.bmp");
	BmpManager::GetInstance()->GetBmpMap().insert(std::make_pair("MainMenu", mainMenu));

	SoundManager::GetInstance()->PlaySound("BGM01.WAV", SoundManager::BGM, true);

	Object* button = new Button(190, 330, 256, 30, [] {
		SoundManager::GetInstance()->PlaySound("SY02.wav", SoundManager::EFFECT, false);
		SceneManager::GetInstance()->ChangeScene(SceneManager::SelectScenario);

		return CHANGESCENE;
	});
	ObjectManager::GetInstance()->AddObject(button, ObjectManager::OBJ_UI);

	Object* spaceKey = new Key(VK_SPACE, Key::DOWN, [] {
		SoundManager::GetInstance()->PlaySound("SY02.wav", SoundManager::EFFECT, false);
		SceneManager::GetInstance()->ChangeScene(SceneManager::SelectScenario);

		return CHANGESCENE;
	});
	ObjectManager::GetInstance()->AddObject(spaceKey, ObjectManager::OBJ_UI);
}

void MainMenuScene::Update()
{
	ObjectManager::GetInstance()->Update();
}

void MainMenuScene::Draw(HDC hDC, int x, int y)
{
	Bmp* mainMenu = BmpManager::GetInstance()->GetBmpMap()["MainMenu"];
	BitBlt(hDC, x, y, mainMenu->GetWidth(), mainMenu->GetHeight(), mainMenu->GetMemDC(), 0, 0, SRCCOPY);
}

void MainMenuScene::Release()
{
	ObjectManager::GetInstance()->Release();
}
