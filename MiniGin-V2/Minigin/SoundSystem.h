#pragma once
using Sound_Id = unsigned int;

class SoundSystem
{
public:
	virtual ~SoundSystem() = default;
	virtual void Play(const Sound_Id id, const float volume) = 0;
	virtual void RegisterSound(const Sound_Id id, const std::string& path) = 0;
};

class null_SoundSystem final : public SoundSystem
{
	void Play(const Sound_Id, const float) override {};
	void RegisterSound(const Sound_Id, const std::string&) override {};
};

class ServiceLocator final
{
private:
	static SoundSystem* _ss_instance;
	static null_SoundSystem _default_ss;

public:
	static void DestroySoundSystem() { delete _ss_instance; };
	static SoundSystem& GetSoundSystem() { return *_ss_instance; };
	static void RegisterSoundSystem(SoundSystem* ss)
	{
		if (ss == nullptr)
			_ss_instance = &_default_ss;
		else
			_ss_instance = ss;
	};
};