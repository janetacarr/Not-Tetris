//
//  GameEngine.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-01-19.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "GameEngine.h"
#include "GameState.h"

void GameEngine::init(std::string title, int winWidth, int winHeight) {
    mRunning = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw std::runtime_error("SDL init failed");
    }
    if (IMG_Init(IMG_INIT_PNG) == -1) {
        throw std::runtime_error("SDL_image init failed");
    }
    if (TTF_Init() == -1) {
        throw std::runtime_error("SDL_ttf init failed");
    }
    
    mBox.x = 0;
    mBox.y = 0;
    mBox.w = winWidth;
    mBox.h = winHeight;
    
    //Create window and renderer, along with making sure it happened.
    mWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mBox.w, mBox.h, SDL_WINDOW_SHOWN);
    if (mWindow == nullptr) {
        throw std::runtime_error("Failed to create SDL_Window!");
    }
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRenderer == nullptr) {
        throw std::runtime_error("Failed to create SDL_Renderer!");
    }
    
}

/**************************************************************************************
                     Never mind, this method is necessary now.
 **************************************************************************************/
void GameEngine::changeState(GameState* state) {
    if (!states.empty()) {
        states.back()->cleanUp();
        states.pop_back();
    }
    
    states.push_back(std::unique_ptr<GameState>{state});
    states.back()->init();
}

//Wrap the state
void GameEngine::pushState(GameState* state) {
    //pause the current state
    if ( !states.empty()) {
        states.back()->pause();
    }
    // push and initialize new state.
    states.push_back(std::unique_ptr<GameState>{state});
    states.back()->init();
}

//Pop the current state
void GameEngine::popState() {
    if (!states.empty()) {
        states.back()->cleanUp();
        states.pop_back();
    }
}

//Call the handle events from the state
void GameEngine::handleEvents() {
    states.back()->handleEvents(this);
}

//Call the states update
void GameEngine::update() {
    states.back()->update(this);
}

//Update the display, probably just call the current state's draw.
void GameEngine::draw() {
    states.back()->draw(this);
}

SDL_Window& GameEngine::getWindow() {
    return *mWindow;
}

SDL_Renderer& GameEngine::getRenderer() {
    return *mRenderer;
}



//Collect various garbage.
void GameEngine::cleanUp() {
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    mRenderer = NULL;
    mWindow = NULL;
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}