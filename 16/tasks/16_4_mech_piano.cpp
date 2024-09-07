#include <iostream>

enum NOTE {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

std::string DecimalToBin(int n);

void SingingNotes(int notes); 


              
int main() {

    int notes = 0;
    int accord, mask;
    bool number;

    do {
        number = true;
        std::cout<<"Enter the accord number containing the digits from 1 to 7\n";
        std::cin>>accord;

        if (accord < 0) {
            std::cout<<"An incorrect number was entered\n";
            number = false;
            continue;
        }

        while (accord > 0) {
            int n = accord % 10;
            if (n == 0 || n > 7) {
                std::cout<<"The accord contains incorrect numbers\n";
                number = false;
                break;    
            }
            mask = 1 << (n - 1);
            notes |= mask;
            std::cout<<n<<"  bitwise shift: 1/"<<(n - 1)<<" "<<"  mask: "
            <<DecimalToBin(mask) <<"   notes: "<<DecimalToBin(notes)<<"\n";
            accord/=10;    
        }

    } while (!number); 

    SingingNotes(notes);
  
    return 0;
}




void SingingNotes(int notes) {
    std::cout<<"I'm singing: ";
    if (notes & NOTE::DO) std::cout << "DO ";
    if (notes & NOTE::RE) std::cout << "RE ";
    if (notes & NOTE::MI) std::cout << "MI ";
    if (notes & NOTE::FA) std::cout << "FA ";
    if (notes & NOTE::SOL) std::cout<< "SOL ";
    if (notes & NOTE::LA) std::cout << "LA ";
    if (notes & NOTE::SI) std::cout << "SI ";
}


std::string DecimalToBin(int n) {

    std::string tmp,bin;
    
    while (n >= 1) {
        tmp += std::to_string(n%2);
        n /=2;
    }

    if (tmp.size() < 8) {
        int k = 8 - tmp.size();
        for (int j = 0; j < k; ++j)
            tmp += "0";
    }

    for (int i = tmp.size() - 1; i >= 0; --i) 
        bin +=tmp[i];
    
    return bin;

}
