//
//  InitialState.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-03-20.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "InitialState.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"

void InitialState::init() {
    
    return;
}
void InitialState::cleanUp() {
    return;
}
void InitialState::pause() {
    return;
}
void InitialState::resume() {
    return;
}

void InitialState::handleEvents(GameEngine* game) {
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

void InitialState::update(GameEngine* game) {
    SDL_RenderClear(&(game->getRenderer()));
}

void InitialState::draw(GameEngine* game) {
    SDL_RenderPresent(&(game->getRenderer()));
}