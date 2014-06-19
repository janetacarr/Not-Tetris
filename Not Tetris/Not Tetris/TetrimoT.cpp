//
//  TetrimoT.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-04-05.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "TetrimoT.h"

//TetrimoT::TetrimoT(int xPosition, int yPosition, int xVelocity, int yVelocity) : xPos(xPosition), yPos(yPosition), xVel(xVelocity), yVel(yVelocity) {
    
//}

void TetrimoT::init() {
    xPos = 160;
    yPos = 20;
    xVel = 10;
    yVel = 2;
    TextDim.x = 160;
    TextDim.y = 20;
    TextDim.w = 60;
    TextDim.h = 40;
    TextPlace.x = 20;
    TextPlace.y = 20;
    TextPlace.w = 60;
    TextPlace.h = 40;
    acceleration = 1;
}
void TetrimoT::buildSprite(GameEngine* game) {
    tex = IMG_LoadTexture(&(game->getRenderer()), this->getTexturePath().c_str());
}

bool TetrimoT::firstRun() {
    if (firstRunVar) {
        firstRunVar = false;
        return true;
    } else {
        return false;
    }
}

void TetrimoT::update() {
    TextDim.y += yVel;
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
    return xPos;
}

int TetrimoT::getYPosition() {
    return yPos;
}

void TetrimoT::setXVelocity(int deltaX) {
    xVel += deltaX;
    return;
}

void TetrimoT::setYVelocity(int deltaY) {
    yVel +=deltaY;
    return;
}
