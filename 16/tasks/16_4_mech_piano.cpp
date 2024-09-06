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

void PrintingDigitsInBinary(int accord, int note, int notes); 

void SingingNotes(int notes); 


              
int main() {

    int accord, notes = 0;
    std::cout<<"Enter the accord number: ";
    std::cin>>accord;
    
    if (accord & NOTE::DO) notes |= NOTE::DO;
    PrintingDigitsInBinary(accord, NOTE::DO, notes); 

    if (accord & NOTE::RE) notes |= NOTE::RE;
    PrintingDigitsInBinary(accord, NOTE::RE, notes);
    
    if (accord & NOTE::MI) notes |= NOTE::MI;
    PrintingDigitsInBinary(accord, NOTE::MI, notes); 

    if (accord & NOTE::FA) notes |= NOTE::FA;
    PrintingDigitsInBinary(accord, NOTE::FA, notes);

    if (accord & NOTE::SOL) notes |= NOTE::SOL;
    PrintingDigitsInBinary(accord, NOTE::SOL, notes);

    if (accord & NOTE::LA) notes |= NOTE::LA;
    PrintingDigitsInBinary(accord, NOTE::LA, notes);

    if (accord & NOTE::SI) notes |= NOTE::SI;
    PrintingDigitsInBinary(accord, NOTE::SI, notes);
  
   
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

void PrintingDigitsInBinary(int accord, int note, int notes) {

    std::cout<<"accord: "<<accord<<"  "<<DecimalToBin(accord)
    <<"  note: "<<note<<"  "<<DecimalToBin(note) 
    <<"  notes: "<<notes<<"  "<<DecimalToBin(notes)<<"\n\n";
          
}


