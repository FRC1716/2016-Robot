#ifndef DRIVEREVERSE_H
#define DRIVEREVERSE_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class DriveReverse: public Command {
public:
	DriveReverse();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
