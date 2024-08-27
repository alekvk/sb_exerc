#include <iostream>
#include <vector>
#include <algorithm>


template <typename Conteiner>
void PrintConteiner(Conteiner& conteiner); 

template <typename Term>
int FindIndexFirstPositiveNum (Term arr[], int sizeArr); 

              
int main() {

    //int a[] = {-100, -75, -50, -30, -15, -5}; FindIndexFirstPositiveNum return -1
    // int a[] = {5, 10, 15, 30, 50, 100};  FindIndexFirstPositiveNum  return 0

    int a[] = {-100, -50, -15, -5, -1, 1, 5, 16};

    int sizeArr = sizeof(a)/sizeof(a[0]);
    int indexFirstPositive = FindIndexFirstPositiveNum(a, sizeArr);
    std::cout<<"indexFirstPositive: "<<indexFirstPositive<<"\n";

    if (indexFirstPositive == 0) {
        for (int i = 0; i <sizeArr; ++i)
            std::cout<<a[i]<<" "; 
    } else if (indexFirstPositive == -1) {
        for (int i = sizeArr - 1; i >= 0; --i)
            std::cout<<a[i]<<" "; 
    } else {
        int i = indexFirstPositive;
        int j = i - 1;
        while ( i < sizeArr || j >= 0 ) {
            if (  i < sizeArr  &&  (j < 0 || abs(a[i]) <= abs(a[j]) )  ) {
                std::cout<<a[i]<<" ";
                ++i;    
            } else if (  j >= 0  &&  (i == sizeArr || abs(a[j]) < abs(a[i]) )  ) {
                std::cout<<a[j]<<" ";
                --j;    
            } 
        }
    }

    return 0;
}



template <typename Term>
int FindIndexFirstPositiveNum(Term arr[], int sizeArr) {
    
    int index = sizeArr/2;

    if  (arr[index] >= 0) {

        for (int i = index; i > 0; --i) {
            if (arr[i - 1] < 0) return i; 
        }
        return 0; 
    }

    if  (arr[index] < 0) {

        for (int i = index; i < sizeArr - 1; ++i) {
            if (arr[i + 1] >= 0) return i + 1; 
        }
        return -1; 
    }
}




template <typename Conteiner>
void PrintConteiner(Conteiner& conteiner) {
    
    for (auto c : conteiner)
        std::cout<<c<<" ";
    std::cout<<"\n"; 
}