//
//  Dot.hpp
//  Midterm Project
//
//  Created by Zeyu Shen on 11/21/20.
//

#ifndef Dot_hpp
#define Dot_hpp

#include "ofMain.h"

class Dot{
public:
    
    Dot(double _len, double _va, double _basex, double _basey);
    void update();
    void draw();
    
    double len;
    double angle;
    double va; //angle velocity
    double px, py; //x-position and y-position
    double basex, basey;
    
    ofColor color;
    
};

#endif 
