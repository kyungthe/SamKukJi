#ifndef _BMPMANAGER_H_
#define _BMPMANAGER_H_

#include "Singleton.h"
#include "Bmp.h"
#include <string>
#include <unordered_map>

class BmpManager
{
	DECLARE_SINGLETON(BmpManager)

private:
	std::unordered_map<std::string, Bmp*> mBmpMap;

public:
	BmpManager() {}
	~BmpManager();

	decltype(mBmpMap)& GetBmpMap() { return mBmpMap; }
	void Release();
};

#endif // !_BMPMANAGER_H_
