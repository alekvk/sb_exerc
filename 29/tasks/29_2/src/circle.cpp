#include "circle.h"


Circle::Circle(float in_radius):
    radius(in_radius)
{}


double Circle::square() 
{
    return PI * radius * radius;  
}


BoundingBoxDimensions Circle::dimensions() 
{
    float side = 2 * radius;
    return {side, side}; 
}


std::string Circle::type()  
{
    return type_shape; 
}