#include <iostream>
#include <thread>
#include <mutex>

std::mutex railway_station;

struct Train 
{
    char name;
    int time;     
};

void FillTrainSchedules(Train* arr, int size_arr);

void TrainMovement(Train* train);


int main()
{
    int num_trains = 3;
    
    Train trains[num_trains];
    FillTrainSchedules(trains, num_trains);
  
    std::thread train_1(TrainMovement, &trains[0]);
    std::thread train_2(TrainMovement, &trains[1]);
    std::thread train_3(TrainMovement, &trains[2]);

    train_1.join();
    train_2.join();
    train_3.join();

    return 0;
}


void FillTrainSchedules(Train* arr, int size_arr) {

    char letter = 'A';
             
    for (int i = 0; i < size_arr; ++i) 
    {
        (arr + i)->name = letter;
        std::cout << "Enter the time for train "<< letter << ": ";
        std::cin >> (arr + i)->time;
        ++letter;
    }
}

void TrainMovement(Train* train)
{
    std::string command;

    std::this_thread::sleep_for(std::chrono::seconds(train->time));
    railway_station.lock();
    std::cout << "Train " << train->name << " arrived at the railway station" << "\n";

    do {
        std::cout << "Enter the command depart: " << "\n";
        std::cin >> command; 
    } while (command != "depart");

    std::cout << "Train " << train->name << " departs from the station" << "\n";
    railway_station.unlock();
}



