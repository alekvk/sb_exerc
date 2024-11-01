#include <iostream>

#define SPRING 0
#define SUMMER 0
#define AUTUMN 1
#define WINTER 0

#if SPRING == 1
    #define SEASON "spring"
#elif SUMMER == 1
    #define SEASON "summer"
#elif AUTUMN == 1
    #define SEASON "autumn"      
#elif WINTER == 1
    #define SEASON "winter" 
#endif

 
int main() {
    
    std::cout << SEASON;
    return 0;
}
