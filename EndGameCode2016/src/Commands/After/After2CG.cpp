#include "After2CG.h"
#include "../../Commands/Shooter/fireC.h"
#include "../../Commands/Shooter/FireCG.h"

After2CG::After2CG()
{
	//ATTEMPT SHOT

	//ADD CODE TO MOVE ROBOT INTO POSITION
	//command to fire
	AddSequential(new FireCG);
}
