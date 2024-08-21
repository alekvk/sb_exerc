#include <iostream>

int COUNT;

template <typename Term> 
void InitMatrix(Term map[][12]);

template <typename Term> 
void PrintMatrix(Term matr[][12]);

bool CheckCoordinates(int begRow, int begCol, int endRow, int endCol);

template <typename Term> 
void BurstingBubbles(int begRow, int begCol, int endRow, int endCol, Term matr[][12]);


              
int main() {

    COUNT = 0;
    bool map[12][12];
    InitMatrix(map);
    std::cout<<"\nPrint map:\n";  
    PrintMatrix(map);

    while (COUNT != 144) {

        int r1, r2, c1, c2;

        do {
            std::cout<<"Entering the coordinates of the range.\n";
            std::cout<<"Enter the line number of the beginning of the range:  ";
            std::cin>>r1;
            std::cout<<"Enter the column number of the beginning of the range:  ";
            std::cin>>c1;
            std::cout<<"Enter the line number of the end of the range:  ";
            std::cin>>r2;
            std::cout<<"Enter the column number of the end of the range:  ";
            std::cin>>c2;
        } while (!CheckCoordinates(r1, c1, r2, c2));

        BurstingBubbles(r1, c1, r2, c2, map);
        if (COUNT != 144)  std::cout<<"\nA total of "<<COUNT<<" bubbles burst!\n"; 
        else std::cout<<"\nAll the bubbles are burst!\n";
        PrintMatrix(map);
    }

    std::cout<<"\nThe program is finished!\n"; 
    return 0;
}




template <typename Term> 
void InitMatrix(Term matr[][12]) {

    std::cout<<"\nInitializing the map with values of true.\n";

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) 
            matr[i][j] = true;
    }     
}


template <typename Term>
void PrintMatrix(Term matr[][12]) {

    int cell = -1;
    for (int i = 0; i < 13; ++i) {
        if (cell != -1) {
           std::cout<<cell<<"  ";
        } else {
            std::cout<<"     ";
        }
        ++cell;
    }
    cell = 0;
    std::cout<<"\n";

    for (int i = 0; i < 13; ++i) {
        std::cout<<"___";
    }
    std::cout<<"\n";
   
         

    for (int i = 0; i < 12; ++i) {
        std::cout<<cell<<(cell < 10 ? "  | " : " | " );
        for (int j = 0; j < 12; ++j) 
            std::cout<<(matr[i][j] ?  "O" : "X")<<"  ";
        std::cout<<"\n"; 
        ++cell;   
    }

    std::cout<<"\n";   
}


bool CheckCoordinates(int begRow, int begCol, int endRow, int endCol) {

    if (begRow < 0 ||  begRow > 11 ||  begCol < 0 ||  begCol > 11 
        || endRow < 0 ||  endRow > 11 ||  endCol < 0 ||  endCol > 11) {        
            std::cout<<"\nThe value of coordinates outside the matrix!\n\n";
            return false;
    }

    return true;
}

template <typename Term> 
void BurstingBubbles(int begRow, int begCol, int endRow, int endCol, Term matr[][12]) {
           
    if (begRow == endRow && begCol == endCol ) {
        if (matr[begRow][begCol]) { 
            matr[begRow][begCol] = false;
            std::cout<<"cell["<<begRow<<", "<<begCol<<"] -  Pop!\n";
            ++COUNT;
        }
    } else if (begRow == endRow && begCol != endCol) {
        if (begCol < endCol) {
            for (int j = begCol; j <= endCol; ++j){
                if (matr[begRow][j]) {
                    matr[begRow][j] = false;
                    std::cout<<"cell["<<begRow<<", "<<j<<"] -  Pop!\n";
                    ++COUNT;
                }
            }        
        } else {
            for (int j = begCol; j >= endCol; --j){
                if (matr[begRow][j]) {
                    matr[begRow][j] = false;
                    std::cout<<"cell["<<begRow<<", "<<j<<"] -  Pop!\n";
                    ++COUNT;
                }
            }      

        }
     } else if (begRow != endRow && begCol == endCol) {
        if (begRow < endRow) {
            for (int i = begRow; i <= endRow; ++i){
                if (matr[i][begCol]) {
                    matr[i][begCol] = false;
                    std::cout<<"cell["<<i<<", "<<begCol<<"] -  Pop!\n";
                    ++COUNT;
                }
            }        
        } else {
            for (int i = begRow; i >= endRow; --i){
                if (matr[i][begCol]) {
                    matr[i][begCol] = false;
                    std::cout<<"cell["<<i<<", "<<begCol<<"] -  Pop!\n";
                    ++COUNT;
                }
            }      


        }


    }     
    
    if (begRow < endRow && begCol < endCol )  {
        for (int i = begRow; i <= endRow; ++i){
            for (int j = begCol; j <= endCol; ++j){
                if (matr[i][j]) {
                    matr[i][j] = false;
                    std::cout<<"cell["<<i<<", "<<j<<"] -  Pop!\n";
                    ++COUNT;
                }
            }      
        
        }
    } 

    if (begRow < endRow && begCol > endCol ) {
        for (int i = begRow; i <= endRow; ++i){
            for (int j = begCol; j >= endCol; --j){
                if (matr[i][j]) {
                    matr[i][j] = false;
                    std::cout<<"cell["<<i<<", "<<j<<"] -  Pop!\n";
                    ++COUNT;
                }
            }     
        }
    }

    if (begRow > endRow && begCol < endCol ) {
        for (int i = begRow; i >= endRow; --i){
            for (int j = begCol; j <= endCol; ++j){
                if (matr[i][j]) {
                    matr[i][j] = false;
                    std::cout<<"cell["<<i<<", "<<j<<"] -  Pop!\n";
                    ++COUNT;
                }  
            }
        }
    }

    if (begRow > endRow && begCol > endCol ) {
        for (int i = begRow; i >= endRow; --i){
            for (int j = begCol; j >= endCol; --j){
                if (matr[i][j]) {
                    matr[i][j] = false;
                    std::cout<<"cell["<<i<<", "<<j<<"] -  Pop!\n";
                    ++COUNT;
                }
            }      
        }
    }
    
    
} 



    










