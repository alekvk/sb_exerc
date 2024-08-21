#include <iostream>
#include <vector>

std::vector<int> FillVectorInt(int size);

template <typename Conteiner>
void PrintConteiner(Conteiner& conteiner); 

template <typename Conteiner, typename Term>
void Erase(Conteiner& cont, Term t); 



int main() {
    
    std::cout<<"\nInput vector size: ";
    int size;
    std::cin>>size;
    std::vector<int> v = FillVectorInt(size);
    std::cout<<"\nVector  content: ";
    PrintConteiner(v);
    
    std::cout<<"\nInput number to delete: ";
    int num;
    std::cin>>num;
    Erase(v, num); 
    std::cout<<"\nResult: ";
    PrintConteiner(v);
  
    return 0;
    
}


std::vector<int> FillVectorInt(int size) {

    std::vector<int> v;
    std::cout<<"\nFilling a vector with numbers\n";

    for(int i = 0; i < size; ++i) {
        std::cout<<"Input numbers:  ";
        int n; 
        std::cin>>n;
        v.push_back(n);
    }    

    return v;     
}



template <typename Conteiner>
void PrintConteiner(Conteiner& conteiner) {
    
    for(auto i : conteiner) 
        std::cout<<i<<"  ";
    
    std::cout<<"\n";     
}


template <typename Conteiner, typename Term>
void Erase(Conteiner& cont, Term t) {

    for (int i = cont.size() - 1; i >= 0; --i) {
        if (cont[i] == t) {

            for (int j = i; j < cont.size() - 1; ++j) 
                cont[j] = cont[j + 1];
            
            cont.pop_back();
        }
    }     

} 





