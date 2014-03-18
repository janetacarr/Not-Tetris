//
//  main.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-01-17.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include <iostream>
#include "GameEngine.h"
#include "TestState.h"

int main(int argc, const char * argv[])
{
    const int TICKS_PER_SECOND = 25;
    const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
    const int MAX_FRAMESKIP = 5; //may have to be bigger. like 10 or 12.
    TestState* test = new TestState();
    //Declare and initialize game engine
    GameEngine game;
    
    //Initialize SDL, create window and renderer, etc.
    game.init("Not Tetris");
    game.pushState(test);
    int next_game_tick = SDL_GetTicks();
    int loops;
    float interpolation;
    /**/
    while (game.running()) {
        
        //Control the frequency at which the game is updated.
        loops = 0;
        while (SDL_GetTicks() > next_game_tick && loops < MAX_FRAMESKIP) {
            game.handleEvents();
            game.update();
            
            next_game_tick += SKIP_TICKS;
            loops++;
        }
        //Render as fast as possible on the hardware.
        game.draw();
    }
    /**/
    game.cleanUp();
    return 0;
}

