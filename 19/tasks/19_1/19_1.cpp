#include <iostream>
#include <fstream>



int main() {
    
    int count = 0;
    std::string word;
    std::cout<<"Enter the word:\n";
    std::cin>>word;
    //std::string word = "Alice";
    std::string path_file = "C:\\pract_exercises\\19\\tasks\\19_1\\words.txt";
    
    std::ifstream book;
    book.open(path_file);

    if (!book.is_open()) 
        std::cout<<"File opening error";
    
    for (;!book.eof();) {
        std::string tmp;
        book>>tmp;
        if (tmp == word) ++count;
    }

    book.close();
    std::cout<<count;
    
    return 0;
}