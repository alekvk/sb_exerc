#include <iostream>
#include <string>
#include <map>


bool IsAnagrams(std::string s1, std::string s2) { 

    if (s1.length() != s2.length())  
        return false;
    
    std::map<char, int> m1, m2;
    
    for (size_t i = 0; i < s1.length(); ++i) {
        m1[s1[i]]++;  m2[s2[i]]++;
    }

    return m1 == m2;
}

int main() {
    
    std::string str1, str2; // lekarstvo steklovar

    std::cout<<"Enter the first line:  ";
    std::cin>>str1;
    std::cout<<"Enter the second line:  ";
    std::cin>>str2;
        
    std::cout<<"Strings are "<<(IsAnagrams(str1, str2)? "":"not ")<<"anagrams ";      

    return 0;    
}