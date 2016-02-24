#ifndef ROTATEOUT_H
#define ROTATEOUT_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class rotateOut: public Command {
public:
	rotateOut();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
