#ifndef FIREC_H
#define FIREC_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class fireC: public Command {
public:
	fireC();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
};

#endif
