#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdlib.h> 


int main() {
    
    std::time_t timer, target, remain;
    timer = target = time(nullptr);

    std::tm timer_tm = *std::localtime(&timer);
    std::cin>>std::get_time(&timer_tm, "%M/%S");

    std::tm target_tm = *std::localtime(&target);
    target_tm.tm_min = 0;
    target_tm.tm_sec = 0; 

    timer = std::mktime(&timer_tm);
    target =  std::mktime(&target_tm);
     
    for (remain = timer - target; remain != 0; --remain) { 
        std::cout<<remain/60<<" minutes and "
        <<remain%60<<" seconds left"<<"\n";
        Sleep(1000);
        system("cls");
    }

    std::cout<<"\nDING! DING! DING!\n";
    return 0;
}