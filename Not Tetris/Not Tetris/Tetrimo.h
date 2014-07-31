//
//  Tetrimo.h
//  Not Tetris
//
//  Created by Justin Carr on 2014-04-05.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#ifndef Not_Tetris_Tetrimo_h
#define Not_Tetris_Tetrimo_h
#include "GameEngine.h"
#include <iostream>
#include <vector>



class Tetrimo{
public:
    //For Texture acquisition
    virtual std::string getTexturePath() = 0;
    virtual SDL_Rect getTexturePlace()=0;
    virtual SDL_Rect getTextureDimensions()=0;
    
    virtual SDL_Texture* getTexture()=0;
    virtual std::vector<SDL_Rect> getAABB()=0;
    
    
    virtual int getXPosition()=0;
    virtual int getYPosition()=0;
    virtual void setXVelocity(float)=0;
    virtual void setYVelocity(float)=0; 
    
    //Simulate falling. The two states are interpolated in the drawing phase below.
    virtual void update(float t, float dt, float accumulator)=0;
    
    //Drawing methods, for the drawing phase.
    virtual void interpolateStates(float t, float dt, float accumulator)=0;
    virtual void draw(GameEngine*)=0;
    
    //Tetrimo mechanics methods.
    virtual void rotateClockWise()=0;//Should rotate AABB and texture's place on screen, use SDL_RenderCopyEx
    virtual void rotateCounterClockWise()=0;//Same ^
    virtual void faceUp()=0; //Should flip texture's place on screen, also flips the AABB for the tetrimo */
    virtual void faceDown()=0;
    
protected:
    Tetrimo() {}
};


#endif
