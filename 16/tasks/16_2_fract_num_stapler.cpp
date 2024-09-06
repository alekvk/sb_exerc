#include <iostream>
#include <cmath>
#include <iomanip>

template <typename Term, typename Term_>
bool XOR(Term a, Term_ b); 

template <typename Term, typename Term_>
bool OR(Term a, Term_ b); 


              
int main() {

    std::string strIntPartNum, strFractPartNum;
    
    std::cout<<"Enter the integer part of the number:\n";
    std::cin>>strIntPartNum;
    std::cout<<"Enter the fractional part of the number:\n";
    std::cin>>strFractPartNum;
    
    int intPartNum = stod(strIntPartNum);
    double fractPartNum = stod(strFractPartNum);

    int precision = strFractPartNum.size();

    if (fractPartNum < 0) {
        --precision;
        fractPartNum /= pow(10, precision);
    } else {
        fractPartNum /= pow(10, precision);
    }

    int coeff = XOR(intPartNum, fractPartNum) ? -1 : 1;
    double num = coeff * (std::fabs(intPartNum) + std::fabs(fractPartNum));
    
    std::cout << std::fixed << std::setprecision(precision) <<num<<"\n";

    return 0;
}



template <typename Term, typename Term_>
bool XOR(Term a, Term_ b) {
    return (a < 0 || b < 0) && !(a < 0 && b < 0);
}

template <typename Term, typename Term_>
bool OR(Term a, Term_ b) {
    return a < 0 || b < 0;
}















//std::cout<<strIntPartNum<<"  "<<strFractPartNum<<"\n";
    //std::cout<<intPartNum<<"  "<<fractPartNum<<"\n\n";