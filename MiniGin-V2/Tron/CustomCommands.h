#pragma once
#pragma once
#include "Command.h"
#include <memory>

class FireCommand : public Command
{
public:

	virtual void Execute() override { std::cout << "Fire" << std::endl; };
};


