#include <cassert>
#include "PlayerNpcController.h"
#include "Pawn.h"
#include "GraphicsSystem2D.h"

void PlayerNpcController::setPawn(Pawn * pawn)
{
	dummyTarget.position = pawn->position;
	pawn->target = &dummyTarget;
	destinationSprite.orientation = &(pawn->target->orientation);
	destinationSprite.position = &(pawn->target->position);
	NpcController::setPawn(pawn);
}

void PlayerNpcController::processLeftClick(unsigned int xScreen, unsigned int yScreen)
{
	assert(pawn != 0);
	GraphicsSystem2D * graphicsSystem = GraphicsSystem2D::getInstance();
    GLfloat x = graphicsSystem->xScreenToWorld(xScreen);
    GLfloat y = graphicsSystem->yScreenToWorld(yScreen);
	pawn->target->position.x = x;
	pawn->target->position.y = y;
	state = arriving;
	destinationSprite.setVisible(true);
}