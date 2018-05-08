#include "Bmp.h"
#include "App.h"

Bmp::~Bmp()
{
	Release();
}

void Bmp::LoadBmp(std::wstring filePath)
{
	HWND hWnd = App::GetApp()->GetMainWnd();
	mhDC = GetDC(hWnd);

	mhMemDC = CreateCompatibleDC(mhDC);
	ReleaseDC(hWnd, mhDC);

	mhBitmap = (HBITMAP)LoadImage(0, filePath.c_str(), IMAGE_BITMAP
		, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	BITMAP bitmap;
	GetObject(mhBitmap, sizeof(BITMAP), &bitmap);
	mWidth = bitmap.bmWidth;
	mHeight = bitmap.bmHeight;

	mhBitOld = (HBITMAP)SelectObject(mhMemDC, mhBitmap);
}

void Bmp::Release()
{
	SelectObject(mhMemDC, mhBitOld);
	DeleteObject(mhBitmap);
	DeleteDC(mhMemDC);
}
