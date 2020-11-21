//
//  Clock.hpp
//  Midterm Project
//
//  Created by Zeyu Shen on 11/21/20.
//

#ifndef Clock_hpp
#define Clock_hpp

#include "Dot.hpp"

class Clock{
public:

    Clock(double _basex, double _basey);
    Clock(const Clock &clock, int i);
    
    void update1();
    void update2();
    void draw(double* color, double alpha);
    
    vector<Dot> dots;
    //dots[0] is second hand
    //dots[1] is minute hand
    //dots[2] is hour hand
};

#endif /* Clock_hpp */
