#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "output_functions.h"



int main()
{
    Circle c(3); 
    printParams(&c);

    Rectangle r(2,3);
    printParams(&r);

    Triangle t(3,4,5); 
    printParams(&t);

    return 0;   
}