//
//  Matrix4.cpp
//  Garfield
//
//  Created by Max Dumas on 11/26/14.
//  Copyright (c) 2014 Max Dumas. All rights reserved.
//

#include "Matrix4.h"
#include <cmath>

constexpr const float Matrix4::ident[4][4];

void Matrix4::set(unsigned char r, unsigned char c, float v)
{
    values[r][c] = v;
}

float Matrix4::get(unsigned char r, unsigned char c)
{
    return values[r][c];
}

Matrix4* Matrix4::identity()
{
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            values[i][j] = ident[i][j];
    
    return this;
}

void Matrix4::mult(Matrix4 &other)
{
    for(int i = 0; i < 4; ++i) {
        float row[4];
        for(int j = 0; j < 4; ++j) {
            float sum = 0;
            for(int k = 0; k < 4; ++k)
                sum += get(i, k) * other.get(k, j);
            row[j] = sum;
        }
        for(int j = 0; j < 4; ++j)
            values[i][j] = row[j];
    }
}

Matrix4* Matrix4::translate(float a, float b, float c)
{
    Matrix4 mat;
    mat.set(0, 3, a);
    mat.set(1, 3, b);
    mat.set(2, 3, c);
    
    mult(mat);
    
    return this;
}

Matrix4* Matrix4::rotateX(float a)
{
    Matrix4 mat;
    float sin = sinf(a);
    float cos = cosf(a);
    mat.set(1, 1, cos);
    mat.set(1, 2, -sin);
    mat.set(2, 1, sin);
    mat.set(2, 2, cos);
    
    mult(mat);
    
    return this;
}

Matrix4* Matrix4::rotateY(float a)
{
    Matrix4 mat;
    float sin = sinf(a);
    float cos = cosf(a);
    mat.set(0, 0, cos);
    mat.set(0, 2, sin);
    mat.set(2, 0, -sin);
    mat.set(2, 2, cos);
    
    mult(mat);
    
    return this;
}

Matrix4* Matrix4::rotateZ(float a)
{
    Matrix4 mat;
    float sin = sinf(a);
    float cos = cosf(a);
    mat.set(0, 0, cos);
    mat.set(0, 1, -sin);
    mat.set(1, 0, sin);
    mat.set(1, 1, cos);
    
    mult(mat);
    
    return this;
}

Matrix4* Matrix4::scale(float a)
{
    Matrix4 mat;
    
    mat.set(0, 0, a);
    mat.set(1, 1, a);
    mat.set(2, 2, a);
    mat.set(3, 3, 1);
    
    mult(mat);
    
    return this;
}

Matrix4* Matrix4::scale(float a, float b, float c)
{
    Matrix4 mat;
    
    mat.set(0, 0, a);
    mat.set(1, 1, b);
    mat.set(2, 2, c);
    mat.set(3, 3, 1);
    
    mult(mat);
    
    return this;
}

V3 Matrix4::transform(const V3 &p)
{
    float point[4] = {p.x, p.y, p.z, 1};
    float newPoint[4] = {0, 0, 0, 0};
    
    for(int i = 0; i < 4; ++i) {
        float sum = 0;
        for(int k = 0; k < 4; ++k)
            sum += get(i, k) * point[k];
        newPoint[i] = sum;
    }
    return V3(newPoint[0], newPoint[1], newPoint[2]);
}