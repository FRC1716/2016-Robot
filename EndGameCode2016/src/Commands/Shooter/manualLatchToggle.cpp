#include "manualLatchToggle.h"

manualLatchToggle::manualLatchToggle(): Command() {
	Requires(Robot::controlSS.get());
}

void manualLatchToggle::Initialize() {
}

void manualLatchToggle::Execute() {
	Robot::controlSS->toggle(2);
}

bool manualLatchToggle::IsFinished() {
    return false;
}

void manualLatchToggle::End() {
}

void manualLatchToggle::Interrupted() {
}
