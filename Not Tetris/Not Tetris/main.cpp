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
    
    //Main game loop.
    while (game.running()) {
        //Control the frequency at which the game is updated.
        game.handleEvents();
        game.update();
        
        //Render as fast as possible on the hardware.
        game.draw();
    }
    
    game.cleanUp();
    return 0;
}

