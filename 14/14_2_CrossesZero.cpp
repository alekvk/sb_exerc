#include <iostream>
#include <vector>
#include <algorithm>


template <typename Term> 
void PrintArray(Term arr[3][3]); 

template <typename Term> 
bool CheckWin(char c, Term arr[][3]);

template <typename Conteiner, typename Term> 
bool findValue(Conteiner& cont, Term term);


int main() {
        
    char map[3][3] = { {' ', ' ',' '},  {' ', ' ',' '}, {' ', ' ',' '} };
    int countCell = 0; 
    bool flag = true, win = false;
    int winner = 0;
    std::vector<int> nums;
    
    while (countCell < 9 && !win) {
        int n;
        bool correctNum;
                       
        do {
            correctNum = true;
            PrintArray(map);
            std::cout<<"The move is made by the player number " <<(flag ? 1 : 2)<<"\n";
            std::cout<<"Enter the cell number: ";
            std::cin>>n;
            if (n < 1 || n > 9) {
               std::cout<<"You must enter a number from 1 to 9\n";
               correctNum = false;
               continue;
            }
            if (findValue(nums, n) ) {
                std::cout<<"Cell "<<n<<" is already occupied\n";
                correctNum = false;
            }
        } while (!correctNum);

        ++countCell;
        map[(n - 1)/3][(n - 1)%3] = flag ? 'x' : '0';
        nums.push_back(n);

        if (countCell > 4) {
            char c = flag ? 'x' : '0'; 
            if ( CheckWin(c, map) ) {
                win = true;
                winner = flag ? 1 : 2; 
            } 
        }

        flag = !flag; 
    }

    if (winner == 0) std::cout<<"\nA draw result!\n";
    else std::cout<<"\nThe number " <<winner<<" player won!\n";
    PrintArray(map);

}

template <typename Term>
void PrintArray(Term arr[3][3]) {

    int cell = 1;
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout<<cell<<" - ";
            std::cout<<arr[i][j]<<"  ";
            ++cell;
        }    
        std::cout<<"\n";    
    }

    std::cout<<"\n";   
}

template <typename Conteiner, typename Term>
bool findValue (Conteiner& cont, Term term) {
    auto result{std::find(begin(cont), end(cont), term)};
    return result != end(cont);
}




template <typename Term>
bool CheckWin(char c, Term arr[][3]) {
    int countCell;

    for (int i = 0; i < 3; ++i) {
        countCell = 0;
        for (int j = 0; j < 3; ++j) {
            if (arr[i][j] != c ) break;
            ++countCell; 
        }
        if (countCell == 3) return true;
    }

    for (int j = 0; j < 3; ++j) {
        countCell = 0;
        for (int i = 0; i < 3; ++i) {
            if (arr[i][j] != c ) break;
            ++countCell;
        }
        if (countCell == 3) return true; 

    }

    countCell = 0;
    for (int i = 0; i < 3; ++i) {
        if (arr[i][i] != c ) break;
        ++countCell;
    }
    if (countCell == 3) return true;    
   
    countCell = 0;
    for (int i = 2, j = 0; i >= 0 && j < 3 ; --i, ++j) {
        if (arr[i][j] != c ) break;
        ++countCell;
    }
    if (countCell == 3) return true;   

    return false;

}







