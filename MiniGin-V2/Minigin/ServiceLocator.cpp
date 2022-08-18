#include "MiniginPCH.h"
#include "ServiceLocator.h"

dae::Null_SoundSystem dae::ServiceLocator::m_pNullSoundSystem{};
std::shared_ptr<dae::BaseSoundSystem> dae::ServiceLocator::m_pSoundSystem{ std::make_shared<Null_SoundSystem>(m_pNullSoundSystem) };


dae::ServiceLocator::~ServiceLocator()
{
	
}

dae::BaseSoundSystem* dae::ServiceLocator::GetSoundSystem()
{
	return m_pSoundSystem.get();
}

void dae::ServiceLocator::RegisterSoundSystem(std::shared_ptr<BaseSoundSystem> soundSystem)
{
    if (soundSystem == nullptr)
    {
        m_pSoundSystem = std::shared_ptr<BaseSoundSystem>(&m_pNullSoundSystem);;
    }
    else
    {
        m_pSoundSystem = std::shared_ptr<BaseSoundSystem>(soundSystem);;
    }
}