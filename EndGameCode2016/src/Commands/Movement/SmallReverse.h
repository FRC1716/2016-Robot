#ifndef SMALLREVERSE_H
#define SMALLREVERSE_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class SmallReverse: public Command {
public:
	SmallReverse();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
