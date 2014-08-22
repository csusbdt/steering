#pragma once

#include "Drawable.h"

class Vec2;

class Sprite : public Drawable
{
public:
	Sprite();
	virtual ~Sprite() { }
	virtual void draw() const;
	virtual void drawSprite() const =0;
	void setVisible(bool visible);

	float red;
	float green;
	float blue;
	float alpha;

	Vec2 * position;
	float * orientation;
};
