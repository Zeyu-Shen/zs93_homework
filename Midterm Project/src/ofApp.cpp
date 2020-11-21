#include "ofApp.h"
#include "cmath"
#define maxdepth 11
#define ColorAdjustment 0.85
vector<double> alpha(maxdepth+1);

void ofApp::recursive_draw(Clock &curr, int depth, double *color){
    curr.draw(color, alpha[maxdepth-depth]);
    Clock curr0 = Clock(curr, 0);
    Clock curr1 = Clock(curr, 1);
    if (depth){
        double newcolor[3];
        newcolor[1] = 0.92*color[1];
        newcolor[0] = ColorAdjustment*color[0];
        newcolor[2] = 0.1*255+ColorAdjustment*color[2];
        recursive_draw(curr0, depth-1, newcolor);
        
        newcolor[1] = 0.92*color[1];
        newcolor[0] = 0.1*255+ColorAdjustment*color[0];
        newcolor[2] = ColorAdjustment*color[2];
        recursive_draw(curr1, depth-1, newcolor);
    }
}

void ofApp::recursive_draw(){
    double color[3];
    color[0] = color[1] = color[2] = 255;
    recursive_draw(clock, maxdepth, color);
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    for (int i=0; i<maxdepth+1; i++){
        alpha[i] = 255.0/(pow(i+1, 1.2));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if (control){
        clock.update2();
    }
    else if (state){
        clock.update1();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    ofFill();
    ofDrawBitmapString("Press 'm' to Stop the Clock", 15, 15);
    ofDrawBitmapString("Press 'x' to Get Screenshot", 15, 30);
    ofDrawBitmapString("Press 's' to Control the Clock with Mouse", 15, 45);
    ofNoFill();
    recursive_draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'm'){
        state = !state;
    }
    if (key == 'x'){
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        img.save("screenshot.png");
    }
    if (key == 's'){
        control = !control;
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
