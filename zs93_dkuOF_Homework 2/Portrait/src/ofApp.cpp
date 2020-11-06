#include "ofApp.h"
ofVec3f dist1, dist2, dist3, dist4, dist5;

void Portrait::update(ofVec3f target){
    ofVec3f target2 = target+dist1;
    ofVec3f target3 = target+dist2;
    ofVec3f target4 = target+dist3;
    ofVec3f target5 = target+dist4;
    ofVec3f target6 = target+dist5;
    head_center = head_center*(1.-lerp1)+target*lerp1;
    body_bottom = body_bottom*(1.-lerp2)+target2*lerp2;
    left_hand = left_hand*(1.-lerp3)+target3*lerp3;
    right_hand = right_hand*(1.-lerp4)+target4*lerp4;
    left_foot = left_foot*(1.-lerp5)+target5*lerp5;
    right_foot = right_foot*(1.-lerp6)+target6*lerp6;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    me.head_radius = 15;
    double w = ofGetWidth();
    double h = ofGetHeight();
    me.head_center = ofVec3f(w/2, h-100);
    me.body_bottom = ofVec3f(w/2, h-30);
    me.left_foot =ofVec3f(w/2-20, h);
    me.right_foot = ofVec3f(w/2+20, h);
    me.left_hand = ofVec3f(w/2-20, h-40);
    me.right_hand = ofVec3f(w/2+20, h-40);
    dist1 = me.body_bottom-me.head_center;
    dist2 = me.left_hand-me.head_center;
    dist3 = me.right_hand-me.head_center;
    dist4 = me.left_foot-me.head_center;
    dist5 = me.right_foot-me.head_center;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec3f target;
    target.set(ofGetMouseX(), ofGetMouseY());
    me.update(target);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(me.head_center, me.head_radius);
    ofVec3f pt1 = me.head_center+ofVec3f(0, me.head_radius);
    ofDrawLine(pt1, me.body_bottom);
    ofVec3f pt2 = 0.7*pt1+0.3*me.body_bottom;
    ofDrawLine(pt2, me.left_hand);
    ofDrawLine(pt2, me.right_hand);
    ofDrawLine(me.body_bottom, me.left_foot);
    ofDrawLine(me.body_bottom, me.right_foot);
    ofDrawBitmapString("Use Your Mouse to Move Me!", 15, 15);
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
