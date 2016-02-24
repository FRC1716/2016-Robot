#ifndef MANUALLOADERTOGGLE_H
#define MANUALLOADERTOGGLE_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class manualLoaderToggle: public Command {
public:
	manualLoaderToggle();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
