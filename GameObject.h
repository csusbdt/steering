#pragma once

#include "Vec2.h"
#include "TickListener.h"
#include "SDL_opengl.h"

class Sprite;

class GameObject : public TickListener
{
public:
	GameObject();
	~GameObject();
	virtual void init();
	virtual void tick(float dt);
	void setVisible(bool visible);

	// sprite
	void setSprite(Sprite * sprite);
	Sprite * sprite;

	void orientToDirection(const Vec2 & direction);

	float minX;
	float minY;
	float maxX;
	float maxY;
	Vec2 position;
	float orientation;

private:
	bool visible;
};
