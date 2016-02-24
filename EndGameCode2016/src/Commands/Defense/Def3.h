#ifndef DEF3_H
#define DEF3_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Def3: public Command {
public:
	Def3();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
