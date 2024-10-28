#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <map>
#include <fstream>

std::string PATH_PHONES = "phones.txt";
std::string PATH_LNAMES = "last_names.txt";
std::map<std::string, std::string> PHONES;
std::map<std::string, std::vector<std::string>> LNAMES;

void AddPhone();
void GetLastName(std::string phone); 
void GetPhones(std::string last_name);
void ReadPhones(std::ifstream& file); 
void SavePhones(std::ofstream& file);
void SaveLastNames(std::ofstream& file);
void ReadLastNames(std::ifstream& file);
void ListPhones();
void ListLastNamesPhones();


int main () {

    std::ifstream file_phones(PATH_PHONES, std::ios::binary);
    std::ifstream file_lnames(PATH_LNAMES, std::ios::binary);


    if (file_phones.is_open()) {
        ReadPhones(file_phones);
        file_phones.close();
    } else { 
        std::cout<<"The phone book is empty\n";
    }
    
    if (file_lnames.is_open()) {
        ReadLastNames(file_lnames);
        file_lnames.close();
    } else { 
        std::cout<<"The last names phone book is empty";
    } 

    while (true) {
        char operation;
        
        std::cout<<"\nEnter a number\n"
        <<"(1 - Add a phone   2 - Get the last name "
        <<"  3 - Get the phones   \n 4 - List phones   5 - List last names  6 - Exit program)\n";
        std::cin>>operation;
           
        switch(operation) {
            case '1': AddPhone(); 
                    break;
            case '2':
                    {
                    std::string phone;
                    std::cout<<"\nEnter the phone: ";
                    std::cin>>phone; 
                    GetLastName(phone); 
                    break;
                    }
            case '3': 
                    {
                    std::string last_name;
                    std::cout<<"\nEnter the last name: ";
                    std::cin>>last_name; 
                    GetPhones(last_name);
                    break;
                    }
            case '4': ListPhones();
                      break;
            case '5': ListLastNamesPhones();
                      break; 
            case '6':
                    {
                    std::ofstream pfile(PATH_PHONES);
                    SavePhones(pfile);
                    pfile.close();
                    
                    std::ofstream lfile(PATH_LNAMES);
                    SaveLastNames(lfile);
                    lfile.close();

                    std::cout<<"\nExit program";
                    return 0;
                    }
            default:std::cout<<"\nInvalid number\n";
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

        if (last_name == PHONES[phone]) {
            std::cout<<"The subscriber with the specified phone number "
            <<"is already present in the phone book";
            return;
        }

        std::string choice;
        std::cout<<"The phone is already in the book\n"
        <<"Do you want to rewrite the last name\n";

        do {
            std::cout<<"Enter yes or no: ";
            std::cin>>choice;
            if( !(choice == "yes" || choice == "no") )
                std::cout<<"The wrong word\n";
        } while ( !(choice == "yes" || choice == "no") );
        
        if (choice =="yes") {
            std::string prev_name = PHONES[phone];
            PHONES[phone] = last_name;

            auto it = std::find(LNAMES[prev_name].begin(), LNAMES[prev_name].end(), phone);
            if(it != LNAMES[prev_name].end())
                LNAMES[prev_name].erase(it);
            LNAMES[last_name].push_back(phone);         
        }
        
    } else {
        PHONES.insert({phone, last_name});
        LNAMES[last_name].push_back(phone);    
    }
} 


void GetLastName(std::string phone) {

    if (PHONES.find(phone) != PHONES.end()) 
        std::cout<<PHONES.find(phone)->second;
    else 
        std::cout<<"\nThe phone is missing from the phone book\n";
} 

  

void GetPhones(std::string last_name) {

    if(LNAMES.count(last_name)){
        for(auto p : LNAMES[last_name])
            std::cout<<p<<"  ";
    } else {
       std::cout<<"There are no phone subscribers\n"; 
    }
}

void ListPhones() {

    for(auto&[p,l]: PHONES)
        std::cout<<l<<" "<<p<<"\n"; 
}

void ListLastNamesPhones() {

    for(auto& l: LNAMES) {
        std::cout<<l.first<<": ";

        for(auto& p : l.second) 
            std::cout<<p<<"  ";
        
        std::cout<<"\n";
    } 
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

void SaveLastNames(std::ofstream& file) {

    int len;
    std::string last_name, phone;
    std::vector<std::string> vect_phones;

    for(auto &[k, v] : LNAMES) {
        
        last_name = k;
        vect_phones = v;

        len = last_name.size();
        file.write((char*)&len, sizeof(len));
        file.write(last_name.c_str(), len);

        int size_vect = vect_phones.size();
        file.write((char*)&size_vect, sizeof(size_vect));
    
        for (int i = 0; i < size_vect; ++i) {
            len = vect_phones[i].size();
            file.write((char*)&len, sizeof(len));
            file.write(vect_phones[i].c_str(), len);
        }
    }
    
}

void ReadLastNames(std::ifstream& file){

    int len, size_vect;
    std::string last_name, phone;
    
    while (!file.eof()) {

        std::vector<std::string> vect_phones;
              
        file.read((char*)&len, sizeof(len));
        last_name.resize(len);
        file.read((char*)last_name.c_str(), len);

        file.read((char*)&size_vect, sizeof(size_vect));

        for(int i = 0; i < size_vect; ++i) {
            file.read((char*)&len, sizeof(len));
            phone.resize(len);
            file.read((char*)phone.c_str(), len); 
            vect_phones.push_back(phone); 
        }

        if (!file.eof())
            LNAMES[last_name] = vect_phones; 
    }
}
