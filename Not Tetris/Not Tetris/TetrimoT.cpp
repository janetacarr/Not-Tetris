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
    yCap = 440;
    
    //Axis Aligned bounding boxes for this tetrimo
    AABB = {
        {
            this->getXPosition(),
            this->getYPosition(),
            60,
            20
        },{
            this->getXPosition()+20,
            this->getYPosition()+20,
            20,
            20
        }
    };
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
    //std::vector<SDL_Rect> v;
    return AABB;
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

void TetrimoT::updateAABB() {
    AABB = {
        {
            this->getXPosition(),
            this->getYPosition(),
            60,
            20
        },
        {
            this->getXPosition()+20,
            this->getYPosition()+20,
            20,
            20
        },
        {
            this->getXPosition(),
            this->getYPosition(),
            60,
            20
        }
    };
}
//Taking care of business.
void TetrimoT::update(float t, float dt, float accumulator, std::vector<std::unique_ptr<Tetrimo>>& tetrimoStack) {
    previous = current;
    integrate(current, t, dt);
    
    //Update collider boxes after integrating state.
    updateAABB();
    
    //Check for the collisions
    for (auto& x: tetrimoStack ) {
        this->checkCollision(x.get());
    }
    
    //Cap the position on screen.
    /*if (current.v > 50) {   //Toy velocity limit
        current.v = 50;
    }*/
    if (current.x >= yCap) { //Toy distance limit.
        current.x = yCap;
        current.v = 0;
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

bool TetrimoT::checkCollision(const std::vector<std::unique_ptr<Tetrimo>>& tetrimoStack) {
    bool collision = false;
    
    for (auto& x : tetrimoStack ) {
        updateAABB();
        
        int leftA, leftB;
        int rightA, rightB;
        int topA, topB;
        int bottomA, bottomB;
        
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
                return true;
            }
        }
    }
    return collision;
}

void TetrimoT::checkCollision(Tetrimo* particle) {
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