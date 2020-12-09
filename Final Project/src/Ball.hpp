//
//  Ball.hpp
//  Final Project
//
//  Created by Zeyu Shen on 12/9/20.
//

#include "ofMain.h"

class Ball{
    
public:
    
    Ball();
    
    void update();
    bool update_left;
    bool update_right;
    void draw();
    void click_update();
    
    double radius;
    double x, y, z;
    double dirY, aY = 0.4;
    double dirX = 2;
    
    ofColor color;
};
