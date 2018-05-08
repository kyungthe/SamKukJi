#ifndef _KEYMANAGER_H_
#define _KEYMANAGER_H_

#include <Windows.h>
#include "Object.h"
#include <functional>

class Key : public Object
{
public:
	enum KEYPROCESS { PRESSING, DOWN, UP };

	Key(int key, KEYPROCESS pro, std::function<int(void)> update);
	virtual ~Key() {}
	
	virtual int Update() override;

private:
	bool KeyPressing();
	bool KeyDown();
	bool KeyUp();

	virtual void Initialize() override;
	virtual void Draw(HDC hDC) override;
	virtual void Release() override;

private:
	int mKey;
	KEYPROCESS mProcess;
	std::function<int(void)> mUpdate;
};

#endif // !_KEYMANAGER_H_
