#include "ofApp.h"

void ofApp::setup(){
    
    vid.load("sea.mp4");
    vidShift.allocate(vid.getWidth(), vid.getHeight(), OF_IMAGE_COLOR);
    
    vid.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float time = ofGetElapsedTimef();
    
    vid.update();
    if (vid.isFrameNew())
    {
        float time = ofGetElapsedTimef();
        glm::vec2 mouse = glm::vec2(ofGetMouseX(), ofGetMouseY());
        glm::vec2 mouseNorm = mouse / ofGetWindowSize();    // normalized 0-1
        glm::vec2 vidSize = glm::vec2(vid.getWidth(), vid.getHeight());
        
        for (int i=0; i < vidSize.y; i++){
            for (int j=0; j < vidSize.x; j++){
                glm::vec2 pos = glm::vec2(i,j) / vidSize;
                ofColor color = vid.getPixels().getColor(i,j);
                color[0]=(color[0]+10)%255;
                color[1]=(color[1]+10)%255;
                color[2]=(color[2]+10)%255;
                glm::vec2 offset;
                double brightness = color.getBrightness()/100;
                offset.x = mouseNorm.x*brightness*300;
                offset.y = mouseNorm.y*brightness*300;
                int newX = int(i+offset.x)%int(vid.getWidth());
                int newY = int(j+offset.y)%int(vid.getHeight());
                vidShift.setColor(newX, newY, color);
            }
        }
        vidShift.update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    vidShift.draw(0,0, ofGetWidth(), ofGetHeight());

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
