//
//  Dot.cpp
//  Midterm Project
//
//  Created by Zeyu Shen on 11/21/20.
//

#include "Dot.hpp"
using namespace glm;

Dot::Dot(double _len, double _va, double _basex, double _basey){
    color = ofColor(0, 0, 0);
    len = _len;
    va = _va;
    basex = _basex;
    basey = _basey;
    angle = 0;
    px = basex+len*(cos(angle));
    py = basey+len*(sin(angle));
}

void Dot::update(){
    angle+=va;
    px = basex+len*(cos(angle));
    py = basey+len*(sin(angle));
}

void Dot::draw(){
    ofDrawLine(vec2(basex, basey), vec2(px, py));
}
