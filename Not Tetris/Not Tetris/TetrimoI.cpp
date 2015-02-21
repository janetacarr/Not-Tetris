//
//  TetirmoI.cpp
//  Not Tetris
//
//  Created by Justin Carr on 2014-07-31.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "TetrimoI.h"

TetrimoI::TetrimoI(GameEngine* game) {
    tex = IMG_LoadTexture(&(game->getRenderer()), TexturePath.c_str());
    std::cout << "init" << std::endl;
    time = 0.0f;
    current.x = 20.0f;
    current.v = 0;
    previous = current;
    TextDim.x = 360;
    TextDim.y = 20;
    TextDim.w = 20;
    TextDim.h = 80;
    TextPlace.x = 160;
    TextPlace.y = 20;
    TextPlace.w = 20;
    TextPlace.h = 80;
    yCap = 400;
    
    //Axis Aligned bounding boxes for this tetrimo
    AABB = {
        {
            this->getXPosition(),
            this->getYPosition(),
            20,
            80
        }
    };
}

void TetrimoI::init() {
    return;
}

SDL_Texture* TetrimoI::getTexture() {
    return tex;
}

std::string TetrimoI::getTexturePath() {
    return TexturePath;
}

SDL_Rect TetrimoI::getTextureDimensions() {
    return TextDim;
}

SDL_Rect TetrimoI::getTexturePlace() {
    return TextPlace;
}

std::vector<SDL_Rect> TetrimoI::getAABB(){
    return AABB;
}

int TetrimoI::getXPosition() {
    return TextPlace.x;
}

int TetrimoI::getYPosition() {
    return TextPlace.y;
}

void TetrimoI::setXVelocity(float deltaX) {
    TextPlace.x += (int)deltaX;
    return;
}

void TetrimoI::setYVelocity(float deltaY) {
    TextPlace.y = (int)deltaY;
    //yVel +=deltaY;
    return;
}

void TetrimoI::updateAABB() {
    AABB = {
        {
            this->getXPosition(),
            this->getYPosition(),
            20,
            80
        }
    };
}

//Integrate acceleration.
void TetrimoI::update(float t, float dt, float accumulator, std::vector<std::unique_ptr<Tetrimo>>& tetrimoStack) {
    previous = current;
    integrate(current, t, dt);
    
    //Update collider boxes after integrating state.
    updateAABB();
    
    //Check for the collisions
    for (auto& x: tetrimoStack ) {
        this->checkCollision(x.get());
    }
    
    //Cap the position on screen.
    if (current.v > 50) {   //Toy velocity limit
        current.v = 50;
    }
    if (current.x >= yCap) { //Toy distance limit.
        current.x = yCap;
        current.v = 0;
    }
    
}

//Drawing phase.
void TetrimoI::interpolateStates(float t, float dt, float accumulator) {
    State state = interpolate(previous, current, accumulator/dt);
    std::cout << "interpolated x: " << state.x << std::endl << "interpolated Velocity: " << state.v << std::endl;
    TextPlace.y = state.x; //TextDim.y = state.x; causes scrolling over spritesheet, super cool effect.
}

void TetrimoI::draw(GameEngine* game) {
    this->interpolateStates(game->getTimer().getTime(), game->getTimer().getTimeStep(), game->getTimer().getAccumulator());
    SDL_Rect dstRect = this->getTexturePlace(); //Place on the SDL_Window where the texture should be.
    SDL_Rect srcRect = this->getTextureDimensions(); //Source x, y, w, h of the sprite from the sprite sheet
    SDL_RenderCopy(&(game->getRenderer()), this->getTexture(), &srcRect, &dstRect);
}

//Tetrimo Mechanics
void TetrimoI::rotateClockWise() {
    return;
}

void TetrimoI::rotateCounterClockWise() {
    return;
}

void TetrimoI::faceUp() {
    return;
}

void TetrimoI::faceDown() {
    return;
}

bool TetrimoI::checkCollision(const std::vector<std::unique_ptr<Tetrimo>>& tetrimoStack) {
    for (auto& x : tetrimoStack ) {
        updateAABB();
        
        int leftA, leftB;
        int rightA, rightB;
        int topA, topB;
        int bottomA, bottomB;
        bool collision = true;
        
        for (auto& a: AABB ) {
            leftA = a.x;
            rightA = a.x + a.w;
            topA = a.y;
            bottomA = a.y + a.h;
            
            for (auto& b: x->getAABB()) {
                leftB = b.x;
                rightB = b.x + b.w;
                topB = b.y;
                bottomB = b.y + b.h;
                
                if( bottomA <= topB ) {
                    collision = false;
                }
                if( topA >= bottomB ) {
                    collision = false;
                }
                if( rightA <= leftB ) {
                    collision = false;
                }
                if( leftA >= rightB ) {
                    collision = false;
                }
                return collision;
            }
        }
    }
    return false;
}

void TetrimoI::checkCollision(Tetrimo* particle) {
    updateAABB();
    
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    bool collision = true;
    
    for (auto& a: AABB ) {
        leftA = a.x;
        rightA = a.x + a.w;
        topA = a.y;
        bottomA = a.y + a.h;
        
        for (auto& b: particle->getAABB()) {
            leftB = b.x;
            rightB = b.x + b.w;
            topB = b.y;
            bottomB = b.y + b.h;
            
            if( bottomA <= topB ) {
                collision = false;
            }
            if( topA >= bottomB ) {
                collision = false;
            }
            if( rightA <= leftB ) {
                collision = false;
            }
            if( leftA >= rightB ) {
                collision = false;
            }
            //if there is a collision cap the textures y position.
            if (collision) {
                int distanceFrom = this->getTexturePlace().y - a.y;
                yCap = b.y - a.h + distanceFrom;
            }
        }
    }
}