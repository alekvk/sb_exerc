#include <iostream>
#include <string>
#include <map>

std::map<std::string, int> QUEUE;


int main(){
    
    std::string str;    

    while (true) {
                
        std::cout<<"Enter a last name or command \"Next\"\n"
        <<"listing - \"list\"  for exit programm - \"q\"\n";
        std::cin>>str;

        if (str == "Next") {
            std::map<std::string, int>::iterator it = QUEUE.begin();
            std::string lname = it->first;
            std::cout<<lname<<"\n";
            if (QUEUE[lname] > 1)
                --QUEUE[lname];
            else  QUEUE.erase(it);

        } else if (str == "List" || str == "list") {
            for(auto& p: QUEUE)
                std::cout<<p.first<<" "<<p.second<<"\n";
            std::cout<<"\n";

        } else if (str == "q") {
            std::cout<<"\nExit program";
            return 0;  

        } else {
            QUEUE[str]++;        
        }
  }
}