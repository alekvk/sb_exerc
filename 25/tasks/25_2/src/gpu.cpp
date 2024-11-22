#include "gpu.h"


void Read() {

    if(!is_buffer) {
        std::cout<<"The buffer is not full\n";
        return;
    }

    for (int i = 0; i < size_buffer; ++i) {
        std::cout<<"\nNumber "<< i + 1 <<": ";
        std::cout<<buffer[i];
    }

    std::cout<<std::endl;
}