#pragma once
#include <iostream>

#include "GameObject.h"




class Command
{
public:
	Command() {  }
	virtual ~Command() = default;
	virtual void Execute() = 0;


};



