//
//  Ball.hpp
//  fatal attraction
//
//  Created by Zeyu Shen on 11/14/20.
//

#pragma once
#include "ofMain.h"
using namespace glm;

class Ball{
    
public:
    Ball();
    Ball(vec2 _pos, int _m);
    
    void applyForce(vec2 force);
    void applyDampingForce(double strength);
    void update();
    void draw();
    
    vec2 pos, vel, acc;
    vec2 elasticForce;
    double m;
};
