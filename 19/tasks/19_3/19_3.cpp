#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> Parse(std::string str); 

int main() {

    std::string first_name_max, last_name_max;
    std::string str;
    int sum_salary = 0, salary_max = -1;
    
    std::string path_file = "C:\\pract_exercises\\19\\tasks\\19_3\\payment_statement.txt";
    std::ifstream file; 
    file.open(path_file);
        
    while (getline(file,str)) {
      
        std::vector<std::string> s = Parse(str);
        int salary = std::stoi(s[2]);
        sum_salary += salary;
              
        if (salary > salary_max) {
            first_name_max = s[0];
            last_name_max = s[1];
            salary_max = salary;
        } 
        
    }

    std::cout<<"\nTotal amount of funds paid: "<<sum_salary;
    std::cout<<"\n\nThe person with the maximum payout amount.";
    std::cout<<"\nfirst_name: "<<first_name_max;
    std::cout<<"\nlast_name: "<<last_name_max;
    std::cout<<"\nsalary: "<<salary_max;
}
    







std::vector<std::string> Parse(std::string str) {

	std::vector<std::string> words;
    std:: string word;
    int j = 0;
    
    for (int i = 0; i < str.size() && j < 3 ; ++i) {
        if (str[i] == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                ++j;
                word.clear();
            }
        } else {
            word += str[i];
        }
    }

	return words; 
}