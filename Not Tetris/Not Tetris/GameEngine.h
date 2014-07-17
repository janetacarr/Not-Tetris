//
//  GameEngine.h
//  Not Tetris
//
//  Created by Justin Carr on 2014-01-19.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//


#ifndef __Not_Tetris__GameEngine__
#define __Not_Tetris__GameEngine__

#include <iostream>
#include <vector>
#include <memory>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "physics.h"

class Timer{
public:
    float createNewTime();
    float findFrameTime();
    void setCurrentTimeToNewTime();
    void accumulateTime();
    float getAccumulator() {return accumulator;}
    float getTimeStep() {return dt;}
    void consumeTime() {accumulator -= dt;}
    void advanceTime(){t += dt;}
    
    float getTime() {return t;}
    
    
private:
    float t = 0.0f;
	float dt = 0.1f;
	
	float currentTime = 0.0f;
	float accumulator = 0.0f;
    
    float newTime;
    float frameTime;
    
    
};

//kind of hacky
class GameState;

class GameEngine{
    
public:
   
    //Initialize SDL subsystem, game window, and renderers, and SDL modules(SDL_image)
    void init(std::string, int winWidth = 640, int winHeight = 480);
    
    //Quit the SDL subsystem and modules, destroy game window and renderer,
    void cleanUp();
    
    //Change to a particular state
    void changeState(GameState* state);
    
    //Wrap state in unique_ptr and push the state onto the stack
    void pushState(GameState* state);
    
    //Pop a state off of the stack
    void popState();
    
/*
 * The handleEvents() method and the update() method are used in conjunction to update the current game state.
 * handeEvents calls the current states handleEvents, which is an SDL_Event polling loop.
 * update calls the current states update() which would handle SDL_Textures and the Renderer.
 */
    void handleEvents();
    void update();
    
    //Update the display, to be subjected to frame rate control using interpolation SDL_RenderPresent(renderer)
    void draw();
    
    //Control quiting the game.
    bool running() { return mRunning; }
    void quit() { mRunning = false; }
    
    
    //Self explanatory getters
    SDL_Window& getWindow();
    SDL_Renderer& getRenderer();
    
private:
    //the stack of states, with a unique pointer managing each state's memory. The back of the vector is the top of the stack.
    std::vector<std::unique_ptr<GameState>> states;
    
    Timer timer;
    
    bool mRunning;
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    SDL_Rect mBox;
    
    
};



#endif /* defined(__Not_Tetris__GameEngine__) */
