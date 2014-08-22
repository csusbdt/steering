#pragma once

#include "AlignBehavior.h"

class Pawn;
class Vec2;

class LookWhereYoureGoingBehavior
{
public:
	LookWhereYoureGoingBehavior() : pawn(0) { }
	virtual ~LookWhereYoureGoingBehavior() { }
	void setPawn(Pawn * pawn);
	void look(float dt);

private:
	Pawn * pawn;
	AlignBehavior alignBehavior;
};
