#include "BmpManager.h"
#include <algorithm>

IMPLEMENT_SINGLETON(BmpManager)

BmpManager::~BmpManager()
{
	Release();
}

void BmpManager::Release()
{
	std::for_each(mBmpMap.begin(), mBmpMap.end(),
		[](auto& pair)
	{
		if (pair.second)
		{
			delete pair.second;
			pair.second = nullptr;
		}
	});
}
