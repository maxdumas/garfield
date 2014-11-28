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

void MyApplication::updatePoint(Point &p)
{
    p.x = modff((p.x + p.v.x) / getWidth(), nullptr); // E_BADACES, should probably find a better way to do this
    if(p.x < 0) p.x = getWidth();
    p.y = modff(p.y + p.v.y / getHeight(), nullptr);
    if(p.y < 0) p.y = getHeight();
    
    p.v.x *= 0.99;
    p.v.y *= 0.99;
    
    p.c.g = 255 / (1 + abs(p.v.x));
    p.c.b = 255 / (1 + abs(p.v.y));
}

void MyApplication::create()
{
    for(uint i = 0; i < N_PARTICLES; ++i)
    {
        pts[i].x = random() * getWidth();
        pts[i].y = random() * getHeight();
        pts[i].c = {0xff, 0xff, 0xff};
        pts[i].v = {0, 0};
    }
}

void MyApplication::render()
{
    // TODO: Add pushing/popping current matrix state
    // Figure out how to/if to separate stroke and fill colors
    // Start trying to port examples!
    int mx, my;
    SDL_GetMouseState(&mx, &my);
    
    getTransform()->identity();
    clear({0x00});
    for(Point &p : pts) {
        updatePoint(p);
        
        setFillColor(p.c);
        p.v.x = 1 / (1 + (getMouse().x - p.x));
        point(p);
    }
}

void MyApplication::destroy()
{
    printf("I am run once when the application is closing.");
}