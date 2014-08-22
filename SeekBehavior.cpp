#include "SeekBehavior.h"
#include "Pawn.h"
#include "Vec2.h"

void SeekBehavior::seek(float dt, const Vec2 & destination)
{
	Vec2 directionToTarget = destination - pawn->position;
	directionToTarget.normalize();
	Vec2 acceleration = directionToTarget * pawn->maxAcceleration;
	pawn->applyAcceleration(dt, acceleration);
}
