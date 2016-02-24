#ifndef POS1_H
#define POS1_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Pos1: public Command {
public:
	Pos1();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
