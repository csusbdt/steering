#include <cassert>
#include "FollowPathTest.h"
#include "GraphicsSystem2D.h"
#include "SquareSprite.h"
#include "Game.h"
#include "Vec2.h"
#include "Path.h"
#include "util.h"

void FollowPathTest::initPawn(Pawn & pawn)
{
	pawn.init();
	pawn.maxSpeed = 100;
	pawn.maxAcceleration = 400;
	pawn.alignSatisfactionAngle = 5 * degrees_to_radians;
	pawn.alignSlowAngle = 10 * degrees_to_radians;
	pawn.alignTimeToTarget = 0.1f;
	pawn.arriveSatisfactionRadius = 10;
	pawn.arriveSlowRadius = 50;
	pawn.arriveTimeToTarget = 0.1f;
	pawn.lookWhereGoingSatisfactionAngle = 5 * degrees_to_radians;
	pawn.followPathOffset = 30;
}

void FollowPathTest::activate()
{
    ApplicationWindow * applicationWindow = ApplicationWindow::getInstance();
	Game * game = Game::getInstance();

	// Initialize chaser.
	initPawn(follower);
	follower.position.x = 225;
	follower.position.y = 225;
	follower.orientation = 100 * degrees_to_radians;
	follower.setSprite(&followerSprite);
	follower.setVisible(true);

	// Initialize chaser controller.
	followerController.setPawn(&follower);
	followerController.state = NpcController::pathFollowing;
	game->addTickListner(&followerController);

	for (int i = 0; i < 8; ++i)
	{
		pathNodes.push_back(new GameObject());
		SquareSprite * sprite = new SquareSprite();
		sprite->blue = 0;
		sprite->red = 0;
		sprite->position = &(pathNodes.back()->position);
		sprite->orientation = &(pathNodes.back()->orientation);
		sprite->setVisible(true);
		pathNodes.back()->setSprite(sprite);
	}

	pathNodes[0]->position = Vec2(200, 200);
	pathNodes[1]->position = Vec2(180, 150);
	pathNodes[2]->position = Vec2(120, 175);
	pathNodes[3]->position = Vec2(75, -50);
	pathNodes[4]->position = Vec2(-40, 0);
	pathNodes[5]->position = Vec2(-125, -145);
	pathNodes[6]->position = Vec2(-260, -15);
	pathNodes[7]->position = Vec2(-170, 150);

	// Create path.
	path = new Path(pathNodes[0]->position, pathNodes[1]->position);
	path->createNextPathSegment(pathNodes[2]->position);
	path->createNextPathSegment(pathNodes[3]->position);
	path->createNextPathSegment(pathNodes[4]->position);
	path->createNextPathSegment(pathNodes[5]->position);
	path->createNextPathSegment(pathNodes[6]->position);
	path->createNextPathSegment(pathNodes[7]->position);

	followerController.followPathBehavior.start(path);
}

void FollowPathTest::deactivate()
{
    ApplicationWindow * applicationWindow = ApplicationWindow::getInstance();
    GraphicsSystem2D * graphicsSystem = GraphicsSystem2D::getInstance();
	Game * game = Game::getInstance();

	graphicsSystem->removeAllDrawables();
	game->removeAllTickListeners();
	applicationWindow->setLeftClickListener(0);

	for (unsigned int i = 0; i < pathNodes.size(); ++i)
	{
		delete pathNodes[i]->sprite;
		delete pathNodes[i];
	}

	followerController.followPathBehavior.stop();
	delete path;
}
