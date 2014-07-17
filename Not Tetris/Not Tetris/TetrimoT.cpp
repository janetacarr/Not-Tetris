//
//  TetrimoT.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-04-05.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "TetrimoT.h"


void TetrimoT::init() {
    std::cout << "init" << std::endl;
    time = 0.0f;
    current.x = 20.0f;
    current.v = 0;
    previous = current;
    TextDim.x = 160;
    TextDim.y = 20;
    TextDim.w = 60;
    TextDim.h = 40;
    TextPlace.x = 20;
    TextPlace.y = 20;
    TextPlace.w = 60;
    TextPlace.h = 40;
}
void TetrimoT::buildSprite(GameEngine* game) {
    std::cout << "building sprite" << std::endl;
    tex = IMG_LoadTexture(&(game->getRenderer()), this->getTexturePath().c_str());
    time = SDL_GetTicks() / 1000;
    std::cout << "Time: " << time << std::endl;
}

bool TetrimoT::firstRun() {
    if (firstRunVar) {
        firstRunVar = false;
        return true;
    } else {
        return false;
    }
}

void TetrimoT::update(float t, float dt, float accumulator) {
    previous = current;
    integrate(current, t, dt);
    
    //Interpolate here.
    //State state = interpolate(previous, current, accumulator);
    //TextDim.y = state.x;
    //std::cout << "Position: " << state.x  << std::endl << "Velocity: " << state.v << std::endl;
}
void TetrimoT::interpolateStates(float t, float dt, float accumulator) {
    State state = interpolate(previous, current, accumulator/dt);
    TextDim.y = state.x;
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
    return TextDim.x;
}

int TetrimoT::getYPosition() {
    return TextDim.y;
}

void TetrimoT::setXVelocity(int deltaX) {
    xVel += deltaX;
    return;
}

void TetrimoT::setYVelocity(int deltaY) {
    yVel +=deltaY;
    return;
}
