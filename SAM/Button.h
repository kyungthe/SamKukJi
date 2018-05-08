#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Object.h"
#include <string>
#include <functional>

class Button : public Object
{	
public:
	Button(std::string BitmapKey, int x, int y, std::function<int(void)> update);
	Button(int x, int y, int width, int height, std::function<int(void)> update);
	virtual ~Button();

	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Draw(HDC hDC) override;
	virtual void Release() override;

private:
	RECT mRect;
	std::string mBitmapKey;
	std::function<int(void)> mUpdate;

	void Draw(HDC hDC, int x, int y);
};

#endif // !_BUTTON_H_
