#ifndef DEF4_H
#define DEF4_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Def4: public Command {
public:
	Def4();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
