#include <iostream>
#include <iomanip>
#include <map>


class Window {
    
public:

    Window (int width_mon, int height_mon) {
        
        width_mon_ = width_mon;
        height_mon_ = height_mon;
    }
     
    int GetW_coord() { return w_coord_; }

    int GetH_coord() { return h_coord_; }

    int GetWidth() { return  width_; }

    int GetHeight() { return height_; }


    void SetPosition(int horiz, int vert) {

        if (horiz > 0) {
            if ((w_coord_ + width_ - 1  + horiz) <= width_mon_ - 1)
                w_coord_ += horiz;  
            else              
                w_coord_ = width_mon_ - width_;
        }

        if (horiz < 0) {
            if ((w_coord_ + horiz) >= 0)
                w_coord_ += horiz;  
            else              
                w_coord_ = 0;
        }

        if (vert > 0) {
            if (h_coord_ + vert <= height_mon_ - 1)
                h_coord_ += vert;     
            else
                h_coord_ = height_mon_ - 1;                 
        }

        if (vert < 0) {
            if (h_coord_ - height_ + 1 + vert >= 0)
                h_coord_ += vert;
            else
                h_coord_ = height_ - 1;            
        }

        
    }

    void SetSize(int horiz, int vert) {

        if (w_coord_ + horiz - 1 <= width_mon_ - 1)
            width_ = horiz;
        else
            width_ = width_mon_ - w_coord_ + 1;     
        
        if (h_coord_ - vert + 1 >= 0 )
            height_ = vert;
        else
            height_ = h_coord_ + 1;
            
        
    }

private:

    int width_ = 2;
    int height_ = 2;

    int w_coord_ = 0;
    int h_coord_ = 1; 

    int height_mon_; 
    int width_mon_;
};


class Monitor {

public:
    
    Monitor(int width_mon = 80, int height_mon = 50) :

       width_mon_ (width_mon),  
       height_mon_ (height_mon)
    {} 

    
    void Move() {
               
        int horiz, vert;
                
        std::cout<<"Enter the horizontal offset: ";
        std::cin>>horiz;
        std::cout<<"Enter the vertical offset: ";
        std::cin>>vert;

        w.SetPosition(horiz, vert);

        std::cout<<"Coordinates of the upper-left corner\n"
        <<"width: "<<w.GetW_coord()<<"   "
        <<"height: "<<w.GetH_coord()<<"\n";
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

        w.SetSize(horiz, vert);

        std::cout<<"Window size\n"
        <<"width: "<<w.GetWidth()<<"   "
        <<"height: "<<w.GetHeight()<<"\n";
    }
   
    void Display() {

        DisplayWindow(w); 
    }
    

private:

    void DisplayWindow(Window w) {

        int h_coord = w.GetH_coord();
        int w_coord = w.GetW_coord();
        int height_wind = w.GetHeight();
        int width_wind = w.GetWidth(); 

        for (int i = height_mon_ - 1; i >= 0; --i) {
            for (int j = 0; j < width_mon_; ++j) {
                if((i <= h_coord && i >= h_coord - height_wind + 1)
                    && (j >= w_coord && j <= w_coord + width_wind - 1))        
                    std::cout<<'1';  
                else
                    std::cout<<'0';        
            }
            std::cout<<"\n";
        }
    }

    int width_mon_;
    int height_mon_;
    Window w = Window(width_mon_, height_mon_);
};


int main() {

    int width = 80; 
    int height = 50;
    Monitor* mon = new Monitor(width, height);
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
