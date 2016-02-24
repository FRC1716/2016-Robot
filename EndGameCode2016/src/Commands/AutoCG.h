#ifndef AutoCG_H
#define AutoCG_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoCG: public CommandGroup
{
public:
	AutoCG();
	CommandGroup* def;
	CommandGroup* before;
	CommandGroup* after;

	int pos;
};

#endif
