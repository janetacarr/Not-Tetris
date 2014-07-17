//
//  TetrimoT.h
//  Not Tetris
//
//  Created by Justin Carr on 2014-04-05.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#ifndef __Not_Tetris__TetrimoT__
#define __Not_Tetris__TetrimoT__

#include <iostream>
#include "GameEngine.h"
#include "Tetrimo.h"

//#include "physics.h"



class TetrimoT : public Tetrimo {
public:
    void init();
    void buildSprite(GameEngine* game);
    bool firstRun();
    //TetrimoT(int xPosition, int yPosition, int xVelocity, int yVelocity);
    std::string getTexturePath();
    SDL_Rect getTextureDimensions();
    SDL_Rect getTexturePlace();
    std::vector<SDL_Rect> getAABB();
    int getXPosition();
    int getYPosition();
    void setXVelocity(int); //Pixels per frame
    void setYVelocity(int); //Pixels per frame
    void update(float t, float dt, float accumulator);
    SDL_Texture* tex;
    void interpolateStates(float t, float dt, float accumulator);
private:
    //State S;
    State current;
    State previous;
    
    bool firstRunVar = true;
    std::string TexturePath = "/Users/justinacarr/Not-Tetris/Not Tetris/Textures/Tetrimos.png";
    SDL_Rect TextDim;
    SDL_Rect TextPlace;
    float time;
    int xPos;
    int yPos;
    int xVel;
    int yVel;
    int acceleration;
    const int maxVelocity = 20;
    
};

#endif /* defined(__Not_Tetris__TetrimoT__) */
