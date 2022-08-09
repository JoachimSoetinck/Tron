#include "MiniginPCH.h"
#include "SDL_SoundSystem.h"


#include "sdl_SoundSystem.h"
#include <map>
#include <mutex>
#include <thread>

#include "SDL_mixer.h"

struct Sound
{
	Sound_Id id;
	float volume  = 5;
};

class dae::SDL_SoundSystem::sdl_SoundSystemImpl
{
public:
	sdl_SoundSystemImpl()
		: m_Head{ 0 }
		, m_Tail{ 0 }
	{
		int result = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, MIX_CHANNELS);
		if (result < 0)
			std::cout << "Failed To Load Sound\n";

		//Opening Thread
		m_Thread = std::jthread([&, this] {while (m_KeepThreadOpen) { Update(); }});
	}

	~sdl_SoundSystemImpl()
	{
		m_KeepThreadOpen = false;

		Mix_CloseAudio();
	}

	void RegisterSound(const Sound_Id id, const std::string& file)
	{
		Mix_Chunk* sound;
		const std::string path = m_path + file;

		//loading Sound
		sound = Mix_LoadWAV(path.c_str());


		//checking if sound is made
		if (!sound)
		{
			std::cout << "Failed To Register Sound\n";
			throw;
		}

		//Adding Sound to list
		 m_pSounds.insert(std::pair<Sound_Id, Mix_Chunk*>{id, sound});

		
	};


	void Play(const Sound_Id id, const float volume)
	{

		m_Mutex.lock();
		m_SoundQueue[m_Tail].id = id;
		m_SoundQueue[m_Tail].volume = volume;
		m_Tail = (m_Tail + 1) % m_MaxPending;
		m_Mutex.unlock();
	}


	void Update()
	{
		if (m_Head == m_Tail)
			return;

		Mix_Chunk* sound;
		sound = m_pSounds[m_SoundQueue[m_Head].id];

	
		sound->volume = static_cast<Uint8>(m_SoundQueue[m_Head].volume);

		if (Mix_PlayChannel(-1, sound, 0) == -1)
			std::cout << "sdl_SoundSystem::Play\n" << SDL_GetError() << "\n";

		m_Head = (m_Head + 1) % m_MaxPending;
	}

private:
	//Sound names cant be the same -> map
	std::map<Sound_Id, Mix_Chunk*> m_pSounds{};
	std::string m_path = "../Data/Sound/";


	static const unsigned int m_MaxPending = 16;
	Sound m_SoundQueue[m_MaxPending]{};
	std::jthread m_Thread;
	std::mutex m_Mutex;

	 int m_Head;
	 int m_Tail;

	bool m_KeepThreadOpen = true;
};

dae::SDL_SoundSystem::SDL_SoundSystem():
m_pImpl{ new sdl_SoundSystemImpl()}
{

}

dae::SDL_SoundSystem::~SDL_SoundSystem()
{
	delete m_pImpl;
}

void dae::SDL_SoundSystem::Play(const Sound_Id id, const float volume)
{
	m_pImpl->Play(id, volume);
}

void dae::SDL_SoundSystem::RegisterSound(const Sound_Id id, const std::string& file)
{
	m_pImpl->RegisterSound(id, file);
}