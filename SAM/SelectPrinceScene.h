#ifndef _SELECTPRINCESCENE_H_
#define _SELECTPRINCESCENE_H_

#include "Scene.h"

class SelectPrinceScene : public Scene
{
public:
	SelectPrinceScene() {}
	virtual ~SelectPrinceScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw(HDC hDC, int x, int y) override;
	virtual void Release() override;
};

#endif // !_SELECTPRINCESCENE_H_
