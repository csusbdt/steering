#include <cassert>
#include <cmath>
#include "LookWhereYoureGoingBehavior.h"
#include "Vec2.h"
#include "Pawn.h"

void LookWhereYoureGoingBehavior::setPawn(Pawn * pawn) 
{ 
	this->pawn = pawn;
	alignBehavior.setPawn(pawn);
}

void LookWhereYoureGoingBehavior::look(float dt)
{
	assert(pawn != 0);
	assert(pawn->lookWhereGoingSatisfactionAngle != 0);

	if (pawn->velocity.length() <= pawn->lookWhereGoingSatisfactionAngle)
	{
		pawn->stopRotating();
		return;
	}
	float desiredOrientation = std::atan2(-pawn->velocity.x, pawn->velocity.y);
	alignBehavior.align(dt, desiredOrientation);
}
