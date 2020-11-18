#include "ofApp.h"
#include "Particle.hpp"
#include "ParticleSystem.hpp"
using namespace glm;
typedef pair<Particle, ParticleSystem> ppp;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    vec2 pos = vec2(ofGetWidth()*0.5, ofGetHeight()*0.5);
    gravity = vec2(0, 0.15);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<particleSystems.size(); i++){
        if (particleSystems[i].first.vel.y>=0){
            particleSystems[i].second.applyForce(gravity);
            particleSystems[i].second.update();
        }
        else{
            particleSystems[i].first.applyForce(gravity);
            particleSystems[i].first.update();
            particleSystems[i].second.pos = particleSystems[i].first.pos;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<particleSystems.size(); i++){
        if (particleSystems[i].first.vel.y>=0){
            particleSystems[i].second.draw();
        }
        else particleSystems[i].first.draw();
    }
    ofDrawBitmapString("Click the mouse to see FireWork!", 15, 15);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    glm::vec2 vel   = glm::vec2(0, -8);   // move up
    float mass      = ofRandom(1, 2);
    Particle particle = Particle(vec2(x, y),vel,mass);
    particleSystems.push_back(make_pair(particle, ParticleSystem(vec2(x, y))));
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
