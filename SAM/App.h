#ifndef _APP_H_
#define _APP_H_

#include <Windows.h>

class App
{
public:
	static App* mApp;

protected:
	HINSTANCE	mhAppInst;
	HWND		mhMainWnd = nullptr;
	int			mClientWidth = 640;
	int			mClientHeight = 480;
	WCHAR*		mMainWndCaption = L"App";
	HDC			mhDC;

protected:
	App(HINSTANCE hInstance);
	App(const App& rhs) = delete;
	App& operator=(const App& rhs) = delete;
	virtual ~App() {}

public:
	static App* GetApp() { return mApp; }

	HINSTANCE GetAppInst() const { return mhAppInst; }
	HWND GetMainWnd() const { return mhMainWnd; }
	int GetWidth() const { return mClientWidth; }
	int GetHeight() const { return mClientHeight; }

	virtual bool Initialize();
	virtual LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	int Run();

protected:
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

#endif // !_APP_H_
