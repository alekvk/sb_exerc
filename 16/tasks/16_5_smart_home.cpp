#include <iostream>
#include <sstream>
#include <limits>

enum SWITCHES { 
    LIGHTS_INSIDE = 1, 
    LIGHTS_OUTSIDE = 2, 
    HEATERS = 4, 
    WATER_PIPE_HEATING = 8, 
    CONDITIONER = 16 
};


std::string DecimalToBin(int n);

              
int main() {
     
    int hour, switches_state = 0;
    std::string sensors;
    int tIn, tOut, tColor;
    std::string move, light;

    
    do {
        std::cout<<"Enter the current hour (number from 0 to 23):  ";
        std::cin>>hour;
        if (hour < 0 || hour > 23)
            std::cout<<"Incorrect hour!\n";
    } while (hour < 0 || hour > 23);

    //Добавил этот фрагмент для сброса буфера cin 
    getline(std::cin, sensors);
    std::stringstream buffer(sensors); 
    buffer>>tIn>>tOut>>move>>light;

    //std::cin.ignore(std::numeric_limits<int>::max(),' ');

    while (true) {

        

        std::cout<<"\nThe time is "<<hour<<" hour(s)  ";
        std::cout<<"(switch states: ";
        std::cout<<DecimalToBin(switches_state)<<")\n";
               
        std::cout<<"Temperature inside, temperature outside, movement, lights: ";
        getline(std::cin, sensors);
        std::stringstream buffer_sensors(sensors); 
        buffer_sensors>>tIn>>tOut>>move>>light;
       
        /*Как только температура снаружи падает ниже 0 °С, надо включить систему обогрева водопровода. 
        Если температура снаружи поднялась выше 5 °С, то систему обогрева водопровода нужно отключить.*/
        if (tOut < 0 && !(switches_state & WATER_PIPE_HEATING)) {
            switches_state |= WATER_PIPE_HEATING;
            std::cout<<"Water pipe heating ON!\n";
        } else if (tOut > 5 && (switches_state & WATER_PIPE_HEATING)) { 
            switches_state &= ~ WATER_PIPE_HEATING;
            std::cout<<"Water pipe heating OFF!\n";
        } 

        /*Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) 
        и снаружи есть какое-то движение, то необходимо включить садовое освещение. 
        Если движения нет или время не вечернее, то света снаружи быть не должно.*/
        if (move == "yes" && ( hour < 5 || hour > 16)
              && !(switches_state & LIGHTS_OUTSIDE)) {
            switches_state |= LIGHTS_OUTSIDE;
            std::cout<<"Lights outside ON!\n";
        } else if ((move == "no" || hour >= 5 || hour <= 16)
                    && (switches_state & LIGHTS_OUTSIDE)) {
            switches_state &= ~ LIGHTS_OUTSIDE;
            std::cout<<"Lights outside OFF!\n";              

        }
         
        /*Если температура в помещении упала ниже 22 °С, должно включиться отопление. 
        Как только температура равна или поднимается выше 25 °С, 
        отопление автоматически отключается.*/
        if (tIn < 22 && !(switches_state & HEATERS)) {
            switches_state |= HEATERS;
            std::cout<<"Heaters ON!\n";
        } else if (tIn >=25 && (switches_state & HEATERS)) { 
            switches_state &= ~ HEATERS;
            std::cout<<"Heaters OFF!\n";
        }   

        /*Если температура в помещении поднялась до 30 °С, 
        включается кондиционер. Как только температура становится 25 °С, 
        кондиционер отключается. */
        if (tIn >= 30 && !(switches_state & CONDITIONER)) {
            switches_state |= CONDITIONER;
            std::cout<<"Conditioner ON!\n";
        } else if (tIn <=25 && (switches_state & CONDITIONER)) { 
            switches_state &= ~ CONDITIONER;
            std::cout<<"Conditioner OFF!\n";
        } 

        /*Всё освещение в доме также умное и поддерживает настройку 
        цветовой температуры для комфортного нахождения. 
        Каждый день начиная с 16:00 и до 20:00 температура цвета 
        должна плавно изменяться с 5000K до 2700К. 
        Разумеется, это изменение должно происходить, 
        если свет сейчас включён. В 00:00 температура сбрасывается до 5000К. */
        if (light == "on" && !(switches_state & LIGHTS_INSIDE)) {
            switches_state |= LIGHTS_INSIDE;
            std::cout<<"Lights inside ON!\n";
        } else if (light == "off" && (switches_state & LIGHTS_INSIDE)) {
            switches_state &= ~ LIGHTS_INSIDE;
            std::cout<<"Lights inside OFF!\n";             
        } else if (hour >= 16 && !(switches_state & LIGHTS_INSIDE)) {
            switches_state |= LIGHTS_INSIDE;
            std::cout<<"Lights inside ON!\n";
        } else if (hour < 16 && (switches_state & LIGHTS_INSIDE)) {
            switches_state &= ~ LIGHTS_INSIDE;
            std::cout<<"Lights inside OFF!\n";             
        }

        light = "";
                        
        if ( hour < 16) tColor = 5000;
        else if (hour > 20) tColor = 2700; 
        else if (hour >= 16 && hour <= 20) tColor = 5000 - 575 *(hour - 16);
        std::cout<<"Color temperature: "<<tColor<<" K\n\n";
         
        ++hour; if (hour == 24) hour = 0;
       
    } 

    return 0;

}


std::string DecimalToBin(int n) {

    std::string tmp,bin;
    
    while (n >= 1) {
        tmp += std::to_string(n%2);
        n /=2;
    }

    if (tmp.size() < 8) {
        int k = 8 - tmp.size();
        for (int j = 0; j < k; ++j)
            tmp += "0";
    }

    for (int i = tmp.size() - 1; i >= 0; --i) 
        bin +=tmp[i];
    
    return bin;

}











