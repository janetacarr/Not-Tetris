//
//  PlayState.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-03-31.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "PlayState.h"
#include "TestState.h"

void PlayState::init() {
    firstRun = true;
    stupidSwitch = true;
    mT = nullptr; //new TetrimoT(); //<- is temporary
        return;
}

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
        //Test controls. Toys really.
        if (e.key.keysym.sym == SDLK_SPACE) {
            //SDL is polling two events when there is actually only one, here is a work around that seems to work.
            if (stupidSwitch) {
                tetrimoStack.push_back(std::move(mT)); //Standard library move function to force move constructor.
                std::cout << "Pushed onto the stack" << std::endl;
                mT = std::unique_ptr<Tetrimo>{new TetrimoI(game)};
                stupidSwitch = false;
            } else {
                stupidSwitch = true;
            }
        }
        if (e.key.keysym.sym == SDLK_UP) {
            mT = std::move(tetrimoStack.back());
            tetrimoStack.pop_back();
        }
        if (e.key.keysym.sym == SDLK_RIGHT) {
            if (stupidSwitch) {
                mT->setXVelocity(20);
                stupidSwitch = false;
            } else {
                stupidSwitch = true;
            }
        }
        if (e.key.keysym.sym == SDLK_LEFT) {
            if (stupidSwitch) {
                mT->setXVelocity(-20);
                stupidSwitch = false;
            } else {
                stupidSwitch = true;
            }
        }
    }
}

void PlayState::update(GameEngine* game) {
    
    if (firstRun) {
        mT = std::unique_ptr<Tetrimo>{new TetrimoT(game)};
        firstRun = false;
    }
    mT->update(game->getTimer().getTime(), game->getTimer().getTimeStep(), game->getTimer().getAccumulator());
    
}

void PlayState::draw(GameEngine* game) {
    
    SDL_RenderClear(&(game->getRenderer()));
    mT->draw(game);
    
    for (auto& x: tetrimoStack ) {
        x->draw(game);
    }
    
    SDL_RenderPresent(&(game->getRenderer()));
}