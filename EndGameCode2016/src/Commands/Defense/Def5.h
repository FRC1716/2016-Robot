#ifndef DEF5_H
#define DEF5_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Def5: public Command {
public:
	Def5();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
