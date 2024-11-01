#include <iostream>

#define E_MS "Input error"
#define ARG_QUOT_MARKS(arg) #arg
#define NAME_DAY(num_day) DAY##num_day

#define DAY1 ARG_QUOT_MARKS(mondey) 
#define DAY2 ARG_QUOT_MARKS(tuesday)
#define DAY3 ARG_QUOT_MARKS(wednesday)
#define DAY4 ARG_QUOT_MARKS(thursday)
#define DAY5 ARG_QUOT_MARKS(friday)
#define DAY6 ARG_QUOT_MARKS(saturday)
#define DAY7 ARG_QUOT_MARKS(sunday)



int main() {

    while(true) {
        char num_day;
        std::cout<<"\nEnter the day number: ";
        std::cin>>num_day;
        
        switch(num_day) {
            case '1' : std::cout<<NAME_DAY(1); break;
            case '2' : std::cout<<NAME_DAY(2); break;
            case '3' : std::cout<<NAME_DAY(3); break;
            case '4' : std::cout<<NAME_DAY(4); break;
            case '5' : std::cout<<NAME_DAY(5); break;
            case '6' : std::cout<<NAME_DAY(6); break;
            case '7' : std::cout<<NAME_DAY(7); break;
            case '0' : std::cout<<"Exit programm"; 
                       return 0;
            default : std::cout<<E_MS; break;
        }
    }    

    return 0;
}