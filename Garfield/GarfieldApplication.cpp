//
//  GarfieldApplication.cpp
//  Garfield
//
//  Created by Max Dumas on 11/23/14.
//  Copyright (c) 2014 Max Dumas. All rights reserved.
//

#include "GarfieldApplication.h"

GarfieldApplication::GarfieldApplication() :
_running(false)
{
}

GarfieldApplication::~GarfieldApplication()
{
    if (win)
    {
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }
}

GarfieldApplication::APP_STATE GarfieldApplication::init(ushort width, ushort height, const char *title)
{
    // Initialize the SDL library.
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
        fprintf(stderr, "SDL_Init() failed: %s\n", SDL_GetError());
        return APP_FAILED;
    }
    
    win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if(!win)
    {
        fprintf(stderr, "SDL failed to create window: %s\n", SDL_GetError());
        return APP_FAILED;
    }
    
    this->width = width;
    this->height = height;
    
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!renderer)
    {
        fprintf(stderr, "SDL failed to create renderer: %s\n", SDL_GetError());
        return APP_FAILED;
    }
    
    srand((unsigned)time(0));
    
    return APP_OK;
}

GarfieldApplication::APP_STATE GarfieldApplication::run(ushort width, ushort height, const char *title)
{
    // Initialize application.
    GarfieldApplication::APP_STATE state = init(width, height, title);
    if (state != APP_OK) return state;
    
    create();
    
    // Enter to the SDL event loop.
    SDL_Event ev;
    _running = true;
    
    while(_running) {
        currentTime = SDL_GetTicks();
        
        int x, y;
        SDL_GetMouseState(&x, &y);
        
        currentMouse = {static_cast<float>(x), static_cast<float>(y)};
        
        while (SDL_PollEvent(&ev))
            onEvent(&ev);
        
        render();
        SDL_RenderPresent(renderer);
        
        if (!_running)
            break;
        
        lastTime = currentTime;
        lastMouse = currentMouse;
    }
    destroy();
    
    return APP_OK;
}

void GarfieldApplication::onEvent(SDL_Event *ev)
{
    switch (ev->type)
    {
        case SDL_QUIT:
            _running = false;
            break;
            
        case SDL_KEYDOWN:
            if (ev->key.keysym.sym == SDLK_ESCAPE)
            {
                _running = false;
            }
    }
}

V2 GarfieldApplication::fromViewPort(const V3 &v)
{
    return {width / 2 * v.x + width / 2, height / 2 - (width / 2) * v.y};
}

uint GarfieldApplication::getWidth()
{
    return width;
}

uint GarfieldApplication::getHeight()
{
    return height;
}

Matrix4* GarfieldApplication::getTransform()
{
    return &tMat;
}

uint GarfieldApplication::getTime()
{
    return currentTime;
}

uint GarfieldApplication::getDeltaTime()
{
    return currentTime - lastTime;
}

V2 GarfieldApplication::getMouse()
{
    return currentMouse;
}

V2 GarfieldApplication::getDeltaMouse()
{
    return currentMouse - lastMouse;
}

void GarfieldApplication::clear(const Color &c)
{
    const Color oldC = getFillColor();
    setFillColor(c);
    clear();
    setFillColor(oldC);
}

void GarfieldApplication::clear()
{
    setFillColor(getFillColor());
    SDL_RenderClear(renderer);
}

void GarfieldApplication::setFillColor(const Color &c)
{
    fillColor = c;
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
}

const Color& GarfieldApplication::getFillColor() const
{
    return fillColor;
}

float GarfieldApplication::random()
{
    return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

float GarfieldApplication::random(float low, float high)
{
    return low + (high - low) * random();
}

void GarfieldApplication::rect(float x, float y, float w, float h)
{
    primaryRect.x = x;
    primaryRect.y = y;
    primaryRect.w = w;
    primaryRect.h = h;
    
    SDL_RenderFillRect(renderer, &primaryRect);
}

void GarfieldApplication::rect(const V3 &bl, const V3 &tr)
{
    primaryRect.x = bl.x;
    primaryRect.y = bl.y;
    primaryRect.w = tr.x - bl.x;
    primaryRect.h = tr.y - bl.y;
    
    SDL_RenderFillRect(renderer, &primaryRect);
}

void GarfieldApplication::line(const V3 &start, const V3 &end)
{
    SDL_RenderDrawLine(renderer, start.x, start.y, end.x, end.y);
}

void GarfieldApplication::point(const V3 &p)
{
    SDL_RenderDrawPoint(renderer, p.x, p.y);
}