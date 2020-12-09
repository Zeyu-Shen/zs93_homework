//
//  Ball.cpp
//  Final Project
//
//  Created by Zeyu Shen on 12/9/20.
//

#include "Ball.hpp"

Ball::Ball(){
    radius = 32;
    
    color = ofColor(150);
    
    x = ofGetWidth()/2;
    y = 3.5*ofGetHeight()/5;
    z = 0;
    
    dirY = 0;
}

void Ball::update(){
    if (y+dirY<=3.5*ofGetHeight()/5) y+=dirY;
    if (dirY+aY < 12) dirY+=aY;
    if (update_left) x-=dirX;
    if (update_right) x+=dirX;
}

void Ball::click_update(){
    dirY = -6;
}

void Ball::draw(){
    ofSetColor(color);
    
    ofDrawIcoSphere(x, y, z, radius);
}
