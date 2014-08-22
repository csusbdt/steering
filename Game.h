#pragma once

#include <set>
#include "ApplicationWindow.h"
#include "TickListener.h"

class GameState;

class Game : public WindowClosingListener
{
public:
    static Game * getInstance() { static Game instance; return &instance; }
    void setShuttingdown(bool shuttingDown) { this->shuttingDown = shuttingDown; }
    void processWindowClosing() { setShuttingdown(true); }
	void addTickListner(TickListener * tickListener) { tickListeners.insert(tickListener); }
	void removeTickListner(TickListener * tickListener) { tickListeners.erase(tickListener); }
	void removeAllTickListeners() { tickListeners.clear(); }
	void init();
    void run(GameState * gameState);
	static void fatalError(const std::string & message);

private:
    Game() : shuttingDown(false) { }
    bool shuttingDown;
	std::set<TickListener *> tickListeners;
};
