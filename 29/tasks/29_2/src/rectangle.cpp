#include "rectangle.h"


Rectangle:: Rectangle(float in_width, float in_height):
    width(in_width),
    height(in_height)
{}    

double Rectangle::square() 
{
    return width * height;  
}

BoundingBoxDimensions Rectangle::dimensions() 
{
    return {width, height}; 
}

std::string Rectangle::type()  
{
    return type_shape; 
} 
    