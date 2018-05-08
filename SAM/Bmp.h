#ifndef _BMP_H_
#define _BMP_H_

#include <Windows.h>
#include <string>

class Bmp
{
private:
	HDC mhDC;
	HDC mhMemDC;
	HBITMAP mhBitmap;
	HBITMAP mhBitOld;
	int mWidth;
	int mHeight;

public:
	Bmp() {}
	~Bmp();
	HDC GetMemDC() const { return mhMemDC; }
	int GetWidth() const { return mWidth; }
	int GetHeight() const { return mHeight; }

	void LoadBmp(std::wstring pFilePath);
	void Release();
};

#endif // !_BMP_H_
