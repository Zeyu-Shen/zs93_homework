//
//  Clock.cpp
//  Midterm Project
//
//  Created by Zeyu Shen on 11/21/20.
//

#include "Clock.hpp"
#include "cmath"

Clock::Clock(double _basex, double _basey){
    Dot d1 = Dot(100, M_PI/480, _basex, _basey);
    Dot d2 = Dot(80, M_PI/28800, _basex, _basey);
    Dot d3 = Dot(40, M_PI/691200, _basex, _basey);
    dots.push_back(d1);
    dots.push_back(d2);
    dots.push_back(d3);
}

Clock::Clock(const Clock &clock, int i){
    double bx = clock.dots[i].basex+clock.dots[i].len*cos(clock.dots[i].angle);
    double by = clock.dots[i].basey+clock.dots[i].len*sin(clock.dots[i].angle);
    double diff_angle_13 = clock.dots[2].angle-clock.dots[0].angle;
    double diff_angle_23 = clock.dots[2].angle-clock.dots[1].angle;
    vector<Dot> tmp;
    for (int j=0; j<clock.dots.size(); j++){
        Dot d = clock.dots[j];
        d.basex = bx;
        d.basey = by;
        tmp.push_back(d);
    }
    tmp[2].angle = clock.dots[i].angle+M_PI;
    tmp[0].angle = tmp[2].angle-diff_angle_13;
    tmp[1].angle = tmp[2].angle-diff_angle_23;
    for (int j=0; j<3; j++){
        tmp[j].px = tmp[j].basex+tmp[j].len*cos(tmp[j].angle);
        tmp[j].py = tmp[j].basey+tmp[j].len*sin(tmp[j].angle);
    }
    dots = tmp;
}

void Clock::update1(){
    for (int i=0; i<dots.size(); i++){
        dots[i].update();
    }
}

void Clock::update2(){
    double xpos = ofGetMouseX();
    double ypos = ofGetMouseY();
    double angle = atan2(ypos-ofGetHeight()/2, xpos-ofGetWidth()/2);
    double xpos_prev = dots[0].px;
    double ypos_prev = dots[0].py;
    double angle_prev = atan2(ypos_prev-ofGetHeight()/2, xpos_prev-ofGetWidth()/2);
    if (abs(angle-angle_prev)<0.01) return;
    double da = angle-dots[0].angle;
    while(da<0){
        da+=(2*M_PI);
    }
    for (int i=0; i<dots.size(); i++){
        dots[i].angle += da*pow(1.0/60, i);
        dots[i].px = dots[i].basex+dots[i].len*cos(dots[i].angle);
        dots[i].py = dots[i].basey+dots[i].len*sin(dots[i].angle);
    }
}

void Clock::draw(double *color, double alpha){
    ofEnableAlphaBlending();
    ofSetColor(color[0], color[1], color[2], alpha);
    ofFill();
    for (int i=0; i<dots.size(); i++){
        dots[i].draw();
    }
    ofDisableAlphaBlending();
    ofNoFill();
}
