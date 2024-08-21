#include <iostream>

template <typename Term>
void PrintArray(Term arr[][6]) {
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j)
            std::cout<<arr[i][j]<<"  ";
        std::cout<<"\n";    
    }

    std::cout<<"\n";   
}




int main() {

    std::string map[2][6] = {{"VIP","ordinary","ordinary","ordinary","ordinary","ordinary"},
                             {"VIP","ordinary","ordinary","ordinary","ordinary","ordinary"}};
    int cutlery[2][6] = { {4, 3, 3, 3, 3, 3}, {4, 3, 3, 3, 3, 3} };
    int dishes[2][6] = { {3, 2, 2, 2, 2, 2}, {3, 2, 2, 2, 2, 2} };
    int chairs[2][6] = { {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1} };
    
    std::cout<<"Placement scheme:\n";
    PrintArray(map);

    std::cout<<"chairs:\n";
    PrintArray(chairs);
    std::cout<<"The lady who came to the fifth place in the first row brought a child with her\n"
    <<"and therefore another chair was placed in this place.\n";
    chairs [1-1][5-1] +=1;
    std::cout<<"chairs:\n";
    PrintArray(chairs);
    
    std::cout<<"cutlery:\n";
    PrintArray(cutlery);
    std::cout<<"A spoon was stolen from the third place in the second row in an unknown direction\n";
    cutlery [2-1][3-1] -=1;
    std::cout<<"cutlery:\n";
    PrintArray(cutlery);

    std::cout<<"One of the VIPs (any one) shared her spoon with the one who was left without a spoon,\n"
    <<"and began to eat dessert soup.\n";
    cutlery [0][0] -=1;
    cutlery [2-1][3-1] +=1;
    std::cout<<"cutlery:\n";
    PrintArray(cutlery);
 
    std::cout<<"dishes:\n";
    PrintArray(dishes);
    std::cout<<"As unnecessary, the waiter took one dessert plate from the VIP guest.\n";
    dishes [0][0] -=1;
    PrintArray(dishes);
    
    return 0;
    
}

    