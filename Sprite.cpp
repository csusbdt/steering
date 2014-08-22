#include "Sprite.h"
#include "util.h"
#include "SDL_opengl.h"
#include "Vec2.h"
#include "GraphicsSystem2D.h"

Sprite::Sprite() : 
	red(1), 
	green(1), 
	blue(1), 
	alpha(1)
{
}

void Sprite::draw() const
{
	glPushMatrix();
	glTranslatef(position->x, position->y, 0);
	glRotatef(*orientation * radians_to_degrees, 0, 0, 1);
	drawSprite();
	glPopMatrix();
}

void Sprite::setVisible(bool visible)
{
    GraphicsSystem2D * graphicsSystem = GraphicsSystem2D::getInstance();
	if (visible)
	{
		graphicsSystem->addDrawable(this);
	}
	else
	{
		graphicsSystem->removeDrawable(this);
	}
}
