#ifndef INTAKEDOWN_H
#define INTAKEDOWN_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class intakeDown: public Command {
public:
	intakeDown();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
