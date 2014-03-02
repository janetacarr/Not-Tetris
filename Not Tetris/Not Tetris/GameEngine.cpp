//
//  GameEngine.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-01-19.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "GameEngine.h"

void GameEngine::init(std::string title, int winWidth, int winHeight) {
    mRunning = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw std::runtime_error("SDL init failed");
    }
    if (IMG_Init(IMG_INIT_PNG) == -1) {
        throw std::runtime_error("SDL_image init failed");
    }
    
    mBox.x = 0;
    mBox.y = 0;
    mBox.w = winWidth;
    mBox.h = winHeight;
    
    //Create window and renderer
    mWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mBox.w, mBox.h, SDL_WINDOW_SHOWN);
    if (mWindow == nullptr) {
        throw std::runtime_error("Failed to create SDL_Window!");
    }
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRenderer == nullptr) {
        throw std::runtime_error("Failed to create SDL_Renderer!");
    }
    
}

void GameEngine::changeState(GameState* state) {
    
}

//Wrap the state
void GameEngine::pushState(GameState* state) {
    std::unique_ptr<GameState> theState {state};
    states.push_back(theState);
}

//Pop the current state
void GameEngine::popState() {
    states.pop_back();
}

//Call the handle events from the state
void GameEngine::handleEvents() {
    states.back().get()->handleEvents();
}

//Call the states update
void GameEngine::update() {
    states.back().get()->update();
}

//Update the display, probably just call the current state's draw.
void GameEngine::draw() {
    states.back().get()->draw();
}

void GameEngine::cleanUp() {
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    IMG_Quit();
    SDL_Quit();
}