#include <iostream>
#include <vector>


template <typename Conteiner_, typename Conteiner>
float Sum(Conteiner_ prices, Conteiner items) {

    float sum = 0;
    
    for (int i : items) {
        if (i < 0 || i > prices.size() - 1 || prices[i] <= 0)
            return -1;
        sum += prices[i];      
    }

    return sum;
}



int main() {
   
    std::vector<float> prices {2.5, 4.25, 3.0, 10.0};
    std::vector<int> items {1, 1, 0, 3};

    std::cout<<"The total cost: " << Sum(prices, items);

    return 0;
    
}