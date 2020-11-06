#pragma once

#include "ofMain.h"

class Ball{
public:
    Ball(){}
    ~Ball(){}
    
    bool left = true;
    bool up = true;
    double energy;
    double posx, posy;
    double vx = 0, vy = 0;
    double radius = 30;
    ofColor color = ofColor::grey;
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
        Ball ball;
		
};
