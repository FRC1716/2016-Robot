#ifndef SENSITIVITYTRUE_H
#define SENSITIVITYTRUE_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class sensitivityTrue: public Command {
public:
	sensitivityTrue();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
