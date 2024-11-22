#include <iostream>
#include "custom_types.h"
#include "surg.h"


point INCISION_1, INCISION_2;


int main(){

    std::string oper;
    bool cut = false;
    point suture_1, suture_2, clamp, tweezers;

    while (true) {
        
        std::cout<<"\nEnter the command: ";
        std::cin>>oper;

        if (oper == "scalpel") {

            if(cut) {
               std::cout<<"\nThe incision has already been made";
               continue;
            }
                
            std::cout<<"Enter the coordinates of the cut points\n";
            std::cout<<"Point 1\n";
            INCISION_1 = GetCoord();
            std::cout<<"Point 2\n";
            INCISION_2 = GetCoord();

            cut = true;

            std::cout<<"A cut is made between the entered points\n";
                
        } else if (oper == "hemostat") {

            if(!cut) {
                std::cout<<"\nThe incision has not been made yet\n";
                continue;
            }
            
            std::cout<<"Enter the clamping point\n";
            clamp = GetCoord(); 
            std::cout<<"A clamp is made at the specified point\n";
        
        } else if (oper == "tweezers") {

            if(!cut) {
                std::cout<<"\nThe incision has not been made yet\n";
                continue;
            }

            std::cout<<"Enter the point of the tweezers\n";
            tweezers = GetCoord();
            std::cout<<"Tweezers at the specified point\n";
            

        } else if (oper == "suture") {

            if(!cut) {
                std::cout<<"\nThe incision has not been made yet\n";
                continue;
            }

            std::cout<<"Enter the coordinates of the suture points\n";
            std::cout<<"Point 1\n";  suture_1 = GetCoord();
            std::cout<<"Point 2\n";  suture_2 = GetCoord();

            if ((EqualPoints(suture_1, INCISION_1)
                && EqualPoints(suture_2, INCISION_2))
                || (EqualPoints(suture_1, INCISION_2)
                && EqualPoints(suture_2, INCISION_1))) {
                    std::cout<<"\nThe surgical operation is completed!\n";
                    return 0;
            }

            std::cout<<"A suture has been made between the two indicated points.\n";
       
        } else {
            std::cout<<"\nThe wrong command\n";
        }
    }    
}