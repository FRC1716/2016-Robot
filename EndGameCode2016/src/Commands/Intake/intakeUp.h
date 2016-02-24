#ifndef INTAKEUP_H
#define INTAKEUP_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class intakeUp: public Command {
public:
	intakeUp();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
