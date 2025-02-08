#include <iostream>

class CastFishException {
public:
    CastFishException(int _code) 
    {
        if(_code < 0 || _code > 1)
            code = 2;
        else
           code = _code;        
    }

    CastFishException() : code(2)
    {}

    char* what() const {
        return str_what[code]; 
    }

    int getCode() const {
        return code; 
    }

private:
    int code;
    char* str_what[3] = {
                        "You have caught a boot!", 
                        "You have caught a fish!",
                        "An unforeseen situation"
                        };
};

template <typename Term>
void PrintArr(Term (*ar)[4], int size); 

template <typename Term>
void FillArr(Term (*arr)[4], int size, int fish, int boot );

template <typename Term>
void CastFishing(Term (*arr)[4], int sector) 
{
    int col = 4;
    sector --;
    
    if (arr[(sector) /col ][(sector) % col] == 'f') {
        throw CastFishException(1);
    }
    
    if (arr[(sector) /col ][(sector) % col] == 'b') {
        throw CastFishException(0);
    }    

}



int main() {
    
    int fish = 1, boot = 3;
    int row = 3, col = 4;
    int countCell = row * col; 
    int attempts = 0;
    char pond[3][4] = { {'0','0','0','0'}, {'0','0','0','0'}, {'0','0','0','0'} };

    PrintArr(pond, row); 
    FillArr(pond, row, fish, boot); 
    PrintArr(pond, row); 
        
    while (true) {
        int n;
        bool num = true;
                       
        do {
            std::cout<<"Enter the cell number: ";
            std::cin>>n;
            if (n < 1 || n > countCell) {
               std::cout<<"You must enter a number from 1 to "<<countCell<<"\n";
               num = false;
               continue;
            }
            
        } while (!num);

        ++attempts;

        try
        {
            CastFishing(pond, n);
        }
        
        catch(const CastFishException& x)
        {
            std::cerr << "Caught exception.  " << x.what() << std::endl;
            if(x.getCode())
                std::cout<<"Number of attempts "<<attempts;
            return 0;
        }
    }
}


template <typename Term>
void PrintArr(Term (*ar)[4], int size) {

    for (int r = 0; r < size; ++r) 
    {
        for (int c = 0; c < 4; ++c) 
            std::cout<<ar[r][c]<<" ";
        std::cout<<std::endl;    
    }

    std::cout<<std::endl;    
}

template <typename Term>
void FillArr(Term (*arr)[4], int size, int fish, int boot )
{
    std::srand(time(nullptr));
    int count_cell = 4 * size;
    
    for(int i = 0; i < fish;) {
        int n = rand() % (count_cell - 1);
        if (arr[n / 4 ][n % 4] == '0') {
            arr[n / 4 ][n % 4] = 'f';
            ++i;    
        }
    } 

    for(int i = 0; i < boot;) {
        int n = rand() % (count_cell - 1);
        if (arr[n / 4 ][n % 4] == '0') {
            arr[n / 4 ][n % 4] = 'b';
            ++i;    
        }
    }      
}




