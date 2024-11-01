#include <iostream>
#include <vector>

#define NUM_WAGONS 10
#define OPT_NUM_PASS 20
#define CALL(func) { func(); }
#define CALL_ARG(func, arg) { func(arg); };

int TOTAL_NUMBER_PASS;
std::vector<int> OVERLY, ZERO;

void TrainAnalys();
void PrintConteiner(std::vector<int> cont);


int main() {
    
    CALL(TrainAnalys);

    std::cout<<"\nOver-filled wagons: ";
    CALL_ARG(PrintConteiner, OVERLY);

    std::cout<<"Wagons with empty passenger seats: "; 
    CALL_ARG(PrintConteiner, ZERO);

    std::cout<<"Total number of passengers in all carriages: "
    <<TOTAL_NUMBER_PASS; 

    return 0;
} 




void TrainAnalys() {

   int n;
   TOTAL_NUMBER_PASS = 0;

    for (int i = 1; i <= NUM_WAGONS; ++i) {
        std::cout<<"Enter the number of passengers "
            <<"in the carriage number "<<i<<": ";
        std::cin>>n;

        if(n > OPT_NUM_PASS) 
            OVERLY.push_back(i);
        if(n == 0)
            ZERO.push_back(i);

        TOTAL_NUMBER_PASS += n;
    }
}


void PrintConteiner(std::vector<int> cont) {

    for(auto& i : cont) std::cout<<i<<" ";
    std::cout<<"\n"; 
}


