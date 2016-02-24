#ifndef MANUALLATCHTOGGLE_H
#define MANUALLATCHTOGGLE_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class manualLatchToggle: public Command {
public:
	manualLatchToggle();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
