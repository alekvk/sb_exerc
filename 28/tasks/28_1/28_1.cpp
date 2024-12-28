#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

const int DISTANCE = 100;
std::mutex output;

struct Swimmer 
{
    std::string name;
    double speed;
    int time;     
};

void swim(Swimmer* swimmer, int id_swimmer, std::vector<int>* results)
{
    int i = 1;
        
    for (double way = 0; way < DISTANCE; ++i)
    {
        output.lock();
        std::cout << i << " sec ";
        way += swimmer->speed;

        if (way >= DISTANCE)
        {
            swimmer->time = i;
            results->push_back(id_swimmer);
            way = DISTANCE;
        }

        std::cout << swimmer->name << "  " << way << std::endl;
        output.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
}


int main()
{
    int num_swimmers = 6;
    Swimmer swimmers[num_swimmers];
    std::vector<int> results;
          
    for (int i = 0; i < num_swimmers; ++i) 
    {
        std::cout << "Enter the name of swimmer number " << i + 1 << ": ";
        std::cin >>  swimmers[i].name;
        std::cout << "Enter the speed of swimmer number " << i + 1 << ": ";
        std::cin >> swimmers[i].speed; 
     
    }
    
    std::thread swimmer_1(swim, &swimmers[0], 0, &results);
    std::thread swimmer_2(swim, &swimmers[1], 1, &results);
    std::thread swimmer_3(swim, &swimmers[2], 2, &results);
    std::thread swimmer_4(swim, &swimmers[3], 3, &results);
    std::thread swimmer_5(swim, &swimmers[4], 4, &results);
    std::thread swimmer_6(swim, &swimmers[5], 5, &results);

    swimmer_1.join();
    swimmer_2.join();
    swimmer_3.join();
    swimmer_4.join();
    swimmer_5.join();
    swimmer_6.join();
   
    for (int i = 0; i < num_swimmers; ++i)
    {
        std::cout << i + 1 << "  "<< swimmers[results[i]].name << "  " 
        << swimmers[results[i]].time << " sec." << std::endl;
        //swimmers[(*results)[i]] 
    }

    return 0;
}


    