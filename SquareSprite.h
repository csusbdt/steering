#pragma once

#include "Sprite.h"

class SquareSprite : public Sprite
{
public:
	SquareSprite() { }
	virtual ~SquareSprite() { }
	virtual void drawSprite() const;
};
