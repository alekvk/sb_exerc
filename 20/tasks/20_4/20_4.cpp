#include <iostream>
#include <fstream>
#include <map>


const int MAX_NUMBER_BILLS = 1000;
int NUMBER_BILLS;
int TOTAL_SUM = 0;
std::map<int,int> BILLS;

enum bill {
    bill_100 = 100,
    bill_200 = 200,
    bill_500 = 500,
    bill_1000 = 1000,
    bill_2000 = 2000,
    bill_5000 = 5000
};

bool GetMoney(int request_money);

void CalculateTotalSum();

void CalculateNumberBills();

void WriteFile(std::ofstream & atm_out); 

void GetStatusATM(); 

void FillATM(); 



int main() {

    srand(time(nullptr));
    std::string path = "atm.bin";
    std::ifstream atm_in(path, std::ios::binary);

    if (!atm_in.is_open()) {
        std::cout<<"The ATM is not working";
        return 1;
    }

    std::cout<<"Current status of the ATM:\n";

    int bill, count;
    while (!atm_in.eof()) {
        atm_in>>bill>>count;
        if(bill != 0) 
            BILLS[bill] = count;
        std::cout<<"bill: "<<bill<<"   "<<"count: "<<count<<"\n";
    }

    atm_in.close();
    CalculateTotalSum();
    CalculateNumberBills();
    std::cout<<"Total sum "<<TOTAL_SUM;
            
    while(true) {
        
        std::string oper;
        std::cout << "\n\nTake money \"-\"     "
        <<"Fill the ATM \"+\"     Exit the program \"q\"\n";
        std::cin >> oper;

        if (oper == "-") {
            int money;
            std::cout<<"Enter the required amount of money: ";
            std::cin >> money;

            if (money <= 0) {
                std::cout<<"\nAn incorrect number has been entered";
                continue;
            } else if (money > TOTAL_SUM) {
                std::cout<<"\nThere is not enough money at the ATM.\n"
                <<"The total amount in the ATM is "<<TOTAL_SUM;
                continue;
            }

            if (!GetMoney(money)) {
                std::cout<<"\nThe requested amount cannot be issued "
                <<"with the bills that are in the ATM";
                GetStatusATM();
                continue; 
            }

            GetStatusATM();
            CalculateTotalSum();
            CalculateNumberBills();
            std::cout<<"Total sum "<<TOTAL_SUM;
          
     
        } else if (oper == "+") {
            FillATM();
            GetStatusATM();
            CalculateTotalSum();
            std::cout<<"Total sum "<<TOTAL_SUM;
        } else if (oper == "q") {
            std::ofstream atm_out(path);
            WriteFile(atm_out);
            atm_out.close();
            std::cout<<"\nThe ATM program has been finished";
            return 0;
        } else {
            std::cout << "\nIncorrect input";
            continue;
        }

         
    }
 
    return 1;
 
}











void WriteFile(std::ofstream & atm_out) {

    for (auto [bill, count] : BILLS)
        atm_out<<bill<<" "<<count<<"\n";
}


bool GetMoney(int request_money) {

    int n_5000 = BILLS[bill_5000]; 
    int give_5000 = 0;
    if (request_money >= bill_5000 && n_5000 != 0 ) {
        give_5000 = request_money / bill_5000;
        if (give_5000 > n_5000) give_5000 = n_5000;
        request_money -=(give_5000 * bill_5000); 
    }

    int n_2000 = BILLS[bill_2000]; 
    int give_2000 = 0;
    if (request_money >= bill_2000 && n_2000 != 0 ) {
        give_2000 = request_money / bill_2000;
        if (give_2000 > n_2000) give_2000 = n_2000;
        request_money -=(give_2000 * bill_2000); 
    }

    int n_1000 = BILLS[bill_1000];
    int give_1000 = 0;
    if (request_money >= bill_1000 && n_1000 != 0 ) {
        give_1000 = request_money / bill_1000;
        if (give_1000 > n_1000) give_1000 = n_1000;
        request_money -=(give_1000 * bill_1000); 
    }

    int n_500 = BILLS[bill_500]; 
    int give_500 =0;
    if (request_money >= bill_500 && n_500 != 0 ) {
        give_500 = request_money / bill_500;
        if (give_500 > n_500) give_500 = n_500;
        request_money -=(give_500 * bill_500); 
    }

    int n_200 = BILLS[bill_200];
    int give_200 = 0; 
    if (request_money >= bill_200 && n_200 != 0 ) {
        give_200 = request_money / bill_200;
        if (give_200 > n_200) give_200 = n_200;
        request_money -=(give_200 * bill_200); 
    }

    int B_100 = BILLS[bill_100];
    int give_100 = 0; 
    if (request_money >= bill_100 && B_100 != 0 ) {
        give_100 = request_money / bill_100;
        if (give_100 > B_100) give_100 = B_100;
        request_money -=(give_100 * bill_100); 
    }

    if (request_money == 0) {

        BILLS[bill_5000] -= give_5000; 
        BILLS[bill_2000] -= give_2000; 
        BILLS[bill_1000] -= give_1000;
        BILLS[bill_500] -= give_500; 
        BILLS[bill_200] -= give_200;
        BILLS[bill_100] -= give_100;

        std::cout<<"Issuing money: \n";
        if (give_5000 != 0) std::cout<<give_5000<<" bills of "<<bill_5000<<"   ";
        if (give_2000 != 0) std::cout<<give_2000<<" bills of "<<bill_2000<<"   "; 
        if (give_1000 != 0) std::cout<<give_1000<<" bills of "<<bill_1000<<"   ";
        if (give_500 != 0) std::cout<<give_500<<" bills of "<<bill_500<<"   ";
        if (give_200 != 0) std::cout<<give_200<<" bills of "<<bill_200<<"   "; 
        if (give_100 != 0) std::cout<<give_100<<" bills of "<<bill_100;

        return true;

    } else {

        return false;
    }
}


void FillATM() {

    int banknotes[] = {bill_100, bill_200, bill_500, bill_1000, bill_2000, bill_5000};
    
    for (int i = 0; i < MAX_NUMBER_BILLS - NUMBER_BILLS; ++i) {
        BILLS[banknotes[rand() % 6]]++;
    }

    NUMBER_BILLS = 1000;
}



void CalculateTotalSum() {

    int sum = 0;

    for (auto& [bill, count] : BILLS)
        sum += (bill * count);

    TOTAL_SUM = sum;       

}

void CalculateNumberBills() {

    int sum = 0;

    for (auto& [bill, count] : BILLS)
        sum += count;

    NUMBER_BILLS = sum; 
}


void GetStatusATM() {
    
    std::cout<<"\nThe current status of the ATM:\n";

    for (auto&[bill, count] : BILLS)
        std::cout<<"bill "<<bill<<"  "<<"count "<<count<<"\n";

}













    

















