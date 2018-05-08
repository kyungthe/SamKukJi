#include "SelectScenarioScene.h"
#include "BmpManager.h"
#include "Key.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "Button.h"
#include "ObjectManager.h"

SelectScenarioScene::~SelectScenarioScene()
{
	Release();
}

void SelectScenarioScene::Initialize()
{
	Bmp* selectScenario = new Bmp;
	selectScenario->LoadBmp(L"..\\Image\\SelectScenario1.bmp");
	BmpManager::GetInstance()->GetBmpMap().insert(std::make_pair("SelectScenario1", selectScenario));

	Object* button = new Button(405, 130, 40, 250, [] {
		SoundManager::GetInstance()->PlaySound("SY02.wav", SoundManager::EFFECT, false);
		SceneManager::GetInstance()->ChangeScene(SceneManager::SelectPrince);

		return CHANGESCENE;
	});
	ObjectManager::GetInstance()->AddObject(button, ObjectManager::OBJ_UI);

	Object* spaceKey = new Key(VK_SPACE, Key::DOWN, [] {
		SoundManager::GetInstance()->PlaySound("SY02.wav", SoundManager::EFFECT, false);
		SceneManager::GetInstance()->ChangeScene(SceneManager::SelectPrince);

		return CHANGESCENE;
	});
	ObjectManager::GetInstance()->AddObject(spaceKey, ObjectManager::OBJ_UI);

	Object* escKey = new Key(VK_ESCAPE, Key::DOWN, [] {
		SoundManager::GetInstance()->PlaySound("SY03.wav", SoundManager::EFFECT, false);
		SceneManager::GetInstance()->ChangeScene(SceneManager::MainMenu);

		return CHANGESCENE;
	});
	ObjectManager::GetInstance()->AddObject(escKey, ObjectManager::OBJ_UI);
}

void SelectScenarioScene::Update()
{
	ObjectManager::GetInstance()->Update();
}

void SelectScenarioScene::Draw(HDC hDC, int x, int y)
{
	Bmp* SelectScenario = BmpManager::GetInstance()->GetBmpMap()["SelectScenario1"];
	BitBlt(hDC, x, y, SelectScenario->GetWidth(), SelectScenario->GetHeight(), SelectScenario->GetMemDC(), 0, 0, SRCCOPY);
}

void SelectScenarioScene::Release()
{
	ObjectManager::GetInstance()->Release();
}