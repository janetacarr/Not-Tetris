//
//  GameEngine.h
//  Not Tetris
//
//  Created by Justin Carr on 2014-01-19.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//


#ifndef __Not_Tetris__GameEngine__
#define __Not_Tetris__GameEngine__

#include <iostream>
#include <vector>
#include <memory>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "GameState.h"

class GameEngine{
public:
    void init(std::string);
    void cleanUp();
    
    void changeState(GameState* state);
    void pushState(GameState* state);
    void popState();
    
    void handleEvents();
    void update();
    void draw();
    
    bool running() { return mRunning; }
    void quit() { mRunning = false; }
    
private:
    //the stack of states
    std::vector<std::unique_ptr<GameState>> states;
    
    bool mRunning;
};

#endif /* defined(__Not_Tetris__GameEngine__) */
