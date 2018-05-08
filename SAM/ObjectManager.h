#ifndef _OBJECTMANAGER_H_
#define _OBJECTMANAGER_H_

#include "Singleton.h"
#include <Windows.h>
#include <vector>

class Object;
class ObjectManager
{
	DECLARE_SINGLETON(ObjectManager)

public:
	enum ObjectID { OBJ_MAP, OBJ_UI, OBJ_END };

	void AddObject(Object* obj, ObjectID objID);
	void Update();
	void Draw(HDC hDC);
	void Release();

private:
	ObjectManager() {}
	~ObjectManager();

	std::vector<Object*> mObjectList[OBJ_END];
};

#endif // !_OBJECTMANAGER_H_
