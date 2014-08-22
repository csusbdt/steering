#pragma once

#include "GameState.h"
#include "Pawn.h"
#include "PlayerController.h"
#include "NpcController.h"

class ArriveTest : public GameState
{
public:
	ArriveTest() { }
	virtual ~ArriveTest() { }
	virtual void activate();
	virtual void tick(float dt) { }
	virtual void deactivate();

private:
	Pawn player;
	Pawn chaser;
	PlayerController playerController;
	NpcController chaserController;
};
