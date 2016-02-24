#ifndef After3CG_H
#define After3CG_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class After3CG: public CommandGroup
{
public:
	After3CG();

	CommandGroup* def;
};

#endif
