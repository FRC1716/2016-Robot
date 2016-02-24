#include "After2CG.h"
#include "../Shooter/fireC.h"
#include "../Shooter/FireCG.h"

After2CG::After2CG()
{
	//ATTEMPT SHOT

	//ADD CODE TO MOVE ROBOT INTO POSITION
	//command to fire
	AddSequential(new FireCG);
}
