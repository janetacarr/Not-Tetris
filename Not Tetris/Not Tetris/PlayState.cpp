//
//  PlayState.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-03-31.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "PlayState.h"

void PlayState::init() {return;}
void PlayState::cleanUp() {return;}

void PlayState::pause() {return;}
void PlayState::resume() {return;}

void PlayState::handleEvents(GameEngine* game) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            game->quit();
        }
        if (e.key.keysym.sym == SDLK_ESCAPE) {
            game->quit();
        }
    }
}

void PlayState::update(GameEngine* game) {
    SDL_RenderClear(&(game->getRenderer()));
}

void PlayState::draw(GameEngine* game) {
    SDL_RenderPresent(&(game->getRenderer()));
}