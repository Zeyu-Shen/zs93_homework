#include "snow.hpp"
snow::snow() {
}

snow::snow(glm::vec2 _pos) {
    pos = _pos;
}

void snow::applyForce(glm::vec2 force) {
    for (int i = 0; i < particles.size(); i++) {
        particles[i].applyForce(force);
    }
}

void snow::update() {
    if (good){
        Particle p = Particle(glm::vec2(ofRandom(80, 76+551), 111), glm::vec2(ofRandom(-0.1, 0.1), ofRandom(0.5, 1)), ofColor(255, 255, 255));
        particles.push_back(p);
    }
    for (int i=0; i<particles.size(); i++){
        particles[i].update();
    }
    for (auto i=particles.begin(); i!= particles.end(); i++){
        if ((*i).pos.y >=288+109 || (*i).pos.x<76 || (*i).pos.x>76+555){
            particles.erase(i);
        }
    }
    good = !good;
}

void snow::draw() {
    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
}
