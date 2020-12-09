//
//  Line.cpp
//  Final Project
//
//  Created by Zeyu Shen on 12/9/20.
//

#include "Line.hpp"

Line::Line(){
    color = ofColor(255);
    Z = -400;
    Y = 400;
    for (int i=0; i<ofGetWidth()/4; i++){
        Particle p = Particle(glm::vec3(i*4+1, Y, Z), glm::vec3(0, dirY, -dirZ), 1);
        particles.push_back(p);
    }
}

void Line::update(){
    for (int i=0; i<particles.size(); i++){
        particles[i].update();
    }
    Y+=dirY;
    Z-=dirZ;
}

void Line::draw(){
    ofSetColor(color);
    for (int i=0; i<particles.size(); i++){
        particles[i].draw();
    }
}
