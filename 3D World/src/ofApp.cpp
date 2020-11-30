#include "ofApp.h"
#define sz 100
int prevmode;
bool update1 = false;
bool update2 = false;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    sphere = ofSpherePrimitive(1000, 50);
    sphere.setPosition(0, 0, 0);
    box.setPosition(0, 0, 0);
    prevmode = mode;
}

//--------------------------------------------------------------
void ofApp::update(){
    sphere.rotateDeg(0.05, glm::vec3(-1, 1, 0));
    box.rotateDeg(0.05, glm::vec3(1, -1,0));
    if (update1){
        if (sphere.getRadius()>100){
            sphere.setRadius(sphere.getRadius()-10);
        }
        else{
            update1 = false;
        }
        if (box.getSize().x<1000){
            box.set(box.getSize().x+10, box.getSize().y+10, box.getSize().z+10);
        }
        else{
            update1 = false;
        }
    }
    if (update2){
        if (sphere.getRadius()<1000){
            sphere.setRadius(sphere.getRadius()+10);
        }
        else{
            update2 = false;
        }
        if (box.getSize().x>100){
            box.set(box.getSize().x-10, box.getSize().y-10, box.getSize().z-10);
        }
        else{
            update2 = false;
        }
    }
    if (mode == 1 && mode != prevmode){
        update1 = true;
    }
    else if (mode == 0 && mode != prevmode){
        update2 = true;
    }
    prevmode = mode;
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofEnableDepthTest();
    ofSetColor(ofColor::purple);
    box.drawWireframe();
    sphere.drawWireframe();
    ofDisableDepthTest();
    cam.end();
    
    // instructions:
    ofDrawBitmapString("Drag or Scroll you mouse to Control the Camera!", 20, 20);
    ofDrawBitmapString("Press Space to Switch Mode!", 20, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        mode = 1-mode;
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
