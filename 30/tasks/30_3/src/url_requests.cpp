#include "url_requests.h"

void UrlRequestGet(std::string& site, std::vector<cpr::Pair> &v)
{

    std::string arg_url = "?";

    for(int i = 0; i < v.size();)
    {
        arg_url += (v[i].key + "=" + v[i].value); 
        ++i;
        if(i != v.size())
           arg_url += "&"; //?foo=first&animal=cat&bar=third
    }
            
    cpr::Response r = cpr::Get(cpr::Url(site + "/get" + arg_url));
    std::cout << r.text <<std::endl;
}

void UrlRequestPost(std::string& site, std::vector<cpr::Pair> &v)
{
    cpr::Payload p(v.begin(), v.end());
    cpr::Response r = cpr::Post(cpr::Url(site + "/post"), p);
    std::cout << r.text <<std::endl;
  
}