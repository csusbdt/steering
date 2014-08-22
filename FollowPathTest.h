#pragma once

#include <vector>
#include "GameState.h"
#include "Pawn.h"
#include "PlayerNpcController.h"
#include "NpcController.h"
#include "TriangleSprite.h"
#include "GameObject.h"

class Path;

class FollowPathTest : public GameState
{
public:
	FollowPathTest() : path(0) { }
	virtual ~FollowPathTest() { }
	virtual void activate();
	virtual void tick(float dt) { }
	virtual void deactivate();

private:
	void initPawn(Pawn & pawn);
	TriangleSprite followerSprite;
	Pawn follower;
	NpcController followerController;
	std::vector<GameObject *> pathNodes;
	Path * path;
};
