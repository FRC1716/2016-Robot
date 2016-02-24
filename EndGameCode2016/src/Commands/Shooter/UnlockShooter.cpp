#include "UnlockShooter.h"

UnlockShooter::UnlockShooter(): Command() {
	Requires(Robot::controlSS.get());
}

void UnlockShooter::Initialize() {
}

void UnlockShooter::Execute() {
	Robot::controlSS->unlockShooter();
}

bool UnlockShooter::IsFinished() {
    return false;
}

void UnlockShooter::End() {
	Robot::controlSS->lockShooter();
}

void UnlockShooter::Interrupted() {
	End();
}
