#include "ofApp.h"
#include "Ball.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::black);
    int num = 10;
    for (int i=0; i<num; i++){
        balls.push_back(Ball(vec2(i*30, i*20), 10));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<balls.size(); i++){
        balls[i].acc.x = ofRandom(-0.5, 0.5);
        balls[i].acc.y = ofRandom(-0.5, 0.5);
        balls[i].vel.x+=balls[i].acc.x;
        balls[i].vel.y+=balls[i].acc.y;
        balls[i].pos.x+=balls[i].vel.x;
        balls[i].pos.y+=balls[i].vel.y;
        
        if (balls[i].pos.y<=balls[i].m){
            balls[i].pos.y = balls[i].m;
            balls[i].vel.y = -balls[i].vel.y/2;
            balls[i].acc.y = 0;
        }
        
        if (balls[i].pos.y>=ofGetHeight()-balls[i].m){
            balls[i].pos.y = ofGetHeight()-balls[i].m;
            balls[i].vel.y = -balls[i].vel.y/2;
            balls[i].acc.y = 0;
        }
        
        if (balls[i].pos.x<=balls[i].m){
            balls[i].pos.x = balls[i].m;
            balls[i].vel.x = -balls[i].vel.x/2;
            balls[i].acc.x = 0;
        }
        
        if (balls[i].pos.x>=ofGetWidth()-balls[i].m){
            balls[i].pos.x = ofGetWidth()-balls[i].m;
            balls[i].vel.x = -balls[i].vel.x/2;
            balls[i].acc.x = 0;
        }
    }
    
    //detect collision between balls
    for (int i=0; i<balls.size(); i++){
        for (int j=i+1; j<balls.size(); j++){
            Ball b1 = balls[i];
            Ball b2 = balls[j];
            double d = length(b1.pos-b2.pos);
            if (d<=b1.m+b2.m){
                double angle = atan2(abs(b2.pos.y-b1.pos.y), abs(b2.pos.x-b1.pos.x));
                double vx1 = cos(angle)*b1.vel.x+sin(angle)*b1.vel.y;
                double vy1 = sin(angle)*(-b1.vel.x)+cos(angle)*b1.vel.y;
                double vx2 = cos(angle)*b2.vel.x+sin(angle)*b2.vel.y;
                double vy2 = sin(angle)*(-b2.vel.x)+cos(angle)*b2.vel.y;
                
                b1.vel.x = vx1*cos(angle)-vy1*sin(angle);
                b1.vel.y = vx1*sin(angle)+vy1*cos(angle);
                b2.vel.x = vx2*cos(angle)-vy2*sin(angle);
                b2.vel.y = vx2*sin(angle)+vy2*cos(angle);
                
                double len = b1.m+b2.m-d;
                if (b1.pos.x<=b2.pos.x){
                    b1.pos.x-=len/2;
                    b2.pos.x+=len/2;
                }
                else{
                    b1.pos.x+=len/2;
                    b2.pos.x-=len/2;
                }
                balls[i] = b1;
                balls[j] = b2;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<balls.size(); i++){
        balls[i].draw();
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
