#pragma once

#include "SeekBehavior.h"

class Pawn;
class Path;

/**
 * To follow a path, first call start, then call the follow function until
 * satisfied with the position of the pawn, then call stop.
 */
class FollowPathBehavior
{
public:
	FollowPathBehavior() : pawn(0), path(0), currentPathParam(0) { }
	virtual ~FollowPathBehavior() { }
	void setPawn(Pawn * pawn);
	void start(Path * path);
	void stop();
	void follow(float dt);

private:
	SeekBehavior seekBehavior;
	Pawn * pawn;
	Path * path;
	float currentPathParam;
};
