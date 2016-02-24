#ifndef DEF8_H
#define DEF8_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Def8: public Command {
public:
	Def8();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
