/*
   CSCI 441 Game Programming
   Start of a Simple 2D Game 
*/

#include <iostream>
//#include "SeekTest.h"
//#include "ArriveTest2.h"
#include "FollowPathTest.h"
#include "Game.h"

int main(int argc, char* args[])
{
	try
	{
		Game * game = Game::getInstance();
		game->init();
		//SeekTest gameState;
		//ArriveTest2 gameState;
		FollowPathTest gameState;
		gameState.activate();
		game->run(&gameState);
		gameState.deactivate();
		return 0;
	}
	catch (const std::string & msg)
	{
		std::cerr << msg << std::endl;
		std::cerr << "Press enter to terminate program." << std::endl;
		std::cin.get();
	}
}
