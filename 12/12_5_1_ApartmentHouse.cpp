#include <iostream>

void FillArray (std::string arr[], int sizeArr) {

    for (int i = 0; i < sizeArr; ++i) {
        std::cout << "Enter the last name for apartment number "<< i + 1 <<":\n";
        std::string lname;
        std::cin>>lname;
        arr[i] = lname;
    }

    std::cout<<"\nThe array is full.\n\n"; 

}


int main() {

    int sizeArr = 10;  
    std::string house[sizeArr];
    FillArray(house, sizeArr);

    for (int i = 0; i < 3; ++i) {
        std::cout<<"Enter apartment number: ";
        int n;
        std::cin>>n;
        if (n < 1 || n > 10) std::cout<<"Invalid apartment number entered\n";
        else std::cout<<house[n - 1]<<"\n";
    }

    return 0;
    
}

    