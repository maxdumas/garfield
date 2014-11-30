//
//  FlurryApplication.cpp
//  Garfield
//
//  Created by Max Dumas on 11/23/14.
//  Copyright (c) 2014 Max Dumas. All rights reserved.
//

#include <cmath>
#include "Matrix4.h"
#include "FlurryApplication.h"

inline void FlurryApplication::setOccupationMap(Point &p, const bool b) const
{
    occupationMap[static_cast<int>(p.y)][static_cast<int>(p.x)] = b;
}

inline const bool FlurryApplication::getOccupationMap(Point &p) const
{
    return occupationMap[static_cast<int>(p.y)][static_cast<int>(p.x)];
}

void FlurryApplication::updatePoint(Point &p)
{
    setOccupationMap(p, false); // We're gonna move out of the old position, so set it as unoccupied
    p.x = fmodf((p.x + p.v.x), getWidth());
    if(p.x < 0) p.x = getWidth() - 1.f;
    p.y = fmodf(p.y + p.v.y, getHeight());
    if(p.y < 0) p.y = getHeight() - 1.f;
    
    if(getOccupationMap(p)) // If our new position is already occupied...
    { // Give us a random velocity, because we don't want to be rude!
//        p.v.x = -1.f + 2.f * random();
//        p.v.y = -1.f + 2.f * random();
        
        p.x = fmodf((p.x + (-1.f + 2.f * random())), getWidth());
        if(p.x < 0) p.x = getWidth() - 1.f;
        p.y = fmodf(p.y + (-1.f + 2.f * random()), getHeight());
        if(p.y < 0) p.y = getHeight() - 1.f;
    }
    else setOccupationMap(p, true); // Otherwise set new position as occupied
    
    p.v.x *= 0.95;
    p.v.y *= 0.95;
    
    p.c.g = 255 / (1 + abs(p.v.x));
    p.c.b = 255 / (1 + abs(p.v.y));
}

void FlurryApplication::create()
{
    printf("App created with width %d and height %d.\n", getWidth(), getHeight());
    occupationMap = new bool*[getHeight()];
    for(uint i = 0; i < getHeight(); ++i)
        occupationMap[i] = new bool[getWidth()];
    
    for(uint i = 0; i < N_PARTICLES; ++i)
    {
        pts[i].x = random() * getWidth();
        pts[i].y = random() * getHeight();
        pts[i].c = {0xff, 0xff, 0xff};
        pts[i].v = {0, 0};
        
        setOccupationMap(pts[i], true);
    }
}

void FlurryApplication::render()
{
    // TODO: Add pushing/popping current matrix state
    // Figure out how to/if to separate stroke and fill colors
    // Start trying to port examples!
    
    getTransform()->identity();
    clear({0x00});
    for(Point &p : pts) {
        updatePoint(p);
        
        if(isMousePressed(ANY_BUTTON)) {
            float q = 10.f / (1.f + (getMouse() - p).length());
            V2 d = getDeltaMouse();
            p.v = V2{(d.x > 5.f ? 5.f : d.x) * q,
                     (d.y > 5.f ? 5.f : d.y) * q}
                + p.v;
        }
        setFillColor(p.c);
        point(p);
    }
}

void FlurryApplication::destroy()
{
    for(uint i = 0; i < getHeight(); ++i)
        delete occupationMap[i];
    delete [] occupationMap;
}