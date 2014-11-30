//
//  RunnerApplication.h
//  Garfield
//  This application tests out matrix transformations
//
//  Created by Max Dumas on 11/30/14.
//  Copyright (c) 2014 Max Dumas. All rights reserved.
//

#ifndef __Garfield__RunnerApplication__
#define __Garfield__RunnerApplication__

#include <stdio.h>
#include "GarfieldApplication.h"

class RunnerApplication : public GarfieldApplication
{
private:
    V2 cursor = {0};
    
    void moveTo(const V3 &v);
    
    void lineTo(const V3 &v);
protected:
    
    void create();
    
    // Called to render content into buffer.
    void render();
    
    // Destroy application, called by destructor, don't call manually.
    void destroy();
};

#endif /* defined(__Garfield__RunnerApplication__) */
