#include "PlayerController.h"
#include "GraphicsSystem2D.h"
#include "Pawn.h"

void PlayerController::processMouseMove(unsigned int xScreen, unsigned int yScreen)
{
	GraphicsSystem2D * graphicsSystem = GraphicsSystem2D::getInstance();
    GLfloat x = graphicsSystem->xScreenToWorld(xScreen);
    GLfloat y = graphicsSystem->yScreenToWorld(yScreen);
    pawn->position.x = x;
    pawn->position.y = y;
}