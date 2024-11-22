#include "cpu.h"


void Compute() {

    if(!is_buffer) {
        std::cout<<"The buffer is not full\n";
        return;
    }

    int sum = 0;
    
    for(int i = 0; i < size_buffer; ++i)
        sum += buffer[i];

    std::cout<<"\nThe sum of the buffer numbers:  "
    <<sum<<std::endl;   
}

