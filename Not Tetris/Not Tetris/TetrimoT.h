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
//class Tetrimo;
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
    void update();
    SDL_Texture* tex;

    
private:
    
    bool firstRunVar = true;
    std::string TexturePath = "/Users/justinacarr/Not-Tetris/Not Tetris/Textures/Tetrimos.png";
    SDL_Rect TextDim;
    SDL_Rect TextPlace;
    int xPos;
    int yPos;
    int xVel;
    int yVel;
    int acceleration;
    const int maxVelocity = 20;
    
};

#endif /* defined(__Not_Tetris__TetrimoT__) */
