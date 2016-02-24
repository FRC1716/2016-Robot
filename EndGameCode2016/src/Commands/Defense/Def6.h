#ifndef DEF6_H
#define DEF6_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Def6: public Command {
public:
	Def6();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
