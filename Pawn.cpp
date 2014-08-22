#include <cassert>
#include "util.h"
#include "Pawn.h"

Pawn::Pawn() : 
	target(0),
	maxSpeed(100),
	maxAcceleration(400),
	angularSpeed(0), 
	maxAngularSpeed(600 * degrees_to_radians),
	maxAngularAcceleration(720 * degrees_to_radians),
	alignSatisfactionAngle(0),
	alignSlowAngle(0),
	alignTimeToTarget(0),
	arriveSatisfactionRadius(0),
	arriveSlowRadius(0),
	arriveTimeToTarget(0),
	lookWhereGoingSatisfactionAngle(0),
	followPathOffset(0)
{
}

	
// This function should be protected (or private).
void Pawn::applyAcceleration(float dt, const Vec2 & acceleration)
{ 
	assert(minX != 0 && maxX != 0);
	assert(minY != 0 && maxY != 0);

	// Limit speed to maximum.
	if (velocity.length() > maxSpeed)
	{
		velocity.normalize();
		velocity *= maxSpeed;
	}

	// Apply acceleration.
	velocity += acceleration * dt;

	// Apply velocity.
	position += velocity * dt;

	// Limit position to visible screen.
	if (position.x < minX) position.x = minX;
	if (position.x > maxX) position.x = maxX;
	if (position.y < minY) position.y = minY;
	if (position.y > maxY) position.y = maxY;
}

void Pawn::applyAngularAcceleration(float dt, float angularAcceleration)
{ 
	if (angularSpeed > maxAngularSpeed)
	{
		angularSpeed = maxAngularSpeed;
	}
	else if (angularSpeed < -maxAngularSpeed)
	{
		angularSpeed = -maxAngularSpeed;
	}

	angularSpeed += angularAcceleration * dt;
	orientation += angularSpeed * dt;
	while (orientation > pi)
	{
		orientation -= two_pi;
	}
	while (orientation <= -pi)
	{
		orientation += two_pi;
	}
}
