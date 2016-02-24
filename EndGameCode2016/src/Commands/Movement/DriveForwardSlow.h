#ifndef DRIVEFORWARDSLOW_H
#define DRIVEFORWARDSLOW_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class DriveForwardSlow: public Command {
public:
	DriveForwardSlow();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
