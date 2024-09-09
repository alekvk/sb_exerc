#include <iostream>

void Reverse(int* p, int size); 

void Print(int* p, int size); 


              
int main() {

    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(a)/sizeof(a[0]);
    
    Print(a, size);
    Reverse(a, size);
    Print(a, size);
    
    return 0;
}



void Reverse(int* p, int size) {

    for (int i = 0; i < size/2; ++i) {
        int tmp = *(p + i);
        *(p + i) = *(p + size - 1 - i);
        *(p + size - 1 - i) = tmp;    

    } 
     
}


void Print(int* p, int size) {

    for (int i = 0; i < size; ++i) {
        std::cout<<*(p + i)<<" ";
    }

    std::cout<<"\n";
}