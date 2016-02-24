#ifndef POS2_H
#define POS2_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Pos2: public Command {
public:
	Pos2();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
