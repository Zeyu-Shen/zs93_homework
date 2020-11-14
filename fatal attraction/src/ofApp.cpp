#include "ofApp.h"
using namespace glm;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::peachPuff);
    vec2 mousePos = vec2(ofGetMouseX(), ofGetMouseY());
    balls.push_back(Ball(mousePos, 10));
    vec2 ballPos = vec2(50, 100);
    balls.push_back(Ball(ballPos, 5));
    font.load("Iron.ttf", 90);
    //cout<<balls[1].pos<<endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    //cout<<balls.size()<<endl;
    //cout<<balls[1].pos<<endl;
    if (!finish_fail && !finish_success){
        vec2 mousePos = vec2(ofGetMouseX(), ofGetMouseY());
        if (balls.size()) balls[0].pos = mousePos;
        vec2 diff = mousePos-balls[1].pos;
        double distance = length(diff);
        if (balls.size()>=2){
            if (distance != 0 && distance < 100){
                double diff1 = ofGetMouseX()-balls[1].pos.x;
                double norm1 = diff1/distance;
                double diff2 = ofGetMouseY()-balls[1].pos.y;
                double norm2 = diff2/distance;
                balls[1].applyForce(vec2(0.5, -norm2*5));
            }
            balls[1].applyForce(vec2(0, 0.5));
            balls[1].applyDampingForce(0.1);
            balls[1].update();
        }
    }
    
    if (balls[1].pos.y+balls[1].m*2>=ofGetHeight()){
        finish_fail = true;
    }
    
    if (balls[1].pos.x<=balls[1].m*2){
        finish_fail = true;
    }
    
    if (balls[1].pos.y<=balls[1].m*2){
        finish_fail = true;
    }
    
    if (balls[1].pos.x+balls[1].m*2>=ofGetWidth()){
        finish_success = true;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<balls.size(); i++){
        balls[i].draw();
    }
    ofDrawBitmapString("Try To Take The Small Ball To The Right Without Touching The Other Three Sides!", 15, 15);
    if (finish_success || finish_fail){
        gameOver();
    }
}

void ofApp::gameOver(){
    if (finish_fail){
        font.drawString("Game Over!", ofGetWidth()/2-270, ofGetHeight()/2+30);
    }
    if (finish_success){
        font.drawString("You Won!", ofGetWidth()/2-240, ofGetHeight()/2+30);
    }
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
