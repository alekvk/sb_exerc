/*
Задание 3. Симуляция игры «Рыбалка»
Что нужно сделать
Реализуйте простую симуляцию игры в рыбалку. 

В исходном текстовом файле реки (river.txt) задайте список из разных видов рыб, 
которые можно в ней поймать. Рыбок может быть сколько угодно, а виды могут повторяться.

Как должна работать симуляция:

В начале программы пользователь указывает, какую именно рыбу 
он собирается ловить (её вид). 
После этого из первого файла друг за другом осуществляется чтение его содержимого, 
вид за видом.
Если на отдельных шагах вид совпал с указанным пользователем, 
в выходной файл basket.txt (корзинка) записывается этот вид.
В конце программы показывается, сколько было поймано рыб за текущую ловлю. 
Программу можно запускать несколько раз, при этом уже пойманные рыбы 
должны сохраняться в файле-корзинке.

Рекомендация
Пример содержания исходного файла:

sunfish
shad
carp
bass
bullhead
carp
walleye
catfish
carp


*/

#include <iostream>
#include <fstream>



void PrintFile(std::string path); 



int main() {

    std::string river_path = "river.txt", basket_path = "basket.txt";
    std::string fish;

    std::cout<<"Enter the name of the fish: ";
    std::cin>>fish;
      
    std::ifstream river(river_path);
    if(!river.is_open())  {
        std::cout<<"File "<<river_path<<" opening error";
        return 1;
    }

    std::ofstream basket(basket_path, std::ios::app);
    if(!basket.is_open()) {
        std::cout<<"File "<<basket_path<<" opening error";
        return 1;
    }

    while(!river.eof()) {
        std::string word;
        river>>word;
        if (word == fish) 
            basket<<word<<"\n";
    }

    basket.close();

    PrintFile(basket_path);

    return 0;
 
}







void PrintFile(std::string path) {

    char ch; 
    std::ifstream file(path);

    if (file.is_open()) {
        std::cout<<"Here are the current contents of the "
        <<path<<" file:\n";
        while(file.get(ch)) 
            std::cout<<ch;
        file.close();
        std::cout<<"\n";    
    }
} 
