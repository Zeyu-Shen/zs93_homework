#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class snow{
public:
    snow();
    snow(glm::vec2 _pos);
    void applyForce(glm::vec2 force);
    void update();
    void draw();
    glm::vec2 pos;
    vector<Particle> particles;
    bool good = true;
};
