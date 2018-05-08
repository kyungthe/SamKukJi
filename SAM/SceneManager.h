#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include "Singleton.h"
#include <Windows.h>

class Scene;
class SceneManager
{
	DECLARE_SINGLETON(SceneManager)
public:
	enum SCENEID { Title, MainMenu, SelectScenario, SelectPrince, WorldMap, End };

	SceneManager() {}
	~SceneManager();

	void ChangeScene(SCENEID eID);
	void Update();
	void Draw(HDC hDC, int x, int y);
	void Release();

private:
	Scene* mScene = nullptr;
	SCENEID mCurScene = End;
	SCENEID mPreScene = End;
};

#endif // !_SCENEMANAGER_H_
