#ifndef SLOWTURNLEFT_H
#define SLOWTURNLEFT_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class SlowTurnLeft: public Command {
public:
	SlowTurnLeft();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
