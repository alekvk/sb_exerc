#include <iostream>
#include <cmath>


enum operation {add, subtract, scale, length, normalize};

struct vector2D {
    double x1;
    double y1;
    double x2;
    double y2;
};

vector2D GetVector();
void Add();
void Subtract();
void Scale();
void Length();
void Normalize(); 


int main() {

    int operation;
   
    while (true) {
        
        std::cout<<"\n\nEnter the number of the operation type\n";
        std::cout<<"(0 - add, 1 - subtract, 2 - scale, 3 - length, 4 - normalize, 5 - quit programm): ";
        std::cin>>operation;

        switch (operation) {
            case 0: Add(); break;
            case 1: Subtract(); break; 
            case 2: Scale(); break; 
            case 3: Length(); break; 
            case 4: Normalize(); break; 
            case 5: std::cout<<"The work of the program is completed!";
                    return 0;
            default: std::cout<<"\nInvalid number\n";
        } 
    }
  
    return 1;
}


vector2D GetVector() {

    double x1, y1, x2, y2;

    std::cout<<"Enter the coordinates x and y of the starting point:\n";
    std::cin>>x1>>y1;
    std::cout<<"Enter the coordinates x and y of the end point:\n";
    std::cin>>x2>>y2;

    return {x1, y1, x2, y2};
}


void Add() {

    std::cout<<"\nAdding two vectors.\n";
    std::cout<<"vector 1\n";  vector2D v1 = GetVector();
    std::cout<<"vector 2\n";  vector2D v2 = GetVector(); 
    
    int v1_x = v1.x2 - v1.x1;
    int v1_y = v1.y2 - v1.y1;
    int v2_x = v2.x2 - v2.x1;
    int v2_y = v2.y2 - v2.y1;

    std::cout<<"\nCoordinates of vector 1: ("<<v1_x <<", "<<v1_y<<")"   
    <<"\nCoordinates of vector 2: ("<<v2_x<<", "<<v2_y<<")"
    <<"\nCoordinates of the sum of vectors (" 
    <<v1_x + v2_x<< "; "<<v1_y + v2_y<<")"; 
  
}


void Subtract() {
    
    std::cout<<"\nSubtraction of two vectors.\n";
    std::cout<<"vector 1\n";  vector2D v1 = GetVector();
    std::cout<<"vector 2\n";  vector2D v2 = GetVector(); 
    
    int v1_x = v1.x2 - v1.x1;
    int v1_y = v1.y2 - v1.y1;
    int v2_x = v2.x2 - v2.x1;
    int v2_y = v2.y2 - v2.y1;

    std::cout<<"\nCoordinates of vector 1: ("<<v1_x <<", "<<v1_y<<")"   
    <<"\nCoordinates of vector 2: ("<<v2_x<<", "<<v2_y<<")"
    <<"\nCoordinates of the difference of vectors (" 
    <<v1_x - v2_x<< "; "<<v1_y - v2_y<<")"; 

}

void Scale() {

    double scal;
    std::cout<<"\nMultiplying a vector by a scalar\n";
    vector2D v = GetVector();
    std::cout<<"Enter the scalar value: ";
    std::cin>>scal;
    std::cout<<"The scalar product: ("
    << (v.x2 - v.x1) * scal <<"; "<< (v.y2 - v.y1) * scal <<")\n";
}

void Length() {
    
    std::cout<<"\nCalculating the length of a vector.\n";
    vector2D v =  GetVector();
    std::cout<<"\nVector length  " 
    <<sqrt( pow((v.x2 - v.x1),2) + pow((v.y2 - v.y1),2) )<<"\n";
}

void Normalize() {

    double length_vector;
    std::cout<<"\nNormalization of the vector.\n";
    vector2D v =  GetVector();
    int v_x = v.x2 - v.x1;
    int v_y = v.y2 - v.y1;
    length_vector = sqrt( pow((v.x2 - v.x1),2) + pow((v.y2 - v.y1),2) );

    std::cout<<"\nCoordinates of vector : ("<<v_x <<", "<<v_y<<")\n"
    <<"The normalized vector : ("<<v_x/length_vector <<"; "<<v_y/length_vector<<")"; 
} 