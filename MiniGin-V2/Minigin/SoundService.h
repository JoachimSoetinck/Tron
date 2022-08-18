#pragma once
class SoundService
{


public:
	struct Sound
	{
		int id;
		float volume;
	};

	virtual ~SoundService() = default;
	virtual void PlaySound(int soundID, float volume) = 0;
	virtual void StopSound(int soundID) = 0;
	virtual void StopAllSounds() = 0;
	
};


