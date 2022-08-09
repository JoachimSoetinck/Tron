#include "MiniginPCH.h"
#include "SoundSystem.h"

null_SoundSystem ServiceLocator::_default_ss{};
SoundSystem* ServiceLocator::_ss_instance = &_default_ss;