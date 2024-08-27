#include <iostream>
#include <vector>
#include <algorithm>

template <typename Conteiner>
void PrintConteiner(Conteiner& conteiner); 


              
int main() {
    std::cout<<"To exit the program, the number is -2\n";
    std::cout<<"To output fifth highest number, the number is -1\n";

    std::vector<int> nums;
    int count = 1;
    int sizeVector = 5;
    int maxNum;
    
    
    for(;;) {

        int num;
        std::cout<<"input number: ";
        std::cin>>num; 

            if (num == - 2) {
                std::cout<<"\nThe work of the program is finished!";
                return 0;
            } else if (num == -1) {
                if (nums.size() < 5) {
                    std::cout<<"Less than five digits have been entered!\n";
                    continue;
                }
                std::cout<<"Contents of the container: ";
                PrintConteiner(nums);
                std::cout<<"The fifth highest number: "<<nums[4]<<"\n\n";
            } else {
                if (count > sizeVector) {
                    if (num < maxNum) {
                        nums.pop_back();
                        nums.push_back(num);
                        sort(nums.begin(), nums.end());
                        maxNum = nums[size(nums) - 1];
                    } 
                } else if (count < sizeVector) {
                    nums.push_back(num);
                    ++count;
                } else {
                    nums.push_back(num);
                    sort(nums.begin(), nums.end());
                    maxNum = nums[size(nums) - 1];
                    count = 6;
                } 
            }
    }

    return 0;
}




template <typename Conteiner>
void PrintConteiner(Conteiner& conteiner) {
    
    for (auto c : conteiner)
        std::cout<<c<<" ";
    std::cout<<"\n"; 
}