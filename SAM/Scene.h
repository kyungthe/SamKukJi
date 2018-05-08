#ifndef _SCENE_H_
#define _SCENE_H_

#include <Windows.h>

class Scene
{
public:
	Scene() {}
	virtual ~Scene() {}

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw(HDC hDC, int x, int y) = 0;
	virtual void Release() = 0;
};

#endif // !_SCENE_H_
