#include <vector>
#include <map>
#include <cpr/cpr.h>
#include "url_requests.h"


int main()
{
    std::string site = "http://httpbin.org";
    std::string key, value, request;
    std::map<std::string, std::string> arguments;

    std::vector<cpr::Pair> v; 
   
    std::cout << "Enter the names of the arguments and their values: " << std::endl;

    while (request != "post" && request != "get") 
    {
        do {
            std::cout << "Enter the name of the argument: ";
            std::cin >> key;
            if(arguments.count(key))
                std::cout<<"The argument with the specified name already exists"
                <<std::endl;
        } while (arguments.count(key));

        if(key != "post" && key != "get") {
                std::cout << "Enter the value: ";
                std::cin >> value;

                if(value != "post" && value != "get") {
                v.push_back(cpr::Pair((std::string)key, (std::string)value));
                arguments[key] = value;
            } else
                request = value;    
        } else 
            request = key;
    } 

    if(request == "get") UrlRequestGet(site, v);
    else if (request == "post") UrlRequestPost(site, v); 

    return 0;
}



