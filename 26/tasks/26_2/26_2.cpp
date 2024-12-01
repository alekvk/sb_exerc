#include <iostream>
#include <map>


class Contact {

public:
    std::string GetName()
    {
        return name_;
    }

    std::string GetPhone()
    {
        return phone_number_;
    }

    void SetName(std::string name)
    {
        name_ = name;
    }
    
    void SetPhone(std::string phone_number) 
    {
        phone_number_ = phone_number;
    }

private:
    std::string phone_number_;
    std::string name_;
};


class Phone {

public:

    void Add() {
        
        std::string name, phone;
        
        std::cout<<"Enter your name and phone number name:\n";
        std::cin>>name>>phone;

        if(!CheckFormatNumber(phone)) {
            std::cout<<"Wrong phone number\n";
            return;
        }
            
        if(contacts_.count(name)) {
            std::cout<<"\nThe name is already present "
            <<"in the address book\n";
            return;
        }

        Contact cont;
        cont.SetName(name);
        cont.SetPhone(phone); 
        contacts_[name] = cont;
    }

    void Call() {

        std::string phone, name;
       
        if(SelectOption() == "num") {
            std::cout<<"Enter the phone number:\n";
            std::cin>>phone;
            if(!CheckFormatNumber(phone)) {
                std::cout<<"\nWrong phone number\n";
                return;
            }
            std::cout<<"\nCALL to the number "<<phone<<"\n";

        } else {
            std::cout<<"Enter the name:\n";
            std::cin>>name;
            if (contacts_.count(name)) {
                std::cout<<"\nA call to the subscriber "
                <<name<<" by number "<<contacts_[name].GetPhone()<<"\n";    
            } else {
                std::cout<<"The specified name is missing from the address book";
            }
        }
    }

    void SMS() {

        std::string message, phone;
        
        std::cout<<"Enter the text of the message: ";
        std::cin.ignore();
        getline(std::cin, message);

        if(SelectOption() == "num") {
            std::cout<<"Enter the phone number:\n";
            std::cin>>phone;

            if(!CheckFormatNumber(phone)) {
                std::cout<<"\nWrong phone number\n";
                return;
            }

            std::cout<<"\nMessage \""<<message<<"\"  to the number "
            <<phone<<"\n";  

        } else {
            std::string name;
            std::cout<<"Enter the name:\n";
            std::cin>>name;
            if (contacts_.count(name)) {
                std::cout<<"\nMessage \""<<message<<"\" to the subscriber "
                <<name<<" by number "<<contacts_[name].GetPhone()<<"\n";
            } else {
                std::cout<<"The specified name is missing from the address book\n";
            }
        }
    }

private:

    std::string SelectOption() {

        std::string oper;

        do {
            std::cout<<"To call a contact from the address book select the option \"book\"\n"
            <<"To dial a phone number, select the option \"num\"\n";
            std::cin>>oper;
            if(!(oper == "book" || oper == "num"))
                std::cout<<"Wrong option\n";
        } while (!(oper == "book" || oper == "num"));    
        
        return oper;
    }

    bool CheckFormatNumber(std::string phone) {
       
        if(phone.size() != 12)  //format +7 <10 numbers>.
            return false;

        if(phone[0] != '+' || phone[1] != '7' ||  phone[2] == '0')
            return false;
        
        for (size_t i = 2; i < phone.size(); ++i) {
            if(phone[i] < '0' || phone[i] > '9')
                return false;
        }

        return true;
    } 

    std::map<std::string, Contact> contacts_;
};





int main() {

    Phone* ph = new Phone();
    std::string oper;

    while(true) {

        std::cout<<"Enter the name of the operation: ";
        std::cin>>oper;

        if (oper == "add" ) {
            ph->Add();

        } else if (oper == "call") {
            ph->Call();
        
        } else if (oper == "sms") {
            ph->SMS();

        } else if (oper == "exit") {
            std::cout<<"Turning off the phone";
            delete ph;
            ph = nullptr;
            return 0;

        } else {
            std::cout<<"\nWrong command!\n";
        }
    }

    return 1;
}



