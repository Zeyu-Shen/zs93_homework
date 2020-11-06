#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

    class Ball{
    public:
        Ball(){}
        ~Ball(){}
        
        double posx, posy;
        double vx, vy;
        double ax, ay;
        double radius;
        double mass;
        ofColor color;
    };
    
    class Wind{
    public:
        Wind(){}
        ~Wind(){}
        
        double fx;
        double fy;
    };
    
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
		
        vector<Ball> balls;
        vector<Wind> winds;
};
