#ifndef POS4_H
#define POS4_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Pos4: public Command {
public:
	Pos4();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
