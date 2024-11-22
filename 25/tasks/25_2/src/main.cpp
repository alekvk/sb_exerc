#include <iostream>
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
#include "ram.h"


int main(){

    std::string oper;
    
    while (true) {

        std::cout<<"\nEnter the command: ";
        std::cin>>oper;

        if (oper == "sum") {
            Compute();
            
        } else if (oper == "save") {
            Save();
               
        } else if (oper == "load") {
            Load();
        
        } else if (oper == "input") {
            Write();

        } else if (oper == "display") {
            Read();
   
        } else if (oper == "exit") {
            std::cout<<"\nExit programm";
            return 0;
           
        } else {
            std::cout<<"\nThe wrong command\n";
        }
    }    
}