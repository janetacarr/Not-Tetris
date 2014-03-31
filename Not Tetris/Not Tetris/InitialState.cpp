//
//  InitialState.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-03-20.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "InitialState.h"
#include "PlayState.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"


void InitialState::init() {
    return;
}
void InitialState::cleanUp() {
    SDL_DestroyTexture(NewGame);
    NewGame = NULL;
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
        if (e.key.keysym.sym == SDLK_RETURN) {
            game->changeState(new PlayState());
        }
    }
}

void InitialState::update(GameEngine* game) {
    SDL_RenderClear(&(game->getRenderer()));
}

void InitialState::draw(GameEngine* game) {
    NewGame = IMG_LoadTexture(&(game->getRenderer()), "/Users/justinacarr/Not-Tetris/Not Tetris/Textures/somIntro.png");
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    
    srcRect.x = 390;
    srcRect.y = 395;
    srcRect.w = 60;
    srcRect.h = 30;
    
    dstRect.x = 240;
    dstRect.y = 210;
    dstRect.w = 60;
    dstRect.h = 30;
    
    SDL_RenderCopy(&(game->getRenderer()), NewGame, &srcRect, &dstRect);
    SDL_RenderPresent(&(game->getRenderer()));
}