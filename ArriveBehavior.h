#pragma once

class Pawn;
class Vec2;

class ArriveBehavior
{
public:
	ArriveBehavior() : pawn(0) { }
	virtual ~ArriveBehavior() { }
	void setPawn(Pawn * pawn) { this->pawn = pawn; }
	bool arrive(float dt, const Vec2 & destination); 

private:
	Pawn * pawn;
};
