#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


template <typename Term>
bool CheckSector (int num, Term& cont); 

std::string GetTextSymbols(std::string path_file);

std::string GetTextLines(std::string path_file);


int main() {

    int gamers = 0, viewers = 0; 
    int sector = 1, round = 1;
    std::string template_path = "C:\\pract_exercises\\19\\tasks\\19_5\\";

    std::vector<int> nums;
    
    while (gamers != 6 && viewers != 6) {
   
        int offset;
        std::string path; 
        std::cout<<"\nRound "<<round<<"!\n";
        std::cout<<"Enter the offset: ";
        std::cin>>offset;
        sector = (sector + offset) % 13;
        sector = (sector != 0 ? sector : 13);

        while (CheckSector(sector, nums)) {
            sector = (++sector) % 13;
            sector = (sector != 0 ? sector : 13);
        } 
                
        nums.push_back(sector);
        std::cout<<"Sector "<<sector<<"\n";

        path = template_path + "question_" + std::to_string(sector) + ".txt";
        std::cout<<"Question:\n"<<GetTextLines(path);
        std::cout<<"\nEnter your answer:\n";

        std::string answer;
        std::cin>>answer;
        path = template_path + "answer_" + std::to_string(sector) + ".txt";
        std::string right_answer = GetTextSymbols(path);

        if (answer == right_answer) {
            ++gamers;
            std::cout<<"The answer is correct!\n";
        } else {
            ++viewers;
            std::cout<<"The answer is wrong!\n";
        }

        std::cout<<"Right answer: "<<right_answer<<"\n";
        std::cout<<"Game Score  "<<gamers<<" : "<<viewers<<"\n";
        ++round;
        
    }

    std::cout<<"\nThe "<<( gamers > viewers ? "gamers" : "viewers")<<" won!"; 

}







template <typename Term>
bool CheckSector (int num, Term& cont) {
    
    auto result{std::find(begin(cont), end(cont), num)};
    return !(result == end(cont));
}



std::string GetTextSymbols(std::string path_file){

    std::string text;
    std::ifstream file;
    file.open(path_file);
    
    if (!file.is_open()) 
        std::cout<<"File opening error";
    
    while (!file.eof()) {
        char symb;
        file>>symb;
        if(!file.eof())
            text += symb;
    }

    file.close();
    return text;
}



std::string GetTextLines(std::string path_file){

    std::string text;
    std::string str;
    std::ifstream file;
    file.open(path_file);
    
    if (!file.is_open()) 
        std::cout<<"File opening error";

    while (getline(file,str))
        text += (str + "\n");  
    
    file.close();
    
    return text;
}












