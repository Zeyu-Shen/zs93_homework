#include "ofApp.h"
double base = 600;
double g = 0.98;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ball.energy = 30;
    ball.posy = base;
    ball.posx = ofGetWidth()/2;
}

//--------------------------------------------------------------
void ofApp::update(){
    //kinetic energy
    double k = ball.energy-g*(base-ball.posy);
    //cout<<ball.posy<<" ";
    //when the ball reaches its leftmost or rightmost
    //cout<<k<<endl;
    if (k<=1e-4){
        ball.up = false;
        if (ball.posx<ofGetWidth()/2){
            ball.left = false;
        }
        else{
            ball.left = true;
        }
        k = 1e-4;
    }
    //velocity
    double v = pow(2*k, 0.5);
    double angle = atan2(abs(ball.posy-ofGetHeight()+665), abs(ball.posx-ofGetWidth()/2));
    //when the ball is at its lowest
    if (abs(ball.posx - ofGetWidth()/2)<10){
        ball.up = true;
    }
    double vx = abs(v*sin(angle));
    double vy = abs(v*cos(angle));
    //cout<<ball.vx<<" "<<ball.vy<<endl;
    if (ball.up){
        ball.vy = -vy;
    }
    else{
        ball.vy = vy;
    }
    if (ball.left){
        ball.vx = -vx;
    }
    else{
        ball.vx = vx;
    }
    ball.posx+=ball.vx;
    ball.posy+=ball.vy;
    //cout<<ball.energy<<endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawRectangle(ofGetWidth()/2-100, ofGetHeight()-50, 200, 50);
    ofDrawRectangle(ofGetWidth()/2-10, ofGetHeight()-650, 20, 600);
    ofDrawRectangle(ofGetWidth()/2-60, ofGetHeight()-680, 120, 30);
    ofDrawLine(ofVec3f(ofGetWidth()/2, ofGetHeight()-665), ofVec3f(ball.posx, ball.posy));
    ofSetColor(ball.color);
    ofDrawCircle(ball.posx, ball.posy, ball.radius);
    ofDrawBitmapString("Click Your Mouse to Make the Ball Move Faster and Higher!", 30, 30);
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
    if (ball.energy+10<200){
        ball.energy += 10;
    }
    else{
        ball.energy = 200;
    }
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
