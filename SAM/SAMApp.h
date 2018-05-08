#ifndef _SAMAPP_H_
#define _SAMAPP_H_

#include "App.h"

class SAMApp : public App
{
public:
	SAMApp(HINSTANCE hInstance);
	virtual ~SAMApp();

	virtual bool Initialize() override;

private:
	virtual void Update() override;
	virtual void Draw() override;
	void Release();
};

#endif // !_SAMAPP_H_
