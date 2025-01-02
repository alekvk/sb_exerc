#pragma once
#include <iostream>
#include "shape.h"
#include "global_types.h"


class Circle : public Shape
{
public:
    Circle(float in_radius);

    double square() override; 
    BoundingBoxDimensions dimensions() override; 
    std::string type() override; 

private:
    const float PI = 3.14159;
    const std::string type_shape = "Circle";
    float radius;
};