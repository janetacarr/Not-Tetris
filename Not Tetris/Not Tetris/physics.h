//
//  physics.h
//  Not Tetris
//
//

#ifndef Not_Tetris_physics_h
#define Not_Tetris_physics_h
#include<stdio.h>
#include<math.h>


const float DELTATIME = 0.0167f;

struct State
{
	float x;
	float v;
};

struct Derivative
{
	float dx;
	float dv;
};

float acceleration(const State state, float t);

Derivative evaluate(const State &initial, float t);

Derivative evaluate(const State &initial, float t, float dt, const Derivative &d);

void integrate(State &state, float t, float dt);

State interpolate(const State &previous, const State &current, float alpha);

#endif
