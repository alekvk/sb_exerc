#include <iostream>


template <typename Term>
double GetAverage(Term* arr, int size)
{
    if (size <= 0) return -1.79769e+308;
    
    double sum = 0;

    for (int i = 0; i < size; ++i)
        sum += *(arr + i);
    
    return sum / size;
}


int main()
{
    int size;
    int intArr[] = {5, 3, 4, 6, 11};
    double doubleArr[] = {5.566, -11.825, -9.0, 6.33, 89.8963, -202.369, -199.1};
    float floatArr[] = {123.456e-2f, 123.456e+2f};
    
    size = sizeof(intArr)/sizeof(intArr[0]);
    std::cout<<"size: "<<size<<"  "<<"avr: "
    <<GetAverage(intArr, size)<<std::endl;
    
    size = sizeof(doubleArr)/sizeof(doubleArr[0]);
    std::cout<<"size: "<<size<<"  "<<"avr: "
    <<GetAverage(doubleArr, size)<<std::endl;
   
    size = sizeof(floatArr)/sizeof(floatArr[0]);
    std::cout<<"size: "<<size<<"  "<<"avr: "
    <<GetAverage(floatArr, size)<<std::endl;

    return 0;
}