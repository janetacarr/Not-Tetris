//
//  TetrimoT.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-04-05.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "TetrimoT.h"
TetrimoT::TetrimoT(GameEngine* game) {
    tex = IMG_LoadTexture(&(game->getRenderer()), TexturePath.c_str());
    std::cout << "init" << std::endl;
    time = 0.0f;
    current.x = 20.0f;
    current.v = 0;
    previous = current;
    TextDim.x = 20;
    TextDim.y = 20;
    TextDim.w = 60;
    TextDim.h = 40;
    TextPlace.x = 160;
    TextPlace.y = 20;
    TextPlace.w = 60;
    TextPlace.h = 40;
}

void TetrimoT::init() {
    return;
}

SDL_Texture* TetrimoT::getTexture() {
    return tex;
}

std::string TetrimoT::getTexturePath() {
    return TexturePath;
}

SDL_Rect TetrimoT::getTextureDimensions() {
    return TextDim;
}

SDL_Rect TetrimoT::getTexturePlace() {
    return TextPlace;
}

std::vector<SDL_Rect> TetrimoT::getAABB(){
    std::vector<SDL_Rect> v;
    return v;
}

int TetrimoT::getXPosition() {
    return TextPlace.x;
}

int TetrimoT::getYPosition() {
    return TextPlace.y;
}

void TetrimoT::setXVelocity(float deltaX) {
    TextPlace.x += (int)deltaX;
    return;
}

void TetrimoT::setYVelocity(float deltaY) {
    TextPlace.y = (int)deltaY;
    //yVel +=deltaY;
    return;
}

//Taking care of business.
void TetrimoT::update(float t, float dt, float accumulator) {
    previous = current;
    integrate(current, t, dt);
    if (current.v > 50) {   //Toy velocity limit
        current.v = 50;
    }
    if (current.x >= 440) { //Toy distance limit.
        current.x = 440;
    }
}

//Drawing phase
void TetrimoT::interpolateStates(float t, float dt, float accumulator) {
    State state = interpolate(previous, current, accumulator/dt);
    std::cout << "interpolated x: " << state.x << std::endl << "interpolated Velocity: " << state.v << std::endl;
    TextPlace.y = state.x; //TextDim.y = state.x; causes scrolling over spritesheet, super cool effect.
}

void TetrimoT::draw(GameEngine* game) {
    this->interpolateStates(game->getTimer().getTime(), game->getTimer().getTimeStep(), game->getTimer().getAccumulator());
    SDL_Rect dstRect = this->getTexturePlace(); //Place on the SDL_Window where the texture should be.
    SDL_Rect srcRect = this->getTextureDimensions(); //Source x, y, w, h of the sprite from the sprite sheet
    SDL_RenderCopy(&(game->getRenderer()), this->getTexture(), &srcRect, &dstRect); 
}

//Tetrimo Mechanics
void TetrimoT::rotateClockWise() {
    return;
}

void TetrimoT::rotateCounterClockWise() {
    return;
}

void TetrimoT::faceUp() {
    return;
}

void TetrimoT::faceDown() {
    return;
}