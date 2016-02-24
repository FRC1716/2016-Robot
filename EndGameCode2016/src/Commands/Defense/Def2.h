#ifndef DEF2_H
#define DEF2_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Def2: public Command {
public:
	Def2();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
