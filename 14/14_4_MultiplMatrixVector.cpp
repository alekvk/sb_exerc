#include <iostream>
#include <vector>

template <typename Term> 
void FillMatrix(Term matr[][4]);

template <typename Term> 
void FillArray(Term arr[]);

template <typename Term> 
void PrintMatrix(Term arr[][4]);

template <typename Term>
void PrintArray(Term arr[]); 

template <typename Term, typename Term_>
std::vector<float> MultiplMatrixVector(Term matr[][4], Term_ arr[]);


               
int main() {

    float a[4][4], v[4];  
    
    std::cout<<"Matrix A.";  FillMatrix(a);
    std::cout<<"Vector V.";  FillArray(v);

    PrintMatrix(a); 
    PrintArray(v); 

    std::vector<float> mult = MultiplMatrixVector(a, v);
 
    std::cout<<"\nThe product of matrix A by vector V:\n";  
    for (auto i : mult)
        std::cout<<i<<" "; 

    return 0;     
    
}





template <typename Term> 
void FillArray(Term arr[]) {

    std::cout<<"\nFilling in the array:\n";

    for (int i = 0; i < 4; ++i) {
        std::cout<<"Enter element with index "<<i<<":  ";
        std::cin>>arr[i];
    }
}     
    

template <typename Term> 
void FillMatrix(Term matr[][4]) {

    std::cout<<"\nFilling in the matrix:\n";

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout<<"Enter into row "<<i<<" column "<<j<<":  ";
            std::cin>>matr[i][j];
        } 
            

    }     
    

}


template <typename Term>
void PrintMatrix(Term matr[][4]) {

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) 
            std::cout<<matr[i][j]<<"  ";
        std::cout<<"\n";    
    }

    std::cout<<"\n";   
}

template <typename Term>
void PrintArray(Term arr[]) {

    for (int i = 0; i < 4; ++i) {
        std::cout<<arr[i]<<"  ";
    }

    std::cout<<"\n";   
}



template <typename Term, typename Term_ >
std::vector<float> MultiplMatrixVector(Term matr[][4], Term_ arr[]) {
    std::vector<float> mult(4);
    float sum;

    for (int i = 0; i < 4; ++i) {
        sum = 0;
        for(int j = 0; j < 4; ++j) {
            sum += matr[i][j] * arr[j]; 
        }
        mult[i] = sum; 
    }

    return mult;
} 



