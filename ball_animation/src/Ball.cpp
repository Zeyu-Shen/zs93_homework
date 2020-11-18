//
//  Ball.cpp
//  fatal attraction
//
//  Created by Zeyu Shen on 11/14/20.
//

#include "Ball.hpp"
using namespace glm;

Ball::Ball(){
    pos = vec2(0, 0);
    vel = vec2(0, 0);
    acc = vec2(0, 0);
    
    m = 5;
}

Ball::Ball(vec2 _pos, int _m){
    pos = _pos;
    origPos = _pos;
    vel =  vec2(0, 0);
    acc =  vec2(0, 0);
    m = _m;
}

void Ball::applyForce(vec2 force){
    acc+=force/m;
}

void Ball::applyDampingForce(double strength){
    double speed = length(vel);
    if (speed != 0){
        vec2 dir = vel/speed;
        applyForce(-dir*strength);
    }
}

void Ball::applyElasticForce(double strength)
{
    glm::vec2 diff = origPos - pos;
    float length = glm::length(diff);
    if (length != 0){
        glm::vec2 dir = diff / length;
        elasticForce = dir * strength;
        applyForce( elasticForce );

    }
}

void Ball::update(){
    vel+=acc;
    pos+=vel;
    acc*=0;
}

void Ball::draw(){
    ofDrawCircle(pos, m*2.0);
}
