#include <iostream>


int NumberWays(unsigned stages, unsigned next = 0, unsigned max_jump = 3) {

    if (next == stages) return 1;
    int ways = 0; 
   
    for (unsigned jump = 1; jump <= max_jump; ++jump) {
            
        if (next < stages) {
            next += jump;
            ways += NumberWays(stages, next, max_jump);
            next -= jump;
        }
    }

    return ways;
}



int main() {

	unsigned n, k;
    int init_next = 0;

    std::cout<<"Enter the number of stages: ";
    std::cin>>n;
    std::cout<<"Enter the maximum jump value: ";
    std::cin>>k;
    
    printf("Number of ways: %i\n",  NumberWays(n, init_next, k));
    printf("Number of ways (default jump value): %i",
            NumberWays(n, init_next));

    return 0;
   
}

