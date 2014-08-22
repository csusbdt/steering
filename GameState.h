// GameState.h
#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "TickListener.h"

class GameState : public TickListener
{
public:
    virtual void activate() =0;
    virtual void tick(float dt) =0;
    virtual void deactivate() =0;
};

#endif
