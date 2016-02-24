#ifndef ORIENTLEFT_H
#define ORIENTLEFT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class OrientLeft: public Command
{
public:
	OrientLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
