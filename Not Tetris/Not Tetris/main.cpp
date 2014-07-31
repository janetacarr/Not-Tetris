//
//  main.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-01-17.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include <iostream>
#include "GameEngine.h"
#include "InitialState.h"

int main()
{
    InitialState* test = new InitialState();
    //Declare and initialize game engine
    GameEngine game;
    
    //Initialize SDL, create window and renderer, etc.
    game.init("Not Tetris");
    game.pushState(test);
    //game.getTimer().setCurrentTimeToNewTime();
    //Main game loop.
    while (game.running()) {
        
        game.getTimer().createNewTime();
        game.getTimer().findFrameTime();
        
        game.getTimer().accumulateTime();
        
        //game.handleEvents();
        //Control the frequency at which the game is updated.
        while (game.getTimer().getAccumulator() >= game.getTimer().getTimeStep()) {
            //
            game.handleEvents();
            game.getTimer().consumeTime();
            game.update();
            game.getTimer().advanceTime();
        }
        
        //Render as fast as possible on the hardware. current state at top of stack will probably have to interpolate sprite movement.
        game.draw();
    }
    
    game.cleanUp();
    return 0;
}

