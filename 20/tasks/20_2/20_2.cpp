#include <iostream>
#include <fstream>
#include <ctime>
//#include <cstring>


void PrintFile(std::string path); 



int main() {

    std::string path = "binary_picture.txt";
    PrintFile(path);

    std::srand(time(nullptr));
    int width, height;

    do {

        std::cout << "Enter height and width:\n";
        std::cin >> height >> width;
        if (width <= 0 || height <= 0)
            std::cout<<"Wrong numbers\n"; 

    } while (width <= 0 || height <= 0);

    std::ofstream file(path);
   
    for (int i = 0; i < height; ++i) {

        for(int j = 0; j < width; ++j) {
            file << rand() % 2;    
        }

        file << "\n";      
    }

    file.close();
    PrintFile(path);

    return 0;
 
}




void PrintFile(std::string path) {

    char ch; 
    std::ifstream file(path);

    if (file.is_open()) {
        std::cout<<"Here are the current contents of the "
        <<path<<" file:\n";
        while(file.get(ch)) 
            std::cout<<ch;
        file.close();
        std::cout<<"\n";    
    }
} 


