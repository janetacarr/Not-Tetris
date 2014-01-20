//
//  GameState.h
//  Not Tetris
//
//  Created by Justin Carr on 2014-01-19.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#ifndef Not_Tetris_GameState_h
#define Not_Tetris_GameState_h
#include "SDL2/SDL.h"

class GameState{
public:
    virtual void init() = 0;
    virtual void cleanUp() = 0;
    
    virtual void pause() = 0;
    virtual void resume() = 0;
    
    virtual void handleEvent(SDL_Event* e) = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    
    virtual bool changeState();
protected:
    GameState() {}
};

#endif