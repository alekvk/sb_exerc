#include <iostream>
#include <cpr/cpr.h>
#include "str.h"





int main()
{
    using namespace cpr;
    std::string l_str = "<h1>", r_str = "</h1>";
    std::string site = "http://www.httpbin.org";
      
    Response r = Get(Url(site + "/html"), Header{{"accept","text/html"}});
    auto p = FindIndSubstr(r.text, l_str, r_str);
    std::cout<<GetSubstr(r.text, p.first, p.second); 
 
    return 0;
}

