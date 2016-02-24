#ifndef RELEASEC_H
#define RELEASEC_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class releaseC: public Command {
public:
	releaseC();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
