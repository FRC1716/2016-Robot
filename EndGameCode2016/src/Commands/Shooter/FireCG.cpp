#include "FireCG.h"
#include "../../Commands/Shooter/fireC.h"
#include "../../Robot.h"
#include "../../Commands/Movement/SmallReverse.h"

FireCG::FireCG()
{
	if (Robot::controlSS->loaded == true && Robot::controlSS->locked == false){
		AddParallel(new fireC);
		AddParallel(new SmallReverse);
	}else if (Robot::controlSS->loaded == false){
		SmartDashboard::PutString("Messages: ", "Not loaded");
	}else if (Robot::controlSS->locked == true){
		SmartDashboard::PutString("Messages: ", "Still locked");
	}
}
