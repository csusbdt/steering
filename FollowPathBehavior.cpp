#include <cassert>
#include "Path.h"
#include "FollowPathBehavior.h"
#include "Pawn.h"

void FollowPathBehavior::setPawn(Pawn * pawn)
{
	this->pawn = pawn;
	seekBehavior.setPawn(pawn);
}

void FollowPathBehavior::start(Path * path)
{
	this->path = path;
	currentPathParam = 0;
}

void FollowPathBehavior::stop() 
{ 
	path = 0; 
	currentPathParam = 0;
}

void FollowPathBehavior::follow(float dt)
{
	assert(pawn != 0);
	assert(path != 0);
	assert(pawn->followPathOffset != 0);
	assert(currentPathParam >= 0);
	float newPathParam = path->computeParam(currentPathParam, pawn->position);
	assert(newPathParam >= currentPathParam);
	currentPathParam = newPathParam;
	Vec2 destination = path->computePosition(currentPathParam + pawn->followPathOffset);
	seekBehavior.seek(dt, destination);
}
