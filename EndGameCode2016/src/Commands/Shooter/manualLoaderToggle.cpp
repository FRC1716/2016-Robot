#include "manualLoaderToggle.h"

manualLoaderToggle::manualLoaderToggle(): Command() {
	Requires(Robot::controlSS.get());
}

void manualLoaderToggle::Initialize() {
}

void manualLoaderToggle::Execute() {
	Robot::controlSS->toggle(1);
}

bool manualLoaderToggle::IsFinished() {
    return false;
}

void manualLoaderToggle::End() {
}

void manualLoaderToggle::Interrupted() {
}
