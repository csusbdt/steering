#include "NpcController.h"
#include "Pawn.h"
#include "GameObject.h"
#include <cassert>
#include <iostream>

void NpcController::setPawn(Pawn * pawn)
{
	Controller::setPawn(pawn);
	seekBehavior.setPawn(pawn);
	arriveBehavior.setPawn(pawn);
	lookWhereYoureGoingBehavior.setPawn(pawn);
	followPathBehavior.setPawn(pawn);
}

void NpcController::tick(float dt)
{
	assert(pawn != 0);
	switch (state)
	{
	case idle: 
		tickIdle(dt); 
		break;
	case seeking: 
		tickSeeking(dt); 
		break;
	case arriving: 
		tickArriving(dt); 
		break;
	case pathFollowing: 
		tickPathFollowing(dt); 
		break;
	default: 
		assert(false);
	}
}

void NpcController::tickSeeking(float dt)
{
	assert(pawn->target != 0);
	assert(state == seeking);
	seekBehavior.seek(dt, pawn->target->position);
}

void NpcController::tickArriving(float dt)
{
	assert(pawn->target != 0);
	assert(state == arriving);
	bool arrived = arriveBehavior.arrive(dt, pawn->target->position);
	if (arrived)
	{
		state = idle;
	}
	else
	{
		lookWhereYoureGoingBehavior.look(dt);
	}
}

void NpcController::tickPathFollowing(float dt)
{
	assert(state == pathFollowing);
	followPathBehavior.follow(dt);
	lookWhereYoureGoingBehavior.look(dt);
}

void NpcController::tickIdle(float dt)
{
	if (pawn->target != 0)
	{
		float distanceToTarget = (pawn->position - pawn->target->position).length();
		if (distanceToTarget > pawn->arriveSatisfactionRadius)
		{
			state = arriving;
		}
	}
}
