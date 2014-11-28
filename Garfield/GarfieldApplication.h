//
//  GarfieldApplication.h
//  Garfield
//
//  Created by Max Dumas on 11/23/14.
//  Copyright (c) 2014 Max Dumas. All rights reserved.
//

#ifndef __Garfield__GarfieldApplication__
#define __Garfield__GarfieldApplication__

#include <stdio.h>
#include <stack>
#include <SDL2/SDL.h>
#include "V3.h"
#include "V2.h"
#include "Matrix4.h"
#include "Color.h"

class GarfieldApplication
{
public:
    GarfieldApplication();
    
    // Application state (just convenience instead of 0, 1, ...).
    enum APP_STATE
    {
        APP_OK = 0,
        APP_FAILED = 1
    };
    
    // Run application, called by your code.
    APP_STATE run(ushort width, ushort height, const char *title);

private:
    // Initialize application, called by run(), don't call manually.
    APP_STATE init(ushort width, ushort height, const char *title);
    
    // Called to process SDL event.
    void onEvent(SDL_Event *ev);
    
    void dispose();
    
    // Whether the application is in event loop.
    bool _running;
    ushort width, height;
    SDL_Window *win;
    SDL_Renderer *renderer;
    Matrix4 tMat;
    
    uint currentTime = 0;
    uint lastTime = 0;
    SDL_Rect primaryRect;
    Color fillColor{0x00};
    V2 lastMouse{0}, currentMouse{0};
    
protected:
    ////// PRIMARY METHODS //////
    
    ~GarfieldApplication();
    
    // Called once to initialize custom user stuff
    virtual void create() = 0;
    
    // Called to render content into buffer.
    virtual void render() = 0;
    
    // Destroy application, called by destructor, don't call manually.
    virtual void destroy() = 0;
    
    ////// AUXILIARY METHODS //////
    
    // Converts a vector in viewport coordinates into a new vector in screen space coordinates
    V2 fromViewPort(const V3 &v);
    
    uint getWidth();
    uint getHeight();
    
    Matrix4* getTransform();
    
    uint getTime();
    uint getDeltaTime();
    
    V2 getMouse();
    V2 getDeltaMouse();
    
    void setFillColor(const Color &c);
    const Color& getFillColor() const;
    
    float random();
    float random(float low, float high);
    
    ////// DRAWING METHODS //////
    
    void clear(const Color &c);
    void clear(); // This clears using the current color
    
    void rect(float x, float y, float w, float h);
    void rect(const V3 &bl, const V3 &tr);
    
    void line(const V3 &start, const V3 &end);
    
    void point(const V3 &p);
};

#endif /* defined(__Garfield__GarfieldApplication__) */
