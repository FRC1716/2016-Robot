#ifndef SLOWTURNRIGHT_H
#define SLOWTURNRIGHT_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class SlowTurnRight: public Command {
public:
	SlowTurnRight();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
