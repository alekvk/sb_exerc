#pragma once
#include <iostream>
#include "shape.h"
#include "global_types.h"
#include <cmath>


class Triangle : public Shape
{
public:
    Triangle(float in_a, float in_b, float in_c);

    double square() override; 
    BoundingBoxDimensions dimensions() override; 
    std::string type() override; 
    
private:
    const std::string type_shape = "Triangle";
    float a;
    float b;
    float c; 
    float p;
};