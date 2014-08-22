#pragma once

#include "TickListener.h"
#include "Vec2.h"

class Pawn;

class Controller : public TickListener
{
public:
	Controller() : pawn(0) { }
	virtual ~Controller() { }

	virtual void setPawn(Pawn * pawn) { this->pawn = pawn; }
	virtual void tick(float dt) { }

protected:
	Pawn * pawn;   // game object controlled by this controller
};
