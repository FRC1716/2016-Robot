#ifndef RETRACT_H
#define RETRACT_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class retract: public Command {
public:
	retract();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
