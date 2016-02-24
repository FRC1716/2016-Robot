#ifndef DRIVEC_H
#define DRIVEC_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class DriveC: public Command {
public:
	DriveC();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
