#include "str.h"


std::pair<int,int> FindIndSubstr
(std::string& str, std::string& l_str, std::string& r_str)
{
    int ind_1, ind_2;

    if (str.find(l_str) != std::string::npos) 
        ind_1 = str.find(l_str) + l_str.size();   
    else return {-1, -1};

    if(ind_1 > str.size() - 1 || str.find(r_str, ind_1 + 1) == std::string::npos) 
        return {-1,-1};
    else  ind_2 = str.find(r_str, ind_1 + 1) - 1;

    return {ind_1, ind_2};
}

std::string GetSubstr(std::string& str, int ind_beg, int ind_end) 
{
    std::string substr;

    if (ind_end > str.size() - 1)
        return substr;
    
    if (ind_beg < 0 || ind_end < 0 || ind_beg >= ind_end)
        return substr;

    for (int i = ind_beg; i <= ind_end; ++i)
        substr += str[i];

    return substr;            
}