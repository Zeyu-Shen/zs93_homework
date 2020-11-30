//
//  Ball.cpp
//  zs93_week1class2
//
//  Created by Zeyu Shen on 10/28/20.
//

#include "Ball.hpp"
using namespace glm;

Ball::Ball(){
    radius = 10;
    
    color = ofColor(ofRandom(0, 255));
    
    x = ofGetWidth()/5;
    y = ofGetHeight()/2;
    
    dirY = 0;
}

void Ball::update(){
    y+=dirY;
    dirY+=aY;
    
    if (y>=ofGetHeight()-radius){
        y = ofGetHeight()-radius;
    }
    
    if (y<=radius){
        y = radius;
    }
}

void Ball::click_update(){
    dirY = -6;
}

void Ball::draw(){
    ofSetColor(color);
    
    ofDrawSphere(vec3(x,y, 0), radius);
}
