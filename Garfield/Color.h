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

class Color
{
public:
    unsigned short r, g, b, a;
    
    Color(unsigned short r, unsigned short g, unsigned short b, unsigned short a) : r(r), g(g), b(b), a(a) {};
    Color(char r, char g, char b) : r(r), g(g), b(b), a(0xff) {};
    Color(char x) : r(x), g(x), b(x), a(0xff) {};
    ~Color() {};
};

#endif /* defined(__Garfield__Color__) */
