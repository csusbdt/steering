#include "SeekTest.h"
#include "GraphicsSystem2D.h"
#include "Game.h"

extern void fatalError(const std::string & message);

void SeekTest::activate()
{
    ApplicationWindow * applicationWindow = ApplicationWindow::getInstance();
	Game * game = Game::getInstance();

	// Initialize chaser.
	chaser.init();
	chaser.position.x = 100;
	chaser.position.y = 100;
	chaser.setVisible(true);
	chaser.target = &player;

	// Initialize chaser controller.
	chaserController.setPawn(&chaser);
	chaserController.state = NpcController::seeking;
	game->addTickListner(&chaserController);

	// Initialize player.
	player.setVisible(true);

	// Initialze player controller.
	playerController.setPawn(&player);
	applicationWindow->setMouseMoveListener(&playerController);
}

void SeekTest::deactivate()
{
    ApplicationWindow * applicationWindow = ApplicationWindow::getInstance();
	Game * game = Game::getInstance();

	game->removeTickListner(&chaserController);
	applicationWindow->setMouseMoveListener(0);
}

