#pragma once

#include "Controller.h"
#include "SeekBehavior.h"
#include "ArriveBehavior.h"
#include "LookWhereYoureGoingBehavior.h"
#include "FollowPathBehavior.h"

class NpcController : public Controller
{
public:	
	enum State
	{
		idle, seeking, arriving, pathFollowing
	};

	NpcController() : state(idle) { }
	virtual ~NpcController() { }
	virtual void setPawn(Pawn * pawn);
	virtual void tick(float dt);

	State state;

	SeekBehavior seekBehavior;
	ArriveBehavior arriveBehavior;
	LookWhereYoureGoingBehavior lookWhereYoureGoingBehavior;
	FollowPathBehavior followPathBehavior;

private:
	void tickIdle(float dt);
	void tickSeeking(float dt);
	void tickArriving(float dt);
	void tickPathFollowing(float dt);
};
