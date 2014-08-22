// Game.cpp
#include <iostream>
#include "Game.h"
#include "ApplicationWindow.h"
#include "GraphicsSystem2D.h"
#include "GameState.h"
#include <windows.h>

void Game::fatalError(const std::string & message)
{
#ifdef WIN32
	MessageBoxA(NULL, message.c_str(), "ERROR", MB_OK | MB_ICONEXCLAMATION);
#else
	std::cerr << message << std::endl;
	std::cerr << "Press any key to terminate..." << std::endl;
	std::cin.get();
#endif
	exit(1);
}

void Game::init()
{
    ApplicationWindow * applicationWindow = ApplicationWindow::getInstance();
    applicationWindow->init(640, 480, false, "Game Programming");
    applicationWindow->setWindowClosingListener(this);

    GraphicsSystem2D * graphicsSystem = GraphicsSystem2D::getInstance();
    graphicsSystem->init();
}

void Game::run(GameState * gameState)
{
    ApplicationWindow * applicationWindow = ApplicationWindow::getInstance();
    GraphicsSystem2D * graphicsSystem = GraphicsSystem2D::getInstance();

	// Set up time keeping variables.
	unsigned int previousMilliseconds = 0;
	unsigned int currentMilliseconds = applicationWindow->getTicks();
    float dt = 0;

    while (!shuttingDown)
    {
	    previousMilliseconds = currentMilliseconds;
		currentMilliseconds = applicationWindow->getTicks();
		dt = static_cast<float>((currentMilliseconds - previousMilliseconds) / 1000.0);
		if (dt <= 0) continue;
        applicationWindow->processEvents();
		std::set<TickListener *>::iterator it = tickListeners.begin();
		std::set<TickListener *>::iterator end = tickListeners.end();
		for (; it != end; ++it)
		{
			(*it)->tick(dt);
		}
		graphicsSystem->draw();
        gameState->tick(dt);
    }
}
