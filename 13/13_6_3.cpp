#include <iostream>
#include <vector>


template <typename Conteiner>
void RingBuffer(Conteiner& cont, int n) {

    for (int i = 0; i < cont.size() - 1; ++i) 
        cont[i] = cont [i + 1];
    
    cont[cont.size() - 1] = n;
     
}


template <typename Conteiner>
void PrintConteiner(Conteiner conteiner) {
    
    for(auto i : conteiner) 
        std::cout<<i<<"  ";
    
    std::cout<<"\n";     
}




int main() {
    
   std::vector<int> db(20);
   std::cout<<"To exit the program, the number is -2\n";
   std::cout<<"To output the container, the number is -1\n";
    
    for(;;) {
        int n;
        std::cout<<"input number: ";
        std::cin>>n; 
            if (n == - 2) {
                std::cout<<"\nThe work of the program is completed!";
                return 0;
            } 
            else if (n == -1) {
                std::cout<<"output: ";
                PrintConteiner(db);
            } else {
                RingBuffer(db, n);
            }
    }

    return 1;
}




