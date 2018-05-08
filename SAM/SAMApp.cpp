#include "SAMApp.h"
#include "BmpManager.h"
#include "SceneManager.h"
#include "SoundManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, PSTR cmdLine, int showCmd)
{
	SAMApp theApp(hInstance);
	if (!theApp.Initialize())
		return 0;

	return theApp.Run();
}

SAMApp::SAMApp(HINSTANCE hInstance) : App(hInstance)
{
}

SAMApp::~SAMApp()
{
	Release();
}

bool SAMApp::Initialize()
{
	if (!App::Initialize())
		return false;

	mhDC = GetDC(mhMainWnd);

	SoundManager::GetInstance()->Initialize();
	SceneManager::GetInstance()->ChangeScene(SceneManager::Title);

	Bmp* backBuffer = new Bmp;
	backBuffer->LoadBmp(L"..\\Image\\BackBuffer.bmp");
	BmpManager::GetInstance()->GetBmpMap().insert(std::make_pair("BackBuffer", backBuffer));

	return true;
}

void SAMApp::Update()
{
	SceneManager::GetInstance()->Update();
}

void SAMApp::Draw()
{
	HDC hBackBuffer = BmpManager::GetInstance()->GetBmpMap()["BackBuffer"]->GetMemDC();
	Rectangle(hBackBuffer, 0, 0, mClientWidth, mClientHeight);

	SceneManager::GetInstance()->Draw(hBackBuffer, 0, 0);

	BitBlt(mhDC, 0, 0, mClientWidth, mClientHeight, hBackBuffer, 0, 0, SRCCOPY);
}

void SAMApp::Release()
{
	ReleaseDC(mhMainWnd, mhDC);
}
