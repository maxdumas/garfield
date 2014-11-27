//
//  Matrix4.h
//  Garfield
//
//  Created by Max Dumas on 11/26/14.
//  Copyright (c) 2014 Max Dumas. All rights reserved.
//

#ifndef __Garfield__Matrix4__
#define __Garfield__Matrix4__

#include <stdio.h>
#include "V3.h"

class Matrix4
{
    constexpr static const float ident[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    
    float values[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    
    void mult(Matrix4 &other);
    
public:
    Matrix4() {};
    
    void set(unsigned char r, unsigned char c, float v);
    float get (unsigned char r, unsigned char c);
    
    Matrix4* identity();
    Matrix4* translate(float a, float b, float c);
    Matrix4* rotateX(float a);
    Matrix4* rotateY(float a);
    Matrix4* rotateZ(float a);
    Matrix4* scale(float a);
    Matrix4* scale(float a, float b, float c);
    
    V3 transform(V3 &p);
};

#endif /* defined(__Garfield__Matrix4__) */
