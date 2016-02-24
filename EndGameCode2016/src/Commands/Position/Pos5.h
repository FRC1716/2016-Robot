#ifndef POS5_H
#define POS5_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Pos5: public Command {
public:
	Pos5();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
