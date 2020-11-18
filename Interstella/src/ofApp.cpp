#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::peachPuff);
    int h = ofGetHeight()/2;
    int w = ofGetWidth()/2;
    balls.push_back(Ball(vec2(w+150, h+150), 25));
    balls.push_back(Ball(vec2(w-150, h-150), 25));
    balls.push_back(Ball(vec2(w-150, h+150), 25));
    balls.push_back(Ball(vec2(w, h), 5));
    font.load("Iron.ttf", 90);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (!finish){
        for (int i=0; i<balls.size(); i++){
            for(int j=i+1; j<balls.size(); j++){
                double d = length(balls[i].pos-balls[j].pos);
                double f;
                if (d >=50) f = balls[i].m*balls[j].m/(d*d*d);
                else if (i != 3 && j != 3) f = -0.01;
                vec2 f1, f2;
                if (i == 3) f1 = -(balls[i].pos-balls[j].pos)*f*10;
                else f1 = -(balls[i].pos-balls[j].pos)*f*100;
                if (j == 3) f2 = -(balls[j].pos-balls[i].pos)*f*10;
                else f2 = -(balls[j].pos-balls[i].pos)*f*100;
                balls[i].applyForce(f1);
                balls[j].applyForce(f2);
                 balls[i].applyDampingForce(balls[i].m*0.01);
                 balls[j].applyDampingForce(balls[j].m*0.01); balls[i].applyElasticForce(balls[i].m*0.01); balls[i].applyElasticForce(balls[j].m*0.01);
                balls[i].update();
                balls[j].update();
            }
        }
        
        //detect collision
        for (int i=0; i<balls.size()-1; i++){
            Ball b1 = balls[i];
            Ball b2 = balls[3];
            double d = length(b1.pos-b2.pos);
            if (d<=b1.m+b2.m){
                finish = true;
            }
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<balls.size(); i++){
        balls[i].draw();
    }
    ofDrawBitmapString("Press w to move up", 15, 15);
    ofDrawBitmapString("Press s to move down", 15, 25);
    ofDrawBitmapString("Press d to move right", 15, 35);
    ofDrawBitmapString("Press a to move left", 15, 45);
    ofDrawBitmapString("Try not to be caught by the Suns!", 15, 55);
    if (finish){
        gameOver();
    }
}

void ofApp::gameOver(){
    font.drawString("Game Over!", ofGetWidth()/2-270, ofGetHeight()/2+30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'w'){
        balls[3].acc.y = -0.5;
    }
    if (key == 's'){
        balls[3].acc.y = 0.5;
    }
    if (key == 'a'){
        balls[3].acc.x = -0.5;
    }
    if (key == 'd'){
        balls[3].acc.x = 0.5;
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
