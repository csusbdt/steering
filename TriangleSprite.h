#pragma once

#include "sprite.h"

class TriangleSprite : public Sprite
{
public:
	TriangleSprite() { }
	virtual ~TriangleSprite() { }
	virtual void drawSprite() const;
};
