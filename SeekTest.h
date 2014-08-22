#pragma once

#include "GameState.h"
#include "Pawn.h"
#include "PlayerController.h"
#include "NpcController.h"

class SeekTest : public GameState
{
public:
	SeekTest() { }
	virtual ~SeekTest() { }
	virtual void activate();
	virtual void tick(float dt) { }
	virtual void deactivate();

private:
	Pawn player;
	Pawn chaser;
	PlayerController playerController;
	NpcController chaserController;
};