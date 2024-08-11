#include <iostream>
#include <vector>

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
void PrintConteiner(Conteiner conteiner) {
    
    for(auto i : conteiner) 
        std::cout<<i<<"  ";
    
    std::cout<<"\n";     
}

template <typename Conteiner>
void InsBeginRingBuffer (Conteiner& cont, int n) {

    for (int i = cont.size() - 1; i > 0; --i) 
        cont[i] = cont[i - 1];
    
    cont[0] = n;
}


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
    int endInd = v.size() - 1;
 
    for (int i = size; i > 0; --i) {
        if (v[endInd] != num) { 
            InsBeginRingBuffer(v, v[endInd]);
        } else {
            v.pop_back();
            --endInd;
        }
    }

    std::cout<<"\nResult: ";
    PrintConteiner(v);
  
    return 0;
    
}




