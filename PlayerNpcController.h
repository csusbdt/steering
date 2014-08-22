#pragma once

#include "ApplicationWindow.h"
#include "NpcController.h"
#include "GameObject.h"
#include "SquareSprite.h"

class PlayerNpcController : public NpcController, public LeftClickListener
{
public:
	PlayerNpcController() { }
	virtual ~PlayerNpcController() { }
	void processLeftClick(unsigned int xScreen, unsigned int yScreen);
	virtual void setPawn(Pawn * pawn);

private:
	GameObject dummyTarget;
	SquareSprite destinationSprite;
};
