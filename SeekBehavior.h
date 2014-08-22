#pragma once

class Pawn;
class Vec2;

class SeekBehavior
{
public:
	SeekBehavior() : pawn(0) { }
	virtual ~SeekBehavior() { }
	void setPawn(Pawn * pawn) { this->pawn = pawn; }
	void seek(float dt, const Vec2 & destination);

private:
	Pawn * pawn;
};
