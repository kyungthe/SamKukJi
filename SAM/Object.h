#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <Windows.h>

#define CHANGESCENE	1

class Object
{
public:
	Object() {}
	~Object() {}

	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Draw(HDC hDC) = 0;
	virtual void Release() = 0;
};

#endif // !_OBJECT_H_
