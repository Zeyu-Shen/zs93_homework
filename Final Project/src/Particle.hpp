//
//  Particle.hpp
//  Final Project
//
//  Created by Zeyu Shen on 12/9/20.
//

#pragma once
#include "ofMain.h"

class Particle {
    
public:
    
    Particle();
    Particle(glm::vec3 _pos, glm::vec3 _vel, float _mass);
    
    void applyForce(glm::vec3 force);
    void applyElasticForce(float strength);
    void update();
    void update2(float _ypos);
    void draw();
    ofColor color;
    
    float ypos;
    glm::vec3 pos, vel, acc;
    float mass;
    
};
