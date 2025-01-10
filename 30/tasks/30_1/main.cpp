#include <iostream>
#include <cpr/cpr.h>



int main()
{
    const std::string site = "http://www.httpbin.org/"; 
    std::string oper;

    while(true) {
        std::cout<<"Select an operation (get post put delete patch): ";
        std::cin>>oper;

        if(oper == "get") {
            cpr::Response r = cpr::Get(cpr::Url(site + oper));
            std::cout<<r.text;

        } else if(oper == "post") {
            cpr::Response r = cpr::Post(cpr::Url(site + oper));
            std::cout<<r.text;         

        } else if(oper == "put") {
            cpr::Response r = cpr::Put(cpr::Url(site + oper));
            std::cout<<r.text; 

        } else if(oper == "delete") {
            cpr::Response r = cpr::Delete(cpr::Url(site + oper));
            std::cout<<r.text;

        } else if(oper == "patch") {
            cpr::Response r = cpr::Patch(cpr::Url(site + oper));
            std::cout<<r.text;

        } else if (oper == "exit") {
            std::cout<<"Exit programm";
            return 0;
            
        } else {
            std::cout<<"Wrong name of the operation:  ";
        }
    }

    return 0;

}

