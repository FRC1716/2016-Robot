#include "After2CG.h"
#include "../Commands/fireC.h"

After2CG::After2CG()
{
	//ATTEMPT SHOT
	//command to fire
	AddSequential(new fireC);
}
