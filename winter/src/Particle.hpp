#pragma once
#include "ofMain.h"
class Particle {

public:

    Particle();
    Particle(glm::vec2 _pos, glm::vec2 _vel, ofColor _color);
    ofColor color;
    glm::vec2 pos, vel, acc;
    void applyForce(glm::vec2 force);
    void update();
    void draw();

};
