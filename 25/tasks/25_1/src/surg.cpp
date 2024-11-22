#include "surg.h"
#include "custom_types.h"
#include <iostream>

point GetCoord() {

    double x,y;

    std::cout<<"Enter the coordinate X of the point: ";
    std::cin>>x;
    std::cout<<"Enter the coordinate Y of the point: ";
    std::cin>>y;

    return {x,y};
}

bool EqualPoints(point p1, point p2) {

    if (p1.x != p2.x) return false;
    if (p1.y != p2.y) return false;
    return true;
}

