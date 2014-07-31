//
//  TetirmoI.h
//  Not Tetris
//
//  Created by Justin Carr on 2014-07-31.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#ifndef __Not_Tetris__TetrimoI__
#define __Not_Tetris__TetrimoI__

#include <iostream>
#include "Tetrimo.h"

class TetrimoI : public Tetrimo {
public:
    TetrimoI(GameEngine* game);
    
    //Slated for deletion from all tetrimo subclasses.
    void init();
    void buildSprite(GameEngine* game);
    bool firstRun();
    
    //Texture acquistion stuff
    SDL_Texture* getTexture();
    std::string getTexturePath();
    SDL_Rect getTextureDimensions();
    SDL_Rect getTexturePlace();
    std::vector<SDL_Rect> getAABB();
    
    //Self explanatory, Although doesn't function as you would expect.
    int getXPosition();
    int getYPosition();
    void setXVelocity(float); //Pixels per frame
    void setYVelocity(float); //Pixels per frame
    
    //Update for drawing phase
    void update(float t, float dt, float accumulator);
    
    //Drawing phase methods.
    void interpolateStates(float t, float dt, float accumulator);
    void draw(GameEngine* game);
    
    //Tetrimo Mechanics
    void rotateClockWise();
    void rotateCounterClockWise();
    void faceUp();
    void faceDown();

private:
    //State S;
    State current;
    State previous;
    
    SDL_Texture* tex;
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


#endif /* defined(__Not_Tetris__TetrimoI__) */
