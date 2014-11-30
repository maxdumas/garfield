//
//  RunnerApplication.cpp
//  Garfield
//
//  Created by Max Dumas on 11/30/14.
//  Copyright (c) 2014 Max Dumas. All rights reserved.
//

#include "RunnerApplication.h"
#include <cmath>

#define PI 3.14159f

void RunnerApplication::moveTo(const V3 &v)
{
    cursor = fromViewPort(getTransform()->transform(v));
}

void RunnerApplication::lineTo(const V3 &v)
{
    V2 q = fromViewPort(getTransform()->transform(v));
    line(cursor, q);
    cursor = q;
}

void RunnerApplication::create()
{
    
}

void RunnerApplication::render()
{
    clear({0x00});
    setFillColor({0xff, 0x00, 0x00});
    Matrix4 *m = getTransform();
    
    float turnAngle = sinf(getSecs()) * PI / 4.f;
    
    int side0 = turnAngle > 0 ? 0 : 1;
    int side1 = turnAngle > 0 ? 2 : -1;
    int dside = turnAngle > 0 ? 1 : -1;
    for(int side = side0; side != side1; side += dside)
    {
        int sign = side == 0 ? -1 : 1;
        
        float theta = 8.f * getSecs() + PI * side;
        float bend = .3f + .3f * sinf(theta) - .2f;
        float bund = .3f + .3f * cosf(theta);
        
        m->identity();
        m->rotateY(PI / 2.f + turnAngle);
        
        moveTo({0});                    // HIP
        m->translate(0, 0.1f * bund, 0.1f * sign);
        lineTo({0});
        
        m->rotateZ(2.5f * bend);
        m->translate(0, -.5, 0);
        lineTo({0});                    // KNEE
        
        m->rotateZ(-2 * bund);
        m->translate(0, -0.5, 0);
        lineTo({0});                    // ANKLE
        
        m->rotateZ(-bend);
        m->translate(.2, 0, 0);
        lineTo({0});                    // TOE
    }
}

void RunnerApplication::destroy()
{
    
}