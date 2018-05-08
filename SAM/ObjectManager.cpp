#include "ObjectManager.h"
#include "Object.h"

IMPLEMENT_SINGLETON(ObjectManager)

void ObjectManager::AddObject(Object * obj, ObjectID objID)
{
	mObjectList[objID].push_back(obj);
}

void ObjectManager::Update()
{
	for (int i = 0; i < OBJ_END; i++)
	{
		for (Object* object : mObjectList[i])
		{
			if (object->Update() == CHANGESCENE)
			{
				return;
			}
		}
	}
}

void ObjectManager::Draw(HDC hDC)
{
	for (int i = 0; i < OBJ_END; i++)
	{
		for (Object* object : mObjectList[i])
		{
			object->Draw(hDC);
		}
	}
}

void ObjectManager::Release()
{
	for (int i = 0; i < OBJ_END; i++)
	{
		mObjectList[i].clear();
	}
}

ObjectManager::~ObjectManager()
{
	Release();
}
