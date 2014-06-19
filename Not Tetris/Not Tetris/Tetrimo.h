//
//  Tetrimo.h
//  Not Tetris
//
//  Created by Justin Carr on 2014-04-05.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#ifndef Not_Tetris_Tetrimo_h
#define Not_Tetris_Tetrimo_h
#include <iostream>
#include <vector>
#include "SDL2/SDL.h"

class Tetrimo{
public:
    virtual std::string getTexturePath() = 0;
    virtual SDL_Rect getTextureDimensions()=0;
    virtual std::vector<SDL_Rect> getAABB()=0;
    virtual int getXPosition()=0;
    virtual int getYPosition()=0;
    virtual void setXVelocity(int)=0; //Pixels per frame
    virtual void setYVelocity(int)=0; //Pixels per frame
    
private:
    //for use with physics.h
    struct Derivative {
        float dv;
        float dx;
    };
    //for use with physics.h
    struct State {
        float x;
        float v;
    };
protected:
    Tetrimo(){}
};


#endif
