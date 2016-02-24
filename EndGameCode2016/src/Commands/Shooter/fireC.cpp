#include "fireC.h"

fireC::fireC(): Command() {
	Requires(Robot::controlSS.get());
}

void fireC::Initialize() {
}

void fireC::Execute() {
	Robot::controlSS->runSequence(4);
}

bool fireC::IsFinished() {
    return false;
}

void fireC::End() {
}

void fireC::Interrupted() {
	Robot::controlSS->runSequence(5);
}
