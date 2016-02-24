#ifndef UNLOCKSHOOTER_H
#define UNLOCKSHOOTER_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class UnlockShooter: public Command {
public:
	UnlockShooter();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
