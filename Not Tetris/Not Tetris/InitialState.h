//
//  InitialState.h
//  Not Tetris
//
//  Created by Justin Carr on 2014-03-20.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#ifndef __Not_Tetris__InitialState__
#define __Not_Tetris__InitialState__
#include "GameState.h"
#include <iostream>
class InitialState : public GameState {
public:
    
    void init();
    void cleanUp();
    
    void pause();
    void resume();
    
    void handleEvents(GameEngine* game);
    void update(GameEngine* game);
    void draw(GameEngine* game);
    
};
#endif /* defined(__Not_Tetris__InitialState__) */
