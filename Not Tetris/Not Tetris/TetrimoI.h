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
    
    void updateAABB();
    std::vector<SDL_Rect> getAABB();
    
    //Self explanatory, Although doesn't function as you would expect.
    int getXPosition();
    int getYPosition();
    void setXVelocity(float); //Pixels per frame
    void setYVelocity(float); //Pixels per frame
    
    //Update for drawing phase
    void update(float t, float dt, float accumulator, std::vector<std::unique_ptr<Tetrimo>>& tetrimoStack);
    
    //Drawing phase methods.
    void interpolateStates(float t, float dt, float accumulator);
    void draw(GameEngine* game);
    
    //Tetrimo Mechanics
    void rotateClockWise();
    void rotateCounterClockWise();
    void faceUp();
    void faceDown();
    void checkCollision(Tetrimo*);
    bool checkCollision(const std::vector<std::unique_ptr<Tetrimo>>&);

private:
    //Two states to integrate and interpolate between for update and drawing phases.
    State current;
    State previous;
    
    //Orientation of texture as a
    SDL_RendererFlip flipType;
    
    //Axis aligned bounding boxes
    std::vector<SDL_Rect> AABB;
    
    //The texture from the spritesheet
    SDL_Texture* tex;
    
    bool weInterpolate = true;
    bool firstRunVar = true;
    
    std::string TexturePath = "/Users/justinacarr/Not-Tetris/Not Tetris/Textures/Tetrimos.png";
    
    //Texture dimensions to be clipped from the spritesheet when rendered.
    SDL_Rect TextDim;
    
    //Texture's place on screen, functions as destination rectangle on the renderer
    SDL_Rect TextPlace;
    
    //Misc. Possibly slated for deletion.
    float time;
    int xPos;
    int yPos;
    int xVel;
    int yVel;
    int acceleration;
    const int maxVelocity = 20;
    int yCap;
};


#endif /* defined(__Not_Tetris__TetrimoI__) */
