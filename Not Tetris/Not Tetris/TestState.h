//
//  TestState.h
//  Not Tetris
//
//  Created by Justin Carr on 2014-03-18.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#ifndef __Not_Tetris__TestState__
#define __Not_Tetris__TestState__
#include "GameState.h"
#include <iostream>
class TestState : public GameState {
public:
    
    void init();
    void cleanUp();
    
    void pause();
    void resume();
    
    
    void handleEvents(GameEngine* game);
    void update(GameEngine* game);
    void draw(GameEngine* game);
    
};
#endif /* defined(__Not_Tetris__TestState__) */
