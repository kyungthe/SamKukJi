#include "Button.h"
#include "BmpManager.h"
#include "App.h"
#include "Key.h"

Button::Button(std::string BitmapKey, int x, int y, std::function<int(void)> update)
	: mBitmapKey(BitmapKey), mUpdate(update)
{
	mRect.left = x;
	mRect.top = y;
	mRect.right = x + BmpManager::GetInstance()->GetBmpMap()[mBitmapKey]->GetWidth();
	mRect.bottom = y + BmpManager::GetInstance()->GetBmpMap()[mBitmapKey]->GetHeight();
}

Button::Button(int x, int y, int width, int height, std::function<int(void)> update)
	: mBitmapKey(""), mUpdate(update)
{
	mRect.left = x;
	mRect.top = y;
	mRect.right = x + width;
	mRect.bottom = y + height;
}

Button::~Button()
{
	Release();
}

void Button::Initialize()
{
}

int Button::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(App::mApp->GetMainWnd(), &pt);

	if (GetAsyncKeyState(VK_LBUTTON) & 0x0001)
	{
		if (PtInRect(&mRect, pt))
		{
			return mUpdate();
		}
	}

	return 0;
}

void Button::Draw(HDC hDC)
{
	Draw(hDC, mRect.left, mRect.top);
}

void Button::Draw(HDC hDC, int x, int y)
{
	if (!mBitmapKey.empty())
	{
		HDC bmpHDC = BmpManager::GetInstance()->GetBmpMap()[mBitmapKey]->GetMemDC();
		BitBlt(hDC, x, y, mRect.left, mRect.top, bmpHDC, 0, 0, SRCCOPY);
	}
}

void Button::Release()
{
}
