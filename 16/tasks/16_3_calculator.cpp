#include <iostream>
#include <sstream>


              
int main() {

   std::string buffer;
   char oper;            
   double a, b;
   
   
   std::cout<<"Enter the operation line:\n";
   getline(std::cin, buffer);
   std::stringstream buffer_stream(buffer); 
   buffer_stream>>a>>oper>>b; 
   
    switch(oper) {
        case '+': 
            printf("result: %.2f", a + b);
            break;
        case '-': 
            printf("result: %.2f", a - b);
            break;
        case '/':
            if (b != 0 ) printf("result: %.2f", a / b);
            else std::cout << "You can't divide by zero!"<< "\n";
            break;
        case '*': 
            printf("result: %.2f", a * b);
            break;    
        default: 
            std::cout << "The operation is not defined!" << "\n";
            break;
    }
 
    return 0;
}
