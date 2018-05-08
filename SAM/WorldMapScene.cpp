#include "WorldMapScene.h"
#include "BmpManager.h"
#include "App.h"
#include "Key.h"
#include "ObjectManager.h"

WorldMapScene::~WorldMapScene()
{
	Release();
}

void WorldMapScene::Initialize()
{
	std::wstring mapPath = L"..\\Image\\WorldMap\\";
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			std::wstring mapName = L"bigmap";
			mapName += std::to_wstring(i);
			mapName += std::to_wstring(j);
			std::wstring fullPath = mapPath + mapName + L".bmp";

			Bmp* map = new Bmp;
			map->LoadBmp(fullPath.c_str());
			BmpManager::GetInstance()->GetBmpMap().insert(std::make_pair(
				std::string(mapName.begin(), mapName.end()), map));
		}
	}

	mClient.left = 0;
	mClient.top = 0;
	mClient.right = App::mApp->GetWidth();
	mClient.bottom = App::mApp->GetHeight();

	Key* key = new Key(VK_RIGHT, Key::PRESSING, [this] {
		if (mScrollX < mClient.right * 3 - 1)
		{
			mScrollX += 1;
		}
		return 0;
	});
	ObjectManager::GetInstance()->AddObject(key, ObjectManager::OBJ_UI);

	key = new Key(VK_LEFT, Key::PRESSING, [this] {
		if (mScrollX > mClient.left)
		{
			mScrollX -= 1;
		}
		return 0;
	});
	ObjectManager::GetInstance()->AddObject(key, ObjectManager::OBJ_UI);

	key = new Key(VK_UP, Key::PRESSING, [this] {
		if (mScrollY > mClient.top)
		{
			mScrollY -= 1;
		}
		return 0;
	});
	ObjectManager::GetInstance()->AddObject(key, ObjectManager::OBJ_UI);

	key = new Key(VK_DOWN, Key::PRESSING, [this] {
		if (mScrollY < mClient.bottom * 4 - 1)
		{
			mScrollY += 1;
		}
		return 0;
	});
	ObjectManager::GetInstance()->AddObject(key, ObjectManager::OBJ_UI);
}

void WorldMapScene::Update()
{
	ObjectManager::GetInstance()->Update();
}

void WorldMapScene::Draw(HDC hDC, int x, int y)
{
	int top = (mClient.top + mScrollY) / mClient.bottom;
	int left = (mClient.left + mScrollX) / mClient.right;
	int bottom = (mClient.bottom + mScrollY) / mClient.bottom;
	int right = (mClient.right + mScrollX) / mClient.right;

	char bmpKey[9] = "bigmap";
	bmpKey[6] = '0' + top;
	bmpKey[7] = '0' + left;
	Bmp* bmp = BmpManager::GetInstance()->GetBmpMap()[bmpKey];
	int srcX = mScrollX - bmp->GetWidth() * left;
	int srcY = mScrollY - bmp->GetHeight() * top;
	BitBlt(hDC, 0, 0, bmp->GetWidth(), bmp->GetHeight(), bmp->GetMemDC(), srcX, srcY, SRCCOPY);

	bmpKey[6] = '0' + top;
	bmpKey[7] = '0' + right;
	int dstX = bmp->GetWidth() - srcX;
	bmp = BmpManager::GetInstance()->GetBmpMap()[bmpKey];
	BitBlt(hDC, dstX, 0, bmp->GetWidth(), bmp->GetHeight(), bmp->GetMemDC(), 0, srcY, SRCCOPY);

	bmpKey[6] = '0' + bottom;
	bmpKey[7] = '0' + left;
	int dstY = bmp->GetHeight() - srcY;
	bmp = BmpManager::GetInstance()->GetBmpMap()[bmpKey];
	BitBlt(hDC, 0, dstY, bmp->GetWidth(), bmp->GetHeight(), bmp->GetMemDC(), srcX, 0, SRCCOPY);

	bmpKey[6] = '0' + bottom;
	bmpKey[7] = '0' + right;
	bmp = BmpManager::GetInstance()->GetBmpMap()[bmpKey];
	BitBlt(hDC, dstX, dstY, bmp->GetWidth(), bmp->GetHeight(), bmp->GetMemDC(), 0, 0, SRCCOPY);
}

void WorldMapScene::Release()
{
}
