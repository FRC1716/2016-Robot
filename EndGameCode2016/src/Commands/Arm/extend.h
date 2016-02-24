#ifndef EXTEND_H
#define EXTEND_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class extend: public Command {
public:
	extend();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
