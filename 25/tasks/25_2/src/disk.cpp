#include "disk.h"


const char* path = "data.txt";

void Save(){

    if(!is_buffer) {
        std::cout<<"The buffer is not full\n";
        return;
    }

    std::ofstream file(path);

    for (int i = 0; i < size_buffer; ++i) 
        file<<buffer[i]<<"\n";
    
    file.close();
}


void Load(){

    std::ifstream file(path);
    int n; 
    
    if(!file.is_open()){
        std::cout<<"\nThere is no data on the disk!\n";
        return;    
    }
   
    for (int i = 0; i < size_buffer; ++i) {
        file>>n;
        buffer[i] = n;
    }

    file.close();
    is_buffer = true;
}
