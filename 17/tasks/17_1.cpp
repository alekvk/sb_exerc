#include <iostream>

void swap(int* p1, int* p2) {

    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp; 
}

             
int main() {

    int a = 10;
    int b = 20;
    swap(&a, &b);

    // 20 10
    std::cout << a << " " << b;

    return 0;
}
