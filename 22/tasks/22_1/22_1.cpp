#include <iostream>
#include <string>
#include <map>
#include <fstream>

std::string PATH = "phones.txt";
std::map<std::string, std::string> PHONES;

void AddPhone();
void GetLastName(std::string phone); 
void GetPhones(std::string last_name);
void ReadPhones(std::ifstream& file); 
void SavePhones(std::ofstream& file);
void ListPhones();


int main () {

    std::ifstream file(PATH, std::ios::binary);

    if (file.is_open()) {
        ReadPhones(file);
        file.close();
    } else { 
        std::cout<<"The phone book is empty";
    }     

              
    while (true) {
        char operation;
        
        std::cout<<"\nEnter a number\n"
        <<"(1 - Add a phone   2 - Get the last name "
        <<"  3 - Get the phones   4 - List phones   5 - Exit program)\n";
        std::cin>>operation;
           
        switch(operation) {
            case '1': AddPhone(); 
                    break;
            case '2': {
                    std::string phone;
                    std::cout<<"\nEnter the phone: ";
                    std::cin>>phone; 
                    GetLastName(phone); 
                    break;
                    }
            case '3': {
                    std::string last_name;
                    std::cout<<"\nEnter the last name: ";
                    std::cin>>last_name; 
                    GetPhones(last_name);
                    break;
                    }
            case '4': ListPhones();
                    break;
            case '5': {
                    std::ofstream file(PATH);
                    SavePhones(file);
                    file.close();
                    std::cout<<"\nExit program";
                    return 0;
                    }
            default:std::cout<<"\nInvalid number\n";
                    //std::cin.sync();
                    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break; 
        } 
   }

   return 1;

}



void AddPhone () {

    std::string last_name, phone;

    std::cout<<"Enter the last_name: ";
    std::cin>>last_name;
    std::cout<<"Enter the phone: ";
    std::cin>>phone;

    if(PHONES.count(phone)) {
        std::string choice;
        std::cout<<"The phone is already in the book\n"
        <<"Do you want to rewrite the last name\n";

        do {
            std::cout<<"Enter yes or no: ";
            std::cin>>choice;
            if( !(choice == "yes" || choice == "no") )
                std::cout<<"The wrong word\n";
        } while ( !(choice == "yes" || choice == "no") );
        
        if (choice =="yes") PHONES[phone] = last_name;
        
    } else {
        //PHONES.insert(std::pair<std::string, std::string> (phone, last_name));
        PHONES.insert({phone, last_name});
    } 


    
} 


void GetLastName(std::string phone) {

    if (PHONES.find(phone) != PHONES.end()) 
        std::cout<<PHONES.find(phone)->second;
    else std::cout<<"\nThe phone was not found\n";
} 

void GetPhones(std::string last_name) {
    
    bool phone = false; 
    std::map<std::string, std::string>::iterator it;

    for (it = PHONES.begin(); it != PHONES.end(); ++it) {
        if (it->second == last_name) {
            phone = true;
            std::cout<<it->first<<" ";        
        } 
    }

    if (!phone) std::cout<<"There are no phone subscribers\n";
}

void ListPhones() {

    for (auto&[p,l]: PHONES)
        std::cout<<l<<" "<<p<<"\n"; 
}

void ReadPhones(std::ifstream& file) {
    
    while(!file.eof()) {

        int len;
        std::string phone, last_name;

        file.read((char*)&len, sizeof(len));
        phone.resize(len);
        file.read((char*)phone.c_str(), len);

        file.read((char*)&len, sizeof(len));
        last_name.resize(len);
        file.read((char*)last_name.c_str(), len);

        if (!file.eof()) PHONES[phone] = last_name;   
     }
}


void SavePhones(std::ofstream& file){
        
    int len;
    std::string phone, last_name;
    
    for (auto& [k, v] : PHONES) {
        phone = k; last_name = v;

        len = phone.length();
        file.write((char*)&len, sizeof(len));
        file.write(phone.c_str(), len);

        len = last_name.length();
        file.write((char*)&len, sizeof(len));
        file.write(last_name.c_str(), len);
    }
}

