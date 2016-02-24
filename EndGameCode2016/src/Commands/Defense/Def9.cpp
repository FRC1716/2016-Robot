#include "Def9.h"

Def9::Def9(): Command() {
	Requires(Robot::controlSS.get());
}

void Def9::Initialize() {
}

void Def9::Execute() {
}

bool Def9::IsFinished() {
    return false;
}

void Def9::End() {
}

void Def9::Interrupted() {
}
