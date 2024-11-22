#include "kbd.h"



void Write() {

    for (int i = 0; i < size_buffer; ++i) {
        int n;
        std::cout<<"Enter the number "<< i + 1 <<": ";
        std::cin>>n;
        buffer[i] = n;
    }
    
    is_buffer = true;
}