#include <iostream>


template <typename Term> 
void FillArray(Term arr[][4]);

template <typename Term> 
void PrintArray(Term arr[][4]);

template <typename Term> 
bool CompareMatrix(Term arr_1[][4], Term arr_2[][4]);

template <typename Term> 
void ReduceMatrixDiagView(Term arr_1[][4]);


               
int main() {

    int a[4][4], b[4][4];  
    
    std::cout<<"Matrix a.";  FillArray(a);
    std::cout<<"Matrix b.";  FillArray(b);

    std::cout<<"\nOutput matrix a:\n";  PrintArray(a);  
    std::cout<<"\nOutput matrix b:\n";  PrintArray(b);

    if (!CompareMatrix(a, b)) {
        std::cout<<"The matrices are not equal!\n";
        std::cout<<"The program is finished!\n";
        return 0;
    } else {
        std::cout<<"The matrices are equal!\n";
        ReduceMatrixDiagView(a); 
        PrintArray(a);
    }

    return 0; 
    
}


template <typename Term> 
void ReduceMatrixDiagView(Term arr[][4]) {

    for(int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            arr[i][j] = 0;
            arr[j][i] = 0;
        }
    }      
}  

template <typename Term> 
void FillArray(Term arr[][4]) {

    std::cout<<"\nFilling in the matrix:\n";

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout<<"Enter into row "<<i<<" column "<<j<<":  ";
            std::cin>>arr[i][j];
        } 
            

    }     
    

}


template <typename Term>
void PrintArray(Term arr[][4]) {

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) 
            std::cout<<arr[i][j]<<"  ";
        std::cout<<"\n";    
    }

    std::cout<<"\n";   
}




template <typename Term> 
bool CompareMatrix(Term arr_1[][4], Term arr_2[][4]) {

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (arr_1[i][j] != arr_2[i][j]) return false;
        }
    }

    return true;
}


