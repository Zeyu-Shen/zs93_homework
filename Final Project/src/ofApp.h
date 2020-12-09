#pragma once

#include "ofMain.h"
#include "Ball.hpp"
#include "Line.hpp"
#include "Particle.hpp"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void gameOver();

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
    bool checkCollision();
    ofTrueTypeFont font;
    ofTrueTypeFont font2;
    ofTrueTypeFont font3;
    
    ofSoundPlayer beat;
    
    vector<Line> lines;
    bool finish = false;
    int cnt = 0;
    float *fftsmooth;
    int bands;
    Ball ball;
    ofSpherePrimitive sphere;
    ofEasyCam cam;
    
    bool start = false;
    vector<bool> z;
    bool begin, loaded, canload;
};
