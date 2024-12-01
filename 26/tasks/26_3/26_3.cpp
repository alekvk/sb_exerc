#include <iostream>
#include <iomanip>

// размером 80 × 50 точек.

class Monitor {

public:
    
    void Move() {

        int horiz, vert;
        
        std::cout<<"Enter the horizontal offset: ";
        std::cin>>horiz;
        std::cout<<"Enter the vertical offset: ";
        std::cin>>vert;

        if (horiz > 0) {
            if ((w_coord + width_wind - 1  + horiz) <= width_mon - 1)
                w_coord += horiz;  
            else              
                w_coord = width_mon - width_wind;
        }

        if (horiz < 0) {
            if ((w_coord + horiz) >= 0)
                w_coord += horiz;  
            else              
                w_coord = 0;
        }

        if (vert > 0) {
            if (h_coord + vert <= height_mon - 1)
                h_coord += vert;     
            else
                h_coord = height_mon - 1;                 
        }

        if (vert < 0) {
            if (h_coord - height_wind + 1 + vert >= 0)
                h_coord += vert;
            else
                h_coord = height_wind - 1;            
        }

        std::cout<<"Coordinates of the upper-left corner\n"
        <<"width: "<<w_coord<<"   "<<"height: "<<h_coord<<"\n";
    }

    void Resize() {
        
        int horiz, vert;
        
        std::cout<<"Enter the width of the window: ";
        std::cin>>horiz;
        std::cout<<"Enter the height of the window: ";
        std::cin>>vert;

        if ( horiz <= 1 || vert <= 1 ) {
            std::cout<<"\nIncorrect window sizes\n";
            return;
        }

        if (w_coord + horiz - 1 <= width_mon - 1)
            width_wind = horiz;
        else
            width_wind = width_mon - w_coord + 1;     
        
        if (h_coord - vert + 1 >= 0 )
            height_wind = vert;
        else
            height_wind = h_coord + 1;
            
        std::cout<<"Window size\n"
        <<"width: "<<width_wind<<"   "<<"height: "<<height_wind<<"\n";
    }

    void Display() {

        for (int i = height_mon - 1; i >= 0; --i) {
            for (int j = 0; j < width_mon; ++j) {
                if((i <= h_coord && i >= h_coord - height_wind + 1)
                    && (j >= w_coord && j <= w_coord + width_wind - 1))        
                    std::cout<<'1';  
                else
                    std::cout<<'0';        
            }
            std::cout<<"\n";
        }
    }

private:
    const int width_mon = 80;
    const int height_mon = 50;
    
    int width_wind = 2;
    int height_wind = 2;

    int w_coord = 0;
    int h_coord = 1; 
};





int main() {

    Monitor* mon = new Monitor();
    std::string oper;

    while(true) {

        std::cout<<"Enter the name of the operation: ";
        std::cin>>oper;

        if (oper == "move" ) {
            mon->Move();

        } else if (oper == "resize") {
            mon->Resize();

        } else if (oper == "display") {
            mon->Display();

        } else if (oper == "close") {
            std::cout<<"Exit programm";
            delete mon;
            mon = nullptr;
            return 0;

        } else {
            std::cout<<"\nIncorrect operation name!\n";
        }
    }

    return 1;
}
