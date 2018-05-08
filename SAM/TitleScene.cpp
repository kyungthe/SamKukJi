#include "TitleScene.h"
#include "BmpManager.h"
#include "Button.h"
#include "Key.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "SoundManager.h"

TitleScene::~TitleScene()
{
	Release();
}

void TitleScene::Initialize()
{
	Bmp* title1 = new Bmp;
	title1->LoadBmp(L"..\\Image\\Title1.bmp");
	BmpManager::GetInstance()->GetBmpMap().insert(std::make_pair("Title", title1));

	Object* button = new Button(0, 0, 640, 480, [] {
		SoundManager::GetInstance()->PlaySound("SY02.wav", SoundManager::EFFECT, false);
		SceneManager::GetInstance()->ChangeScene(SceneManager::MainMenu);

		return CHANGESCENE;
	});
	ObjectManager::GetInstance()->AddObject(button, ObjectManager::OBJ_UI);
	
	Object* spaceKey = new Key(VK_SPACE, Key::DOWN, [] {
		SoundManager::GetInstance()->PlaySound("SY02.wav", SoundManager::EFFECT, false);
		SceneManager::GetInstance()->ChangeScene(SceneManager::MainMenu);

		return CHANGESCENE;
	});
	ObjectManager::GetInstance()->AddObject(spaceKey, ObjectManager::OBJ_UI);
}

void TitleScene::Update()
{
	ObjectManager::GetInstance()->Update();
}

void TitleScene::Draw(HDC hDC, int x, int y)
{
	Bmp* title = BmpManager::GetInstance()->GetBmpMap()["Title"];
	BitBlt(hDC, x, y, title->GetWidth(), title->GetHeight(), title->GetMemDC(), 0, 0, SRCCOPY);
}

void TitleScene::Release()
{
	ObjectManager::GetInstance()->Release();
}
