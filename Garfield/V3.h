//
//  Vector2.h
//  Garfield
//
//  Created by Max Dumas on 11/23/14.
//  Copyright (c) 2014 Max Dumas. All rights reserved.
//

#ifndef __Garfield__Vector3__
#define __Garfield__Vector3__

#include <stdio.h>

class V3
{
public:
    float x, y, z;
    
    V3(float x, float y, float z) : x(x), y(y), z(z) {};
    V3(float x, float y) : x(x), y(y) {};
    V3(float a) : x(a), y(a), z(a) {};
    ~V3() {};
};

#endif /* defined(__Garfield__Vector3__) */
