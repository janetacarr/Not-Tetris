//
//  main.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-01-17.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include <iostream>
#include "GameEngine.h"

int main(int argc, const char * argv[])
{
    //Declare and initialize game engine
    GameEngine game;
    
    //Initialize SDL, create window and renderer, etc.
    game.init("Not Tetris");
    /*
    while (game.running()) {
        game.handleEvents();
        game.update();
        game.draw();
    }
    */
    game.cleanUp();
    return 0;
}

