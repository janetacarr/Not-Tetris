//
//  PlayState.h
//  Not Tetris
//
//  Created by Justin Carr on 2014-03-31.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#ifndef __Not_Tetris__PlayState__
#define __Not_Tetris__PlayState__
#include "GameState.h"
#include "TetrimoT.h"
#include "SDL2_image/SDL_image.h"
#include <iostream>
class PlayState : public GameState {
public:
    
    void init();
    void cleanUp();
    
    void pause();
    void resume();
    
    void handleEvents(GameEngine* game);
    void update(GameEngine* game);
    void draw(GameEngine* game);

    TetrimoT* mT;
};
#endif /* defined(__Not_Tetris__PlayState__) */
