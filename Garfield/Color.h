//
//  Color.h
//  Garfield
//
//  Created by Max Dumas on 11/26/14.
//  Copyright (c) 2014 Max Dumas. All rights reserved.
//

#ifndef __Garfield__Color__
#define __Garfield__Color__

#include <stdio.h>
#include <SDL2/SDL.h>

class Color
{
public:
    uint8_t r, g, b, a;
    
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {};
    Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b), a(0xff) {};
    Color(uint8_t x) : r(x), g(x), b(x), a(0xff) {};
    ~Color() {};
};

#endif /* defined(__Garfield__Color__) */
