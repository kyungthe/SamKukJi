#ifndef _SOUNDMANAGER_H_
#define _SOUNDMANAGER_H_

#include "Singleton.h"
#include <unordered_map>
#include <string>
#include <Windows.h>

#include "FMOD\fmod.h"
#include "FMOD\fmod.hpp"

#pragma comment(lib, "FMOD\\fmodex_vc.lib")

class SoundManager
{
	DECLARE_SINGLETON(SoundManager)

public:
	enum ChannelID { BGM, JNGL, EFFECT, END };

private:
	SoundManager();
	~SoundManager();

public:
	void Initialize();
	void LoadSoundFile();
	void Update();
	void PlaySound(const std::string& pSoundKey, ChannelID eID, bool isLoop);
	void StopSound(ChannelID eID);
	void StopAll();
	void Release();

private:
	FMOD_SYSTEM* mSystem;
	FMOD_CHANNEL* mChannelArr[END];
	std::unordered_map<std::string, FMOD_SOUND*> mSoundMap;
};

#endif // !_SOUNDMANAGER_H_
