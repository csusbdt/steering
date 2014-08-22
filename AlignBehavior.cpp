#include <cassert>
#include <string>
#include <cmath>
#include "AlignBehavior.h"
#include "Pawn.h"
#include "util.h"

void AlignBehavior::align(float dt, float desiredOrientation)
{
	assert(pawn->alignSatisfactionAngle != 0);
	assert(pawn->alignSlowAngle != 0);
	assert(pawn->alignTimeToTarget != 0);
	assert(pawn->maxAngularSpeed != 0);
	assert(desiredOrientation >= -pi && desiredOrientation <= pi);
	assert(pawn->orientation >= -pi && pawn->orientation <= pi);

	// Step 1: Determine the shortest angle to rotate to get to desired orientation.

	float angleToRotate = desiredOrientation - pawn->orientation;
	if (angleToRotate > pi) angleToRotate -= two_pi;
	if (angleToRotate <= -pi) angleToRotate += two_pi;

	if (fabs(angleToRotate) < pawn->alignSatisfactionAngle)
	{
		pawn->stopRotating();
		return;
	}

	// Step 2: Compute the desired angular speed.

	float desiredAngularSpeed;
	if (fabs(angleToRotate) < pawn->alignSlowAngle)
	{
		desiredAngularSpeed = pawn->maxAngularSpeed * angleToRotate / pawn->alignSlowAngle;
	}
	else if (angleToRotate < 0)
	{
		desiredAngularSpeed = -pawn->maxAngularSpeed;
	}
	else
	{
		desiredAngularSpeed = pawn->maxAngularSpeed;
	}

	// Step 3: Compute angular acceleration to arrive at desired angular speed in timeToTarget.

	float desiredChangeInAngularSpeed = desiredAngularSpeed - pawn->angularSpeed;
	float angularAcceleration = desiredChangeInAngularSpeed / pawn->alignTimeToTarget;

	if (angularAcceleration > pawn->maxAngularAcceleration)
	{
		angularAcceleration = pawn->maxAngularAcceleration;
	}
	else if (angularAcceleration < -pawn->maxAngularAcceleration)
	{
		angularAcceleration = -pawn->maxAngularAcceleration;
	}

	pawn->applyAngularAcceleration(dt, angularAcceleration);
}

