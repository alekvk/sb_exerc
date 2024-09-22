#include <iostream>
#include <fstream>


int main() {

    std::string str, path;
    std::cout<<"Enter the path to the file:\n";
    std::cin>>path;
    //path = "C:\\pract_exercises\\19\\tasks\\19_4\\file_is_png.jpg";
    //path = "C:\\pract_exercises\\19\\tasks\\19_4\\file_no_png.jpg";
    //path = "C:\\pract_exercises\\19\\tasks\\19_4\\file_no_png.png";
    
    std::ifstream file; 
    std::string s = path.substr(path.size() - 4);
    std::cout<<"The file extension is "
    <<(s == ".png" ? "PNG.\n" : "not PNG.\n");
    
    std::cout<<"\nOption without buffer\n";
    {
        bool file_png = true;
        file.open(path, std::ios::binary);

        if (!file.is_open()) {
            std::cout<<"File opening error";
            return 1;    
        }

        char symb;

        for (int i = 0; i < 4 && file_png; ++i ) {
            file>>symb;
            if (i == 0 && (int)symb != -119) file_png = false;
            if (i == 1 && symb != 'P') file_png = false;
            if (i == 2 && symb != 'N') file_png = false;
            if (i == 3 && symb != 'G') file_png = false;   
        }

        file.close();
        std::cout<<"The file is "<<(file_png ? "PNG!\n" : "not a PNG\n");

    }


    std::cout<<"\nThe buffer option\n";
    {
        bool file_png = true;
        std::ifstream file(path, std::ios::binary);

        if (!file.is_open()) {
            std::cout<<"File opening error";
            return 1;    
        }

        char buffer[4];
        file.read(buffer, sizeof(buffer));
    
        for(int i = 0; i < 4 && file_png; ++i) {
            if (i == 0 && (int)buffer[i] != -119) file_png = false;
            if (i == 1 && buffer[i] != 'P') file_png = false;
            if (i == 2 && buffer[i] != 'N') file_png = false;
            if (i == 3 && buffer[i] != 'G') file_png = false;
        }  
            
        file.close();
        std::cout<<"The file is "<<(file_png ? "PNG!\n" : "not a PNG\n");
       
    }

    return 0;   
}






