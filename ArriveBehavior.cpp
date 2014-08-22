#include <cassert>
#include <string>
#include "ArriveBehavior.h"
#include "Pawn.h"
#include "Vec2.h"

extern void fatalError(const std::string & message);

/**
  @return true on arrival
*/
bool ArriveBehavior::arrive(float dt, const Vec2 & destination)
{
	assert(pawn->arriveSatisfactionRadius != 0);
	assert(pawn->arriveSlowRadius != 0);
	assert(pawn->arriveTimeToTarget != 0);
	assert(pawn->maxSpeed != 0);

	// Step 1: Check to see if we have arrived.

	Vec2 directionToTarget = destination - pawn->position;
	float distanceToTarget = directionToTarget.length();
	directionToTarget.normalize();

	if (distanceToTarget < pawn->arriveSatisfactionRadius)
	{
		pawn->stopMoving();
		return true;
	}

	// Step 2: Compute desired velocity.

	float desiredSpeed = 0;
	if (distanceToTarget < pawn->arriveSlowRadius)
	{
		desiredSpeed = pawn->maxSpeed * distanceToTarget / pawn->arriveSlowRadius;
	}
	else
	{
		desiredSpeed = pawn->maxSpeed;
	}
	Vec2 desiredVelocity = directionToTarget * desiredSpeed;

	// Step 3: Compute acceleration to arrive at desired velocity in timeToTarget.

	Vec2 desiredChangeInVelocity = desiredVelocity - pawn->velocity; 
	Vec2 acceleration = desiredChangeInVelocity / pawn->arriveTimeToTarget;

	if (acceleration.length() > pawn->maxAcceleration)
	{
		acceleration.normalize();
		acceleration *= pawn->maxAcceleration;
	}
	pawn->applyAcceleration(dt, acceleration);
	return false;
}
