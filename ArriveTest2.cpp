#include "ArriveTest2.h"
#include "GraphicsSystem2D.h"
#include "Game.h"

void ArriveTest2::initPawn(Pawn & pawn)
{
	pawn.init();
	pawn.alignSatisfactionAngle = 5 * degrees_to_radians;
	pawn.alignSlowAngle = 10 * degrees_to_radians;
	pawn.alignTimeToTarget = 0.1f;
	pawn.arriveSatisfactionRadius = 10;
	pawn.arriveSlowRadius = 50;
	pawn.arriveTimeToTarget = 0.1f;
	pawn.lookWhereGoingSatisfactionAngle = 5 * degrees_to_radians;
}

void ArriveTest2::activate()
{
    ApplicationWindow * applicationWindow = ApplicationWindow::getInstance();
	Game * game = Game::getInstance();

	applicationWindow->setMouseVisible(true);

	// Initialize chaser.
	initPawn(chaser);
	chaser.position.x = 100;
	chaser.position.y = 100;
	chaser.setSprite(&chaserSprite);
	chaser.setVisible(true);
	chaser.target = &player;

	// Initialize chaser controller.
	chaserController.setPawn(&chaser);
	chaserController.state = NpcController::arriving;
	game->addTickListner(&chaserController);

	// Initialize player.
	initPawn(player);
	playerSprite.green = 0;
	playerSprite.blue = 0;
	player.setSprite(&playerSprite);
	player.setVisible(true);
	player.maxSpeed *= 1.3f;

	// Initialze player controller.
	playerController.setPawn(&player);
	applicationWindow->setLeftClickListener(&playerController);
	game->addTickListner(&playerController);
}

void ArriveTest2::deactivate()
{
    ApplicationWindow * applicationWindow = ApplicationWindow::getInstance();
    GraphicsSystem2D * graphicsSystem = GraphicsSystem2D::getInstance();
	Game * game = Game::getInstance();

	graphicsSystem->removeAllDrawables();
	game->removeAllTickListeners();
	applicationWindow->setLeftClickListener(0);
}

