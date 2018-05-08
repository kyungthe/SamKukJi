#ifndef _WORLDMAP_SCENE_H_
#define _WORLDMAP_SCENE_H_

#include "Scene.h"

#define MAP_WIDTH	4
#define MAP_HEIGHT	5

class WorldMapScene : public Scene
{
public:
	WorldMapScene() {}
	virtual ~WorldMapScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw(HDC hDC, int x, int y) override;
	virtual void Release() override;

private:
	RECT mClient;
	int mScrollX = 0;
	int mScrollY = 0;
};

#endif // !_WORLDMAP_SCENE_H_
