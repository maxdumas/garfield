//
//  FlurryApplication.h
//  Garfield
//  This application exists mostly as a stress test for basic drawing functions
//  of the framework, and to test mouse behavior.
//
//  Created by Max Dumas on 11/23/14.
//  Copyright (c) 2014 Max Dumas. All rights reserved.
//

#ifndef __Garfield__FlurryApplication__
#define __Garfield__FlurryApplication__

#include <stdio.h>
#include "GarfieldApplication.h"

struct Point : public V3
{
    Point() : V3(0), v(0), c(0) {}
    
    V3 v;
    Color c;
};

class FlurryApplication : public GarfieldApplication
{
protected:
    constexpr static const int N_PARTICLES = 40000;
    
    Point pts[N_PARTICLES];
    
    // Occupation map is used as a position hash to quickly check if 2 particles are occupying the same space
    bool **occupationMap;
    
    void create();
    
    void render();
    
    void destroy();
    
    void updatePoint(Point &p);

    inline void setOccupationMap(Point &p, bool v) const;
    
    inline const bool getOccupationMap(Point &p) const;
};

#endif /* defined(__Garfield__FlurryApplication__) */
