#include <iostream>
#include <vector>


struct PairNum
{
    int i = 0;
    double d = 0.0;
};


class Num
{
public:
    Num (std::initializer_list<PairNum> _nums)
    : nums (_nums)
    {}    

private:
    std::vector<PairNum> nums;
 
};

int main()
{
    std::vector<PairNum> pair_nums {{}, {2, 1.23}, {3, 5.6}, {4, 1.0}, {5, 4.4}};
    
    for (auto p : pair_nums)
        std::cout<<p.i<< " ";
    
    std::cout << "\n";
}