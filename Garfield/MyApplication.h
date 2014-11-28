//
//  MyApplication.h
//  Garfield
//
//  Created by Max Dumas on 11/23/14.
//  Copyright (c) 2014 Max Dumas. All rights reserved.
//

#ifndef __Garfield__MyApplication__
#define __Garfield__MyApplication__

#include <stdio.h>
#include "GarfieldApplication.h"

struct Point : public V3
{
    Point() : V3(0), v(0), c(0) {}
    
    V3 v;
    Color c;
};

class MyApplication : public GarfieldApplication
{
protected:
    constexpr static const int N_PARTICLES = 1000;
    
    Point pts[N_PARTICLES];
    
    void create();
    
    void render();
    
    void destroy();
    
    void updatePoint(Point &p);
};

#endif /* defined(__Garfield__MyApplication__) */
