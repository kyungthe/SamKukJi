#ifndef _MAINMENU_H_
#define _MAINMENU_H_

#include "Scene.h"

class MainMenuScene : public Scene
{
public:
	MainMenuScene() {}
	virtual ~MainMenuScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw(HDC hDC, int x, int y) override;
	virtual void Release() override;
};

#endif // !_MAINMENU_H_
