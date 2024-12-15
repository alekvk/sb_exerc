#include <iostream>
#include <cmath>


enum Color { NONE, RED, BLUE, GREEN };

class GeomShape {
    
public:

    GeomShape (int coord_x = 0, int coord_y = 0, Color color = NONE) :
        coord_x_(coord_x), 
        coord_y_(coord_y),
        color_(color)  
           
    {}

    int coord_x_; 
    int coord_y_;
    Color color_;
};



class Circle: public GeomShape 
{

public:

    Circle (int coord_x, int coord_y, double radius, Color color) :
        radius_(radius),
        GeomShape(coord_x, coord_y, color)  
    {}

    Circle (double radius, Color color = NONE) : Circle (0, 0, radius, color)
    {}
 

    double radius_;
    
    double Area()
    {
        return atan(1) * 4 * radius_; 
    }

    double DescrRectangleArea ()
    {
        return 4 * radius_ * radius_;
    }

};


class Square: public GeomShape 
{

public:

    Square (int coord_x, int coord_y, double edge, Color color ) :
        edge_(edge),
        GeomShape(coord_x, coord_y, color)  
    {}

    Square (double edge, Color color = NONE) : Square (0, 0, edge, color)
    {}

    double edge_;

    double Area() {

        return edge_ * edge_;
    }

    double DescrRectangleArea () {

        Area();
    }
};

class EquilateralTriangle: public  GeomShape
{

public:

    EquilateralTriangle (int coord_x, int coord_y, double edge, Color color) :
        edge_(edge),
        GeomShape(coord_x, coord_y, color)  
    {}

    EquilateralTriangle (double edge, Color color) : 
        EquilateralTriangle (0, 0, edge, color)
    {}


    double edge_;
     
    double Area()
    {
        return edge_ * edge_ * sqrt(3) / 4; 
    } 

    double DescrRectangleArea ()
    {
        return edge_ * edge_ * sqrt(3) / 2;   
    }
};

class Rectangle: public GeomShape
{

public:
    
    Rectangle (int coord_x, int coord_y, double width, double height, Color color = NONE) :
        width_(width),
        height_(height),
        GeomShape(coord_x, coord_y, color)  
    {}

    Rectangle (double width, double height, Color color = NONE) : 
        Rectangle (0, 0, width, height, color)
    {}

    double width_; 
    double height_;

    double Area()
    {
        return width_ * height_; 
    } 

    double DescrRectangleArea ()
    {
        Area();      
    }
};

Color SelectColor() {

    int num;
    
    do {
        std:: cout<<"Enter the color number\n";
        std::cout<<"0 - NONE,  1 - RED, 2- BLUE, 3 - GREEN \n";    
        std::cin >> num;

        if (num < 0 || num > 3)
            std::cout<<"Wrong number\n"; 

    } while (num < 0 || num > 3);

    switch (num) {
        case 0:
            return NONE;
        case 1:
            return RED;
        case 2:
            return BLUE;
        case 3:
            return GREEN;
    }
}


int main() 
{
    std::string oper;

    while (true) {
        std::cout<<"Enter the command(circle, square, triangle, rectangle):\n";
        std::cin>>oper;

        if (oper == "circle") {
           
            double r;
            std:: cout<<"Enter the radius: ";
            std::cin>>r;
            Circle c = Circle(r,  SelectColor());
            std::cout<<"\nThe area of the figure: "
            <<c.Area();
            std::cout<<"\nThe area of the describing triangle: "
            <<c.DescrRectangleArea()<<"\n";

        } else if (oper == "square") {
            double e;
            std:: cout<<"Enter the edge: ";
            std::cin>>e;
            Square s = Square(e, SelectColor());
            std::cout<<"\nThe area of the figure: "
            <<s.Area();
            std::cout<<"\nThe area of the describing triangle: "
            <<s.DescrRectangleArea()<<"\n";
    
        } else if (oper == "triangle") {
            double e;
            std:: cout<<"Enter the edge: ";
            std::cin>>e;
            EquilateralTriangle tr = EquilateralTriangle(e, SelectColor());
            std::cout<<"\nThe area of the figure: "
            <<tr.Area();
            std::cout<<"\nThe area of the describing triangle: "
            <<tr.DescrRectangleArea()<<"\n";

        } else if (oper == "rectangle") {
            double w, h;
            std:: cout<<"Enter the Enter the width and height:\n";
            std::cin>>w>>h;
            Rectangle r = Rectangle(w, h, SelectColor());
            std::cout<<"\nThe area of the figure: "
            <<r.Area();
            std::cout<<"\nThe area of the describing triangle: "
            <<r.DescrRectangleArea()<<"\n";
 
        } else if (oper == "exit") {
            return 0;
            
        } else {
            std::cout<<"\nThe wrong command\n";
        }
    }

    return 1;
    
}
