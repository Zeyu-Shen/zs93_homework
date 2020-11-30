#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    background.load("room.jpg");
    ofSetBackgroundAuto(false);
    bgPos=glm::vec2 (0,0);
    windowPos = glm::vec2(76, 111);
    winter.load("winter.png");
    autumn.load("autumn.png");
    s = snow();
    start = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (start){
        s.update();
        transparency+=0.05;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    background.draw(bgPos, 700, 700);
    ofPushStyle();
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, 255-transparency);
    autumn.draw(windowPos, 555, 288);
    ofSetColor(255, 255, 255, transparency);
    winter.draw(windowPos, 555, 288);
    ofDisableAlphaBlending();
    ofPopStyle();
    ofDrawBitmapString("Press Space to See Winter!", 15, 55);
    s.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        start = true;
    }
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
