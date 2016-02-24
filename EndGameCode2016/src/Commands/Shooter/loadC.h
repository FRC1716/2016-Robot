#ifndef LOADC_H
#define LOADC_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class loadC: public Command {
public:
	loadC();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
