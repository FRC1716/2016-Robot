#ifndef DRIVEREVERSESLOW_H
#define DRIVEREVERSESLOW_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class DriveReverseSlow: public Command {
public:
	DriveReverseSlow();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
