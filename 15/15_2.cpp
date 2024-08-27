#include <iostream>

              
int main() {

    int a[] = {2, 7, 11, 15};
    int res = 9;
    int sizeArr = sizeof(a)/sizeof(a[0]);

    for (int i = 0; i < sizeArr; ++i) {
            
        for (int j = i + 1; j < sizeArr; ++j) {
            if ((a[i] + a[j]) == res) {
                std::cout<<a[i]<<"  "<<a[j];
                return 0;
            }
        }
    }
       
    std::cout<<"No numbers found"; 
    return 0;
}

