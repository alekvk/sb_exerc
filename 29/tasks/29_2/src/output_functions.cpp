#include "output_functions.h"
#include "global_types.h"


void printParams(Shape *shape)
{ 
    std::cout <<"Type: " << shape->type() <<"\n" 
    <<"Square: "<<shape->square()<<"\n"
    <<"Width: "<<shape->dimensions().width<<"\n"
    <<"Height: "<<shape->dimensions().height<<"\n"<<std::endl;
};