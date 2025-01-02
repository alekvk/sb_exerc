#pragma once
#include "global_types.h"
#include <iostream>

class Shape
{
public:
    virtual double square() = 0; 
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual std::string type() = 0;
};