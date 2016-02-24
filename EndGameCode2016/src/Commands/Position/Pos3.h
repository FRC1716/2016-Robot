#ifndef POS3_H
#define POS3_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Pos3: public Command {
public:
	Pos3();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
