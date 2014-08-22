#pragma once

#include "Controller.h"
#include "ApplicationWindow.h"

class PlayerController : public Controller, public MouseMoveListener
{
public:
	PlayerController() { }
	virtual ~PlayerController() { }
	void processMouseMove(unsigned int xScreen, unsigned int yScreen);
};
