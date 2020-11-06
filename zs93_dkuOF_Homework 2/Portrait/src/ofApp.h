#pragma once

#include "ofMain.h"

class Portrait{
public:
    Portrait(){};
    ~Portrait(){};
    
    void update(ofVec3f target);
    
    double lerp1 = 0.3, lerp2 = 0.25, lerp3 = 0.2, lerp4 = 0.15, lerp5 = 0.1, lerp6 = 0.05;
    
    ofVec3f head_center;
    double head_radius;
    ofVec3f body_bottom;
    ofVec3f left_hand;
    ofVec3f right_hand;
    ofVec3f left_foot;
    ofVec3f right_foot;
    
    ofColor color = ofColor::white;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        Portrait me;
};
