#include <iostream>

#define SPRING 1
#define SUMMER 0
#define AUTUMN 0
#define WINTER 0

#if SPRING == 1
    int main() {std::cout <<"spring"; return 0;}
#elif SUMMER == 1
    int main() {std::cout <<"summer"; return 0;}
#elif AUTUMN == 1
    int main() {std::cout <<"autumn"; return 0;}      
#elif WINTER == 1
    int main() {std::cout <<"winter"; return 0;}
#endif

 

