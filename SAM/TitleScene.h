#ifndef _TITLESCENE_H_
#define _TITLESCENE_H_

#include "Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene() {}
	virtual ~TitleScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw(HDC hDC, int x, int y) override;
	virtual void Release() override;
};

#endif // !_TITLESCENE_H_
