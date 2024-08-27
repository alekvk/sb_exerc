#include <iostream>

              
int main() {

    int a[] = {-2, 1, -3, 4, -1 ,2 ,1 ,-5 ,4};

    int i1 = 0, i2 = 1;
    int sumMax = a[i1] + a[i2];
    int sizeArr = sizeof(a)/sizeof(a[0]);

    for (int i = 0; i < sizeArr; ++i) {
        
        for (int j = i + 1; j < sizeArr; ++j) {
            int sum = a[i];
            for (int k = i + 1; k <= j; ++k)
                sum +=a[k];

            if (sum > sumMax) {
                    sumMax = sum;
                    i1 = i;
                    i2 = j;
            }
            
        }

    }

    std::cout<<i1<<"  "<<i2;

    return 0;
}





