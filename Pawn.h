#pragma once

#include "GameObject.h"
#include "FollowPathBehavior.h"

/**
 * A pawn is a game object that is controlled by a controller.
 */
class Pawn : public GameObject
{
public:
	Pawn();
	virtual ~Pawn() { }

	void stopMoving() { velocity.x = 0; velocity.y = 0; }
	void stopRotating() { angularSpeed = 0; }
	void applyAcceleration(float dt, const Vec2 & acceleration);
	void applyAngularAcceleration(float dt, float angularAcceleration);

	// linear components of motion
	float maxSpeed;
	float maxAcceleration;
	Vec2 velocity;

	// angular components of motion
    float angularSpeed;
    float maxAngularSpeed;
    float maxAngularAcceleration;

	// steering behavior data -- this will be moved into steering behaviors
	GameObject * target;

	// steering behavior parameters
	float alignSatisfactionAngle;
	float alignSlowAngle;
	float alignTimeToTarget;
	float arriveSatisfactionRadius;
	float arriveSlowRadius;
	float arriveTimeToTarget;
	float lookWhereGoingSatisfactionAngle;
	float followPathOffset;
};
