#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>


template<typename Iter> 
void PrintConteiner(Iter beg, Iter end);

template<typename T>
auto GetUniqNumbers = [](std::vector<T> &numbers) 
{
    auto result { std::make_unique<std::vector<T>>() };
    std::unordered_set<T> numbers_set;

    for (auto &n : numbers) 
        if (numbers_set.insert(n).second)
            result->push_back(n);
        
    return result;
};


int main()
{
    {
        std::vector<int> numbers {1, 2, 2, 2, 2, 8, 4, 7, 10, 8, 1};

        PrintConteiner(std::begin(numbers), std::end(numbers));
        auto uniq_numbers = GetUniqNumbers<int>(numbers);
        auto iter_beg = std::begin(*uniq_numbers);
        auto iter_end = std::end(*uniq_numbers);
        PrintConteiner(iter_beg, iter_end);
    }

    {
        std::vector<double> numbers {1.2, 1.3, 1.3, 1.9, 1.3, 1.0};

        PrintConteiner(std::begin(numbers), std::end(numbers));
        auto uniq_numbers = GetUniqNumbers<double>(numbers);
        auto iter_beg = std::begin(*uniq_numbers);
        auto iter_end = std::end(*uniq_numbers);
        PrintConteiner(iter_beg, iter_end);
    }
  
    return 0;
}




template<typename Iter> 
void PrintConteiner(Iter beg, Iter end)
{
    for (Iter it = beg; it != end; ++it)
        std::cout<<*it<<"  ";
        
    std::cout<<std::endl;
}