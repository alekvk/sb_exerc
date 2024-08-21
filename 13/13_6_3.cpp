#include <iostream>
#include <vector>

int BUFFER_SIZE = 20;
int COUNTER = 0;
std::vector<int> DB(BUFFER_SIZE);


template <typename Term> 
void InsertRingBuffer(Term term); 

void PrintRingBuffer();


int main() {
    
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
            else if (n == -1) PrintRingBuffer();
            else InsertRingBuffer(n);
            

    }

    return 1;
}




void PrintRingBuffer() {

    std::cout<<"output: ";

    for(int i = COUNTER; i < DB.size(); ++i) 
            std::cout<<DB[i]<<"  ";
            
    for(int i = 0; i < COUNTER; ++i) 
            std::cout<<DB[i]<<"  "; 
    
    std::cout<<"\n";     
}


template <typename Term>
void InsertRingBuffer(Term term) {

    COUNTER = COUNTER < BUFFER_SIZE ? COUNTER  : 0; 
    DB[COUNTER] = term;
    ++COUNTER;
     
}
