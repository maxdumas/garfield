//
//  MyApplication.cpp
//  Garfield
//
//  Created by Max Dumas on 11/23/14.
//  Copyright (c) 2014 Max Dumas. All rights reserved.
//

#include <cmath>
#include "Matrix4.h"
#include "MyApplication.h"

void MyApplication::create()
{
    printf("Hello, world! I am run once after the program has successfully initialized!\n");
}

void MyApplication::render()
{
    // TODO: Add pushing/popping current matrix state
    // Figure out how to/if to separate stroke and fill colors
    // Start trying to port examples!
    
    getTransform()->identity();
    clear({0x00});
    setFillColor({0xff, 0xff, 0xff, 0xff});
    rect(200, 200, 200, 200);
    rect(100, 300, 200, 200);
    line({100 + 100 * sinf(getTime() / (float)1000), 0}, {50, 50});
    
    V3 v = {25, 125};
    v = getTransform()->rotateZ(sinf(getTime() / (float)1000))->transform(v);
    point(v);
}

void MyApplication::destroy()
{
    printf("I am run once when the application is closing.");
}