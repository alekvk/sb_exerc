#pragma once
#include <iostream>
#include "shape.h"
#include "global_types.h"

class Rectangle : public Shape
{
public:
    Rectangle(float in_width, float in_height);

    double square() override; 
    BoundingBoxDimensions dimensions() override; 
    std::string type() override; 
    
private:
    const std::string type_shape = "Rectangle";
    float width;
    float height; 
};