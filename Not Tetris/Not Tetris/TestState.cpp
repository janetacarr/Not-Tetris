//
//  TestState.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-03-18.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "TestState.h"


void TestState::init() {return;}
void TestState::cleanUp() {return;}

void TestState::pause() {return;}
void TestState::resume() {return;}

void TestState::handleEvents(GameEngine* game) {
    return;
}

void TestState::update(GameEngine* game) {
    SDL_RenderClear(&(game->getRenderer()));
}

void TestState::draw(GameEngine* game) {
    SDL_RenderPresent(&(game->getRenderer()));
}