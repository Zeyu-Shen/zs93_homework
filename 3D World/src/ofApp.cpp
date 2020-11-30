#include "ofApp.h"
#define sz 100

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    sphere = ofSpherePrimitive(1000, 50);
    sphere.setPosition(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    sphere.rotateDeg(0.05, glm::vec3(-1, 1, 0));
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofEnableDepthTest();
    ofSetColor(ofColor::purple);
    sphere.drawWireframe();
    ofPushStyle();
    ofEnableAlphaBlending();
    ofSetColor(100, 100, 100, 127);
    for (int i=0; i<boxes.size(); i++){
        boxes[i].draw();
        boxes[i].rotateDeg(0.1, glm::vec3(1, -1, 0));
        boxes[i].rotateDeg(0.1, glm::vec3(1, -1, 0));
    }
    ofPopStyle();
    ofDisableAlphaBlending();
    ofDisableDepthTest();
    cam.end();
    
    // instructions:
    ofDrawBitmapString("Drag or Scroll you mouse to Control the Camera!", 20, 20);
    ofDrawBitmapString("Press Space to Create a Cube!", 20, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        ofBoxPrimitive box;
        box.set(sz);
        box.setPosition(ofRandom(ofGetWidth()*-0.5, ofGetWidth()*0.5),
                        ofRandom(ofGetHeight()*-0.5, ofGetHeight()*0.5),
                                 ofRandom(-100, 100));
        boxes.push_back(box);
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
