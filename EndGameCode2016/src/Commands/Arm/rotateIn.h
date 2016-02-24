#ifndef ROTATEIN_H
#define ROTATEIN_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class rotateIn: public Command {
public:
	rotateIn();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
