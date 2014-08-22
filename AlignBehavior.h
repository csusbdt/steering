#pragma once

#include "util.h"

class Pawn;
class Vec2;

class AlignBehavior
{
public:
	AlignBehavior() : pawn(0) { }
	virtual ~AlignBehavior() { }
	void setPawn(Pawn * pawn) { this->pawn = pawn; }
	void align(float dt, float desiredOrientation);

private:
	Pawn * pawn;
};
