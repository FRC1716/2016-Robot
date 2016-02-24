#ifndef SENSITIVITYFALSE_H
#define SENSITIVITYFALSE_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class sensitivityFalse: public Command {
public:
	sensitivityFalse();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
