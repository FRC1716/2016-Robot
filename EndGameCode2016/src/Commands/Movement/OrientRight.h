#ifndef ORIENTRIGHT_H
#define ORIENTRIGHT_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class OrientRight: public Command{
public:
	OrientRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
