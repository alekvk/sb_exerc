/*Задание 2. Реализация программы напоминания о днях рождения
Что нужно сделать

Реализуйте простую программу по вычислению ближайшего дня рождения.
В начале программы пользователь последовательно вводит данные 
о днях рождения своих друзей: вводит имя друга и саму дату рождения полностью, 
включая месяц и год, в формате год/месяц/день. 
Сигналом окончания ввода дней рождения является “end” введённое в качестве имени.

После этого программа вычисляет ближайший день рождения по отношению 
к текущему времени и выводит его на экран вместе с именем в удобном, 
локальном формате - месяц/день. Если день рождения уже был в этом году, 
данные о пользователе пропускаются. 
Если у кого-то из друзей день рождения сегодня, 
то в консоль выводится специальное сообщение об этом. 
Учтите, что таких сообщений может быть несколько, 
ведь сразу несколько людей могут иметь дни рождения в один день.

Советы и рекомендации

Для подсчёта ближайшего дня используйте данные из структуры даты std::tm.*/


#include <iostream>
#include <vector>
//#include <ctime>
#include <iomanip>


struct person{std::string name; tm birthday;};
std::vector<person> BIRTHDAYS;


bool IsBirthToday(tm today, tm birth);
void Congrat(std::string name);
void PrintBirthdays();



int main() {

    std::time_t t1 = time(nullptr);
    std::tm today = *std::localtime(&t1);
    int near_day = 31, near_month = 11;
    
    
    while (true) {

        std::string name;
        std::cout<<"Enter the name: ";
        std::cin>>name;

        if(name == "end") break;

        if(name == "print") {
            PrintBirthdays();
            continue;     
        } 
        
        std::time_t t2 = std::time(nullptr);
        std::tm birth = *std::localtime(&t2);
        std::cout<<"Enter your birthday in the format yyyy/mm/dd: ";
        std::cin>>std::get_time(&birth, "%y/%m/%d");

        if(IsBirthToday(today, birth)) {
            Congrat(name);
            continue;
        }

        if(today.tm_mon > birth.tm_mon
            ||(today.tm_mon == birth.tm_mon 
                && today.tm_mday > birth.tm_mday)) {
            continue;        
        }

        if(birth.tm_mon < near_month
            ||(birth.tm_mon ==  near_month
                && birth.tm_mday < near_day)) {
            near_day = birth.tm_mday; 
            near_month = birth.tm_mon;        
        }

        BIRTHDAYS.push_back({name, birth});
    }

    for(auto& i : BIRTHDAYS) {
        if(i.birthday.tm_mday == near_day
           && i.birthday.tm_mon == near_month) {
            std::cout<<"name: "<<i.name<<"  "<<near_month + 1
            <<"/"<<near_day<<"\n";
        }
    }

    return 0;
}


bool IsBirthToday(tm today, tm birth){

    if (today.tm_mon != birth.tm_mon)
        return false;

    if(today.tm_mday != birth.tm_mday)
        return false;

    return true;        
}

void Congrat(std::string name) {

    std::cout<<"\nDear "<< name<<"! "
    <<"\nHappy birthday to you!!!\n";
} 

void PrintBirthdays(){

    for(auto& i : BIRTHDAYS)
        std::cout<<"name: "<<i.name<<"  "
        <<"birthday: "<<std::put_time(&(i.birthday),"%y/%m/%d")<<"\n";
}