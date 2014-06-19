//
//  physics.h
//  Not Tetris
//
//  Created by Justin Carr on 2014-06-19.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#ifndef Not_Tetris_physics_h
#define Not_Tetris_physics_h
#include<stdio.h>
#include<math.h>

float acceleration(const State &state, float t)
{
	const float k = 10;
	const float b = 1;
	return - k*state.x - b*state.v;
}

Derivative evaluate(const State &initial, float t)
{
	Derivative output;
	output.dx = initial.v;
	output.dv = acceleration(initial, t);
	return output;
}

Derivative evaluate(const State &initial, float t, float dt, const Derivative &d)
{
	State state;
	state.x = initial.x + d.dx*dt;
	state.v = initial.v + d.dv*dt;
	Derivative output;
	output.dx = state.v;
	output.dv = acceleration(state, t+dt);
	return output;
}

void integrate(State &state, float t, float dt)
{
	Derivative a = evaluate(state, t);
	Derivative b = evaluate(state, t, dt*0.5f, a);
	Derivative c = evaluate(state, t, dt*0.5f, b);
	Derivative d = evaluate(state, t, dt, c);
    
	const float dxdt = 1.0f/6.0f * (a.dx + 2.0f*(b.dx + c.dx) + d.dx);
	const float dvdt = 1.0f/6.0f * (a.dv + 2.0f*(b.dv + c.dv) + d.dv);
	
	state.x = state.x + dxdt*dt;
	state.v = state.v + dvdt*dt;
}

#endif
