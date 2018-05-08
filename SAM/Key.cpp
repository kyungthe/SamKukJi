#include "Key.h"

Key::Key(int key, KEYPROCESS pro, std::function<int(void)> update)
	: mKey(key), mProcess(pro), mUpdate(update)
{
}

bool Key::KeyPressing()
{
	if (GetAsyncKeyState(mKey) & 0x8000)
	{
		return true;
	}

	return false;
}

bool Key::KeyDown()
{
	if (GetAsyncKeyState(mKey) & 0x0001)
	{
		return true;
	}

	return false;
}

bool Key::KeyUp()
{
	if (!(GetAsyncKeyState(mKey) & 0x0001))
	{
		return true;
	}

	return false;
}

int Key::Update()
{
	switch (mProcess)
	{
	case PRESSING:
		if (KeyPressing())
		{
			return mUpdate();
		}
		break;
	case DOWN:
		if (KeyDown())
		{
			return mUpdate();
		}
		break;
	case UP:
		if (KeyUp())
		{
			return mUpdate();
		}
		break;
	}

	return 0;
}

void Key::Initialize()
{
}

void Key::Draw(HDC hDC)
{
}

void Key::Release()
{
}
