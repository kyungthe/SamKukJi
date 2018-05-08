#ifndef _SELECTSCENARIOSCENE_H_
#define _SELECTSCENARIOSCENE_H_

#include "Scene.h"

class SelectScenarioScene : public Scene
{
public:
	SelectScenarioScene() {}
	virtual ~SelectScenarioScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw(HDC hDC, int x, int y) override;
	virtual void Release() override;
};

#endif // !_SELECTSCENARIOSCENE_H_
