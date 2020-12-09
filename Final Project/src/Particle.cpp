#include "Particle.hpp"

Particle::Particle()
{
    pos = glm::vec3(0, 0, 0);
    vel = glm::vec3(0, 0, 0);
    acc = glm::vec3(0, 0, 0);
}

Particle::Particle(glm::vec3 _pos, glm::vec3 _vel, float _mass)
{
    pos = _pos;
    ypos = _pos.y;
    vel = _vel;
    mass = _mass;
}

void Particle::applyForce(glm::vec3 force)
{
    acc += force / mass;
}

void Particle::applyElasticForce(float strength){
    glm::vec3 currPos = glm::vec3(pos.x, ypos, pos.z);
    glm::vec3 diff = currPos-pos;
    float length = glm::length(diff);
    if (length != 0){
        glm::vec3 dir= diff/length;
        glm::vec3 elasticForce = dir*strength;
        applyForce(elasticForce);
    }
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    if (pos.y>ypos+5){
        pos.y = ypos;
    }
    acc *= 0;
}

void Particle::update2(float _ypos){
    ypos = _ypos;
}

void Particle::draw()
{
    ofPushStyle();
    
    // interpolate between colors!
    ofColor cSlow    = ofColor::fromHex(0xC1D5FF);    // hex format: 0xRRGGBB
    ofColor cFast    = ofColor::fromHex(0xFF4831);
    
    float percent    = ofMap(glm::length(vel-glm::vec3(0, 1.5, 3)), 0., 7., 0., 1., true);    // mix based on speed
    ofColor color   = cSlow.lerp(cFast, percent);    // "lerp" == interpolate
    
    ofSetColor(color);
    
    ofDrawCircle(pos, mass * 2.0);  // base radius on mass
    
    ofPopStyle();
}
