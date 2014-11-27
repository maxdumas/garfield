//
//  Vector2.h
//  Garfield
//
//  Created by Max Dumas on 11/23/14.
//  Copyright (c) 2014 Max Dumas. All rights reserved.
//

#ifndef __Garfield__Vector2__
#define __Garfield__Vector2__

#include <stdio.h>
#include "V3.h"

class V2
{
public:
    float x, y;
    
    V2(float x, float y) : x(x), y(y) {};
    V2(float a) : x(a), y(a) {};
    V2(V3 &v) : x(v.x), y(v.y) {};
    ~V2() {};
    
    operator V3() { return {x, y, 0}; }
};

#endif /* defined(__Garfield__Vector2__) */
