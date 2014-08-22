#include <cassert>
#include <cmath>
#include "GraphicsSystem2D.h"
#include "GameObject.h"
#include "SDL_opengl.h"
#include "util.h"
#include "Sprite.h"
#include "Game.h"

void GameObject::orientToDirection(const Vec2 & direction)
{
	// Adjust orientation if input vector significantly different from zero.
	if (direction.x < 1E-4 || direction.y < 1E-4)
	{
		orientation = atan2f(-direction.x, direction.y);
	}
}

GameObject::GameObject() : 
	sprite(0),
	visible(false),
	minX(0),
	minY(0),
	maxX(0),
	maxY(0),
	orientation(0)
{
}

GameObject::~GameObject()
{
}

void GameObject::setSprite(Sprite * sprite)
{
	this->sprite = sprite;
	sprite->position = &position;
	sprite->orientation = &orientation;
}

void GameObject::setVisible(bool visible)
{
	if (sprite != 0)
	{
		sprite->setVisible(visible);
		this->visible = visible;
	}
	else
	{
		Game::fatalError("calling setVisible on GameObject with no sprite");
	}
}

void GameObject::init()
{
    GraphicsSystem2D * graphicsSystem = GraphicsSystem2D::getInstance();
	minX = graphicsSystem->getMinVisibleX();
	minY = graphicsSystem->getMinVisibleY();
	maxX = graphicsSystem->getMaxVisibleX();
	maxY = graphicsSystem->getMaxVisibleY();
}

void GameObject::tick(float dt)
{
}

