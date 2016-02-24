#ifndef DEF7_H
#define DEF7_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Def7: public Command {
public:
	Def7();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
