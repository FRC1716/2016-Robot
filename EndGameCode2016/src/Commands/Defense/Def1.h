#ifndef DEF1_H
#define DEF1_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Def1: public Command {
public:
	Def1();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
