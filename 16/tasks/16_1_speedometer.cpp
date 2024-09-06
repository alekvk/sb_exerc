#include <iostream>
#include <stdio.h>

double MAX_SPEED = 150.0;
double EPSILON = 0.01;

double CalculateSpeed(double speed, double delta); 


              
int main() {

    double speed = 0, delta;
    char speed_str[6];
    bool start = false;

    do {
        std::cout<<"Speed delta: ";
        std::cin>>delta;
        speed = CalculateSpeed(speed, delta);
        sprintf(speed_str, "%.1f", speed);
        printf("Speed: %s\n", speed_str);
        if (speed > EPSILON)
            start = true;
        
    } while (!start || (start && speed > EPSILON));

    std::cout<<"\nThe car is stopped\n";

    return 0;

}






double CalculateSpeed(double speed, double delta) {
       
    if (speed + delta <= EPSILON)
        return 0.0;
    else if (MAX_SPEED - speed - delta <= EPSILON)
        return 150.0;
    else return  speed + delta;    

}







