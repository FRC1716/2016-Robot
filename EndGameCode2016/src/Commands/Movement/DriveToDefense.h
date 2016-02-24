#ifndef DRIVETODEFENSE_H
#define DRIVETODEFENSE_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class DriveToDefense: public Command {
public:
	DriveToDefense();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	float distance;
};



#endif
