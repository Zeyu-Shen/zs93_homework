//
//  Line.hpp
//  Final Project
//
//  Created by Zeyu Shen on 12/9/20.
//

#include "ofMain.h"
#include "Particle.hpp"

class Line{
public:
    
    Line();
    
    void update();
    void draw();
    vector<Particle> particles;
    
    double dirZ = -3, Z;
    double dirY = 1.5, Y;
    double radius = 1;
    bool added = false;
    bool updated = false;
    int peak;
    
    ofColor color;
};
