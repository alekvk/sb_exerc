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

void ReadFile(std::ifstream& atm);

void WriteFile(std::ofstream& atm); 

void GetStatusATM(); 

void FillATM(); 



int main() {

    std::string path = "atm.bin";
    srand(time(nullptr));
    std::ifstream atm_in(path);

    if (atm_in.is_open()) {
        std::cout<<"Current status of the ATM:\n";
        ReadFile(atm_in);
        atm_in.close();
        CalculateTotalSum();
        CalculateNumberBills();
        std::cout<<"Total sum "<<TOTAL_SUM;
    } else 
        std::cout<<"The ATM is empty"; 
            
    while(true) {
        std::string oper;
        std::cout << "\n\nTake money \"-\"     "
        <<"Fill the ATM \"+\"     Exit the program \"q\"\n";
        std::cin >> oper;

        if (oper == "-") {
            int money;
            std::cout<<"Enter the required amount of money: ";
            std::cin >> money;

            if (money < 100) {
                std::cout<<"\nAn incorrect number has been entered";
                continue;

            } else if (money % 100 != 0) {
                std::cout<<"\nThe requested amount is not a multiple of 100";
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
            std::ofstream atm_out(path, std::ios::binary);
            WriteFile(atm_out);
            atm_out.close();
            std::cout<<"\nThe ATM program has been finished";
            return 0;

        } else {
            std::cout << "\nIncorrect input";
            continue;
        }
    }
     
}



void ReadFile(std::ifstream& atm) {

    while (!atm.eof()) {
        int bill, count;
        atm.read((char*)&bill, sizeof(bill));
        atm.read((char*)&count, sizeof(count));
        if(!atm.eof()) {
            BILLS[bill] = count;
            std::cout<<"bill: "<<bill<<"   "<<"count: "<<count<<"\n";    
        }
    }    
}


void WriteFile(std::ofstream& atm) {

    for (auto [bill, count] : BILLS) {
        atm.write((char*)&bill, sizeof(bill));
        atm.write((char*)&count, sizeof(count));
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





bool GetMoney(int request_money) {

    int banknotes[] = {bill_100, bill_200, bill_500, bill_1000, bill_2000, bill_5000};
    int give_banknotes[6] = {0, 0, 0, 0, 0, 0};

    for (int i = 5; i >= 0; --i) {
        int banknote = banknotes[i];
        int count_banknotes = BILLS[banknote];
        int give = 0;

        if (request_money >= banknote && count_banknotes != 0) {
            give = request_money / banknote;
            if (give > count_banknotes) 
                give = count_banknotes;
            request_money -= (give * banknote);
            give_banknotes[i] = give;
        }
    }

    if (request_money == 0) {
        std::cout<<"Issuing money: \n";

        for (int i = 5; i >= 0; --i) {
            int banknote =  banknotes[i];
            int count = give_banknotes[i]; 
            BILLS[banknote] -= count;
            if (count != 0)
                std::cout<<count<<" banknotes of "<<banknote<<"   ";   
        }

        return true;

    } else {
        return false;
    }
}










    

















