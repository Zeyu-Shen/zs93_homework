#include "Particle.hpp"

Particle::Particle(){
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, ofColor _color)
{
    color = _color;
    pos = _pos;
    vel = _vel;
    acc = glm::vec2(0, 0);
    
}

void Particle::applyForce(glm::vec2 force)
{
    acc += force;
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Particle::draw()
{
    ofPushStyle();
    ofSetColor(color);
    ofDrawCircle(pos,3);
    ofPopStyle();
}
