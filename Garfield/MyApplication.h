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

class MyApplication : public GarfieldApplication
{
protected:
    void create();
    
    void render();
    
    void destroy();
};

#endif /* defined(__Garfield__MyApplication__) */
