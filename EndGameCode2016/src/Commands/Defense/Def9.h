#ifndef DEF9_H
#define DEF9_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class Def9: public Command {
public:
	Def9();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
