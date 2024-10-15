#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>


struct recipient {
    std::string first_name;
    std::string last_name;
    std::string date;
    int payment;
};

std::vector<recipient> PAYROL;

void PrintPayrol(); 

void save_recipient(std::ofstream& file, recipient& person);

void load_recipient(std::ifstream& file, recipient& person); 


int main() {
    
    std::string path = "payment_statement.bin";
    
    while(true) {
        std::string command;

        std::cout<<"\n\"list\" - reading the payroll\n";
        std::cout<<"\"add\" -  adding a new entry to the end of the payrol\n";
        std::cout<<"\"q\" - exiting the program\n\n";
        std::cout<<"Enter the command: ";
        std::cin >> command;
    
        if (command == "list") {
            std::ifstream file(path, std::ios::binary);

            while(!file.eof()) {
                recipient r;
                load_recipient(file, r);
                if (!file.eof())
                    PAYROL.push_back(r);   
            }

            PrintPayrol(); 
           
        } else if (command == "add") {
            std::string str, first_name, last_name, date, payment;

            std::cout<<"Enter first_name, last_name, date, payment:\n";
            std::cin.ignore();
            std::getline(std::cin, str);

            std::stringstream s(str);
            s>>first_name>>last_name>>date>>payment;
            recipient r = {first_name, last_name, date, stoi(payment)};
            std::ofstream file(path, std::ios::app | std::ios::binary);
            save_recipient(file, r);
            file.close();
           
        } else if (command == "q") {
            std::cout<<"\nThe program has been finished";
            return 0;

        } else {
            std::cout << "\nIncorrect command";
            continue;
        }
    }

    return 1;  
}




void save_recipient(std::ofstream& file, recipient& person) {

    int len;

    len = person.first_name.length();
    file.write((char*)&len, sizeof(len));
    file.write(person.first_name.c_str(), len);

    len = person.last_name.length();
    file.write((char*)&len, sizeof(len));
    file.write(person.last_name.c_str(), len);

    len = person.date.length();
    file.write((char*)&len, sizeof(len));
    file.write(person.date.c_str(), len);

    file.write((char*)&person.payment, sizeof(person.payment));
}
    
void load_recipient(std::ifstream& file, recipient& person) {

    int len;
    
    file.read((char*)&len, sizeof(len));
    person.first_name.resize(len);
    file.read((char*)person.first_name.c_str(), len);

    file.read((char*)&len, sizeof(len));
    person.last_name.resize(len);
    file.read((char*)person.last_name.c_str(), len);

    file.read((char*)&len, sizeof(len));
    person.date.resize(len);
    file.read((char*)person.date.c_str(), len);

    file.read((char*)&person.payment, sizeof(person.payment));

}


void PrintPayrol() {

    for (size_t i = 0; i < PAYROL.size(); ++i) {
        std::cout<<PAYROL[i].first_name<<"  "<<PAYROL[i].last_name
        <<"  "<<PAYROL[i].date<<"  "<<PAYROL[i].payment<<"\n";    
    }

    std::cout<<"\n";
}






