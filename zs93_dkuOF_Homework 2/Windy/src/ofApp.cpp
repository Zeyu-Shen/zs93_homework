#include "ofApp.h"
#include <cmath>
double t = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(100);
    
    int nBalls = 5;
    for (int i=0; i<nBalls; i++){
        Ball ball;
        ball.radius = ofMap(i, nBalls, 0, 10, 50);
        ball.posx = ofRandom(ball.radius, ofGetWidth()-ball.radius);
        ball.posy = ofRandom(ball.radius, ofGetHeight()-ball.radius);
        ball.mass = 10*ball.radius*ball.radius;
        ball.color.r = 0;
        ball.color.b = ofMap(ball.radius, 10, 50, 0, 255);
        ball.color.g = ofMap(ball.radius, 50, 10, 0, 255);
        
        balls.push_back(ball);
    }
    
    int nWind = 3;
    for (int i=0; i<nWind; i++){
        Wind wind;
        wind.fx = ofRandom(-3, 3);
        wind.fy = ofRandom(-2, 2);
        winds.push_back(wind);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    t+=0.05;
    
    if (t>0.5){
        for (int i=0; i<winds.size(); i++){
            winds[i].fx = ofRandom(-3, 3);
            winds[i].fy = ofRandom(-2, 2);
        }
        t = 0;
    }
    
    for (int i=0; i<balls.size(); i++){
        balls[i].vx+=balls[i].ax;
        balls[i].vy+=balls[i].ay;
        for (int j=0; j<winds.size(); j++){
            balls[i].ax+=winds[j].fx/balls[i].mass;
            balls[i].ay+=winds[j].fy/balls[i].mass;
        }
        balls[i].posx+=balls[i].vx;
        balls[i].posy+=balls[i].vy;
        
        if (balls[i].posy<=balls[i].radius){
            balls[i].posy = balls[i].radius;
            balls[i].vy = -balls[i].vy/2;
            balls[i].ay = 0;
        }
        
        if (balls[i].posy>=ofGetHeight()-balls[i].radius){
            balls[i].posy = ofGetHeight()-balls[i].radius;
            balls[i].vy = -balls[i].vy/2;
            balls[i].ay = 0;
        }
        
        if (balls[i].posx<=balls[i].radius){
            balls[i].posx = balls[i].radius;
            balls[i].vx = -balls[i].vx/2;
            balls[i].ax = 0;
        }
        
        if (balls[i].posx>=ofGetWidth()-balls[i].radius){
            balls[i].posx = ofGetWidth()-balls[i].radius;
            balls[i].vx = -balls[i].vx/2;
            balls[i].ax = 0;
        }
    }
    
    //detect collision between balls
    for (int i=0; i<balls.size(); i++){
        for (int j=i+1; j<balls.size(); j++){
            Ball b1 = balls[i];
            Ball b2 = balls[j];
            double d = pow((pow(b1.posx-b2.posx,2)+pow(b1.posy-b2.posy,2)), 0.5);
            if (d<=b1.radius+b2.radius){
                double angle = atan2(abs(b2.posy-b1.posy), abs(b2.posx-b1.posx));
                cout<<angle<<endl;
                double vx1 = cos(angle)*b1.vx+sin(angle)*b1.vy;
                double vy1 = sin(angle)*(-b1.vx)+cos(angle)*b1.vy;
                double vx2 = cos(angle)*b2.vx+sin(angle)*b2.vy;
                double vy2 = sin(angle)*(-b2.vx)+cos(angle)*b2.vy;
                
                b1.vx = vx1*cos(angle)-vy1*sin(angle);
                b1.vy = vx1*sin(angle)+vy1*cos(angle);
                b2.vx = vx2*cos(angle)-vy2*sin(angle);
                b2.vy = vx2*sin(angle)+vy2*cos(angle);
                
                double len = b1.radius+b2.radius-d;
                if (b1.posx<=b2.posx){
                    b1.posx-=len/2;
                    b2.posx+=len/2;
                }
                else{
                    b1.posx+=len/2;
                    b2.posx-=len/2;
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
        ofSetColor(balls[i].color);
        ofDrawCircle(balls[i].posx, balls[i].posy, balls[i].radius);
    }
    ofDrawBitmapString("The Speed of the First Wind  x: "+to_string(winds[0].fx)+" y:  "+to_string(winds[0].fy), 15, 15);
    ofDrawBitmapString("The Speed of the Second Wind  x: "+to_string(winds[1].fx)+" y:  "+to_string(winds[1].fy), 15, 25);
    ofDrawBitmapString("The Speed of the Third Wind  x: "+to_string(winds[2].fx)+" y:  "+to_string(winds[2].fy), 15, 35);
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
