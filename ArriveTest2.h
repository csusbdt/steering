#pragma once

#include "GameState.h"
#include "Pawn.h"
#include "PlayerNpcController.h"
#include "NpcController.h"
#include "TriangleSprite.h"

class ArriveTest2 : public GameState
{
public:
	ArriveTest2() { }
	virtual ~ArriveTest2() { }
	virtual void activate();
	virtual void tick(float dt) { }
	virtual void deactivate();

private:
	void initPawn(Pawn & pawn);
	TriangleSprite chaserSprite;
	TriangleSprite playerSprite;
	Pawn player;
	Pawn chaser;
	PlayerNpcController playerController;
	NpcController chaserController;
};
