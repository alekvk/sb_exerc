#include <iostream>
#include <fstream>


int main() {

    int input;
    int size_buffer = 1000;
    
    std::string path;
    std::cout<<"Enter the path to the file:\n";
    std::cin>>path;
    //path = "C:\\pract_exercises\\19\\tasks\\19_2\\The_Hound_of_the_Baskervilles.txt";
        
    std::ifstream book;
    book.open(path);

    if (!book.is_open()) {
        std::cout<<"File opening error";
        return 1;    
    }

    while (std::cin>>input && !book.eof()) {
        char buffer[size_buffer];
        book.read(buffer, sizeof(buffer)-1);
        std::cout<<buffer<<"\n";    
    }

    book.close();
       
    return 0;
}