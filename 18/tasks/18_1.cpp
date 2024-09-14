#include <iostream>
#include <vector>


template <typename Term>
void PrintConteiner(Term* p, int size = 4); 

template <typename Term>
void Swapvec(Term* p1, Term* p2, int size = 4) {
        
    for (int i = 0; i < size; ++i) {
        Term term = *(p1 + i);
        *(p1 + i) = *(p2 + i);
        *(p2 + i) = term;
    }
}

              
int main() {
        
    std::vector<int> a = {1,2,3,4};
    int b[] = {2,4,6,8};
   
    PrintConteiner(&a[0]);
    PrintConteiner(b);

    Swapvec(&a[0], b);
    std::cout << std::endl;

    PrintConteiner(&a[0]);
    PrintConteiner(b);
    
    return 0;
}





template <typename Term>
void PrintConteiner(Term* p, int size) {

    for (int i = 0; i < size; ++i) 
        std::cout<<*(p + i)<<" ";
    
    std::cout<<"\n";
}

