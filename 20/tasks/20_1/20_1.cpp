#include <iostream>
#include <fstream>
#include <cstring>


void PrintFile(std::string path); 

bool CheckDate(std::string date); 


int main() {

    std::string path;
    path = "statement.txt";
    PrintFile(path);
    
    std::ofstream payrol;
    payrol.open(path, std::ios::out | std::ios::app);
    if (!payrol.is_open()) {
        std::cout<<"File opening error";
        return 1;    
    }

    int n;
    std::cout<<"To enter data into the statement, enter the number 1\n"
        <<"To stop entering data into the statement, enter the number 2\n\n";     

    while (true) {
        std::string first_name, last_name, date;
        unsigned sum;
        std::cout<<"Enter the option number: ";
        std::cin>>n;
        if (n == 1) {
            std::cout<<"Enter a first name: ";
            std::cin>>first_name;
            std::cout<<"Enter a last name: ";
            std::cin>>last_name;
            std::cout<<"Enter date of issue in the format DD.MM.YYYY.: ";
            std::cin>>date;
            if (!CheckDate(date)) {
                std::cout<<"Incorrect date!\n";
                continue;
            }
            std::cout<<"Enter a sum: ";
            std::cin>>sum;
            payrol<<first_name<<" "<<last_name<<" "<<" "<<date<<" "<<sum<<"\n";
        } else if (n == 2) {
            payrol.close();
            PrintFile(path);
            return 0;
        } else std::cout<<"The wrong number\n";
    }

    return 1;
 
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


bool CheckDate(std::string date) {
   
    if(date.length() != 10) return false;
    if(date[2] != '.' || date[5] != '.' ) return false;
    
    for (int i = 0; i < date.length(); ++i) {
        if ( (date[i] < '0' || date[i] > '9') 
              && ( i <= 1 || (i >= 3 && i <= 4) || i >= 6)) return false;
    }

    int day = stoi(date.substr(0, 2));
    if (day < 0 || day > 31) return false;  
   
    int month = stoi(date.substr(3, 2));
    if (month < 1 || month > 12) return false; 

    int year = stoi(date.substr(6, 4));
    if (year != 2024) return false;  

    return true;
}
