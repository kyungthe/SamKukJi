#include "SelectPrinceScene.h"
#include "BmpManager.h"
#include "Key.h"
#include "SoundManager.h"
#include "SceneManager.h"
#include "ObjectManager.h"

SelectPrinceScene::~SelectPrinceScene()
{
	Release();
}

void SelectPrinceScene::Initialize()
{
	Bmp* selectPrince = new Bmp;
	selectPrince->LoadBmp(L"..\\Image\\SelectPrince1.bmp");
	BmpManager::GetInstance()->GetBmpMap().insert(std::make_pair("SelectPrince1", selectPrince));

	Object* spaceKey = new Key(VK_SPACE, Key::DOWN, [] {
		SoundManager::GetInstance()->PlaySound("SY02.wav", SoundManager::EFFECT, false);
		SceneManager::GetInstance()->ChangeScene(SceneManager::WorldMap);

		return CHANGESCENE;
	});
	ObjectManager::GetInstance()->AddObject(spaceKey, ObjectManager::OBJ_UI);

	Object* escKey = new Key(VK_ESCAPE, Key::KEYPROCESS::DOWN, [] {
		SoundManager::GetInstance()->PlaySound("SY03.wav", SoundManager::EFFECT, false);
		SceneManager::GetInstance()->ChangeScene(SceneManager::SelectScenario);

		return CHANGESCENE;
	});
	ObjectManager::GetInstance()->AddObject(escKey, ObjectManager::OBJ_UI);
}

void SelectPrinceScene::Update()
{
	ObjectManager::GetInstance()->Update();
}

void SelectPrinceScene::Draw(HDC hDC, int x, int y)
{
	Bmp* selectPrince = BmpManager::GetInstance()->GetBmpMap()["SelectPrince1"];
	BitBlt(hDC, x, y, selectPrince->GetWidth(), selectPrince->GetHeight(), selectPrince->GetMemDC(), 0, 0, SRCCOPY);
}

void SelectPrinceScene::Release()
{
	ObjectManager::GetInstance()->Release();
}
