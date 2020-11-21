#pragma once

#include "ofMain.h"
#include "Clock.hpp"
#include "Dot.hpp"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void recursive_draw(Clock &clock, int depth, double* color);
    void recursive_draw();

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
    
    bool state = true;
    bool control = false;
    Clock clock = Clock(ofGetWidth()/2, ofGetHeight()/2);
    ofImage img;
};
