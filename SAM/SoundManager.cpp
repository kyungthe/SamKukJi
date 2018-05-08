#include "SoundManager.h"
#include "App.h"
#include <io.h>

IMPLEMENT_SINGLETON(SoundManager)

SoundManager::SoundManager()
{
	mSystem = nullptr;
	ZeroMemory(mChannelArr, sizeof(mChannelArr));
}

SoundManager::~SoundManager()
{
	Release();
}

void SoundManager::Initialize()
{
	FMOD_RESULT res = FMOD_System_Create(&mSystem);

	if (res != FMOD_OK)
	{
		MessageBox(App::mApp->GetMainWnd(), L"FMOD System Create Failed!", L"Error!!", MB_OK);
		return;
	}

	FMOD_System_Init(mSystem, END, FMOD_INIT_NORMAL, nullptr);
	LoadSoundFile();
}

void SoundManager::LoadSoundFile()
{
	std::vector<std::string> soundDir = { "bgm\\", "se\\" };
	_finddata_t _fd;

	for (auto dir : soundDir)
	{
		std::string soundPath = "..\\Sound\\";
		std::string fullPath = soundPath + dir + "*.*";

		long handle = _findfirst(fullPath.c_str(), &_fd);
		int iResult = 0;

		if (handle == 0)
		{
			MessageBox(App::mApp->GetMainWnd(), L"Not found soundfile!!!", L"Error!!", MB_OK);
			return;
		}

		while (iResult != -1)
		{
			FMOD_SOUND* pSound = nullptr;

			fullPath = soundPath + dir + _fd.name;

			FMOD_RESULT res = FMOD_System_CreateSound(mSystem, fullPath.c_str(), FMOD_HARDWARE,	nullptr, &pSound);

			if (res == FMOD_OK)
			{
				mSoundMap.insert(std::make_pair(_fd.name, pSound));
			}

			iResult = _findnext(handle, &_fd);
		}
		_findclose(handle);
	}

	FMOD_System_Update(mSystem);
}

void SoundManager::Update()
{
	FMOD_System_Update(mSystem);
}

void SoundManager::PlaySound(const std::string& soundKey, ChannelID eID, bool isLoop)
{
	auto findSound = mSoundMap.find(soundKey);
	if (findSound == mSoundMap.end())
	{
		std::wstring wstr(soundKey.begin(), soundKey.end());
		MessageBox(App::mApp->GetMainWnd(), L"Not found soundfile!!!", wstr.c_str(), MB_OK);
		return;
	}

	FMOD_System_PlaySound(mSystem, FMOD_CHANNEL_REUSE, findSound->second, FALSE, &mChannelArr[eID]);
	
	FMOD_Channel_SetMode(mChannelArr[eID], FMOD_LOOP_NORMAL & (isLoop << 1));
}

void SoundManager::StopSound(ChannelID eID)
{
	FMOD_Channel_Stop(mChannelArr[eID]);
}

void SoundManager::StopAll()
{
	for (int i = 0; i < END; ++i)
	{
		FMOD_Channel_Stop(mChannelArr[i]);
	}
}

void SoundManager::Release()
{
	for (auto& pair : mSoundMap)
	{
		FMOD_Sound_Release(pair.second);
	}

	mSoundMap.clear();

	FMOD_System_Release(mSystem);
	FMOD_System_Close(mSystem);
}
