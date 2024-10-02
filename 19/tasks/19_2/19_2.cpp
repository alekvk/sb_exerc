#include <iostream>
#include <fstream>


int main() {

    int size_buffer = 500;
    char buffer[size_buffer];
    std::string path;
    std::cout<<"Enter the path to the file:\n";
    std::cin>>path;
    //path = "The_Hound_of_the_Baskervilles.txt";
        
    std::ifstream book;
    book.open(path);

    if (!book.is_open()) {
        std::cout<<"File opening error";
        return 1;    
    }

         
    int counter = 0;
    
    while (!book.eof()) {
        book.read(buffer, sizeof(buffer)-1);
        buffer[book.gcount()] = 0;
        std::cout<<buffer;
        ++counter;

        if(counter == 2) { 
            counter = 0;
            std::cout<<"\n";
            system("pause");
            system("cls");
        }

    }


    book.close();
       
    return 0;
}