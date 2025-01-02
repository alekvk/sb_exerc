#include "triangle.h"

Triangle::Triangle(float in_a, float in_b, float in_c):
    a(in_a), b(in_b), c(in_c)
{ p = (a + b + c) / 2; }    


double Triangle::square() 
{
    return sqrt(p*(p - a)*(p - b)*(p - c));
}

BoundingBoxDimensions Triangle::dimensions() 
{
    float rad_circ = a * b * c / (4 * sqrt(p*(p - a)*(p - b)*(p - c)));
    rad_circ *= 2; 
    return {rad_circ, rad_circ}; 
}

std::string Triangle::type()  
{
    return type_shape; 
}     