#include <iostream>
#include <vector>
#include <iomanip>

struct task {std::string name; double duration;};

std::vector<task> COMPLETED_TASKS;

void PrintTasks(std::time_t begin, std::string name);
void WriteTask(std::time_t begin, std::string name); 


int main() {

    bool task = false;
    std::string exist_task, oper;
    std::time_t beg;

    while (true) {
        std::cout<<"Enter the command: ";
        std::cin>>oper;

        if (oper == "begin") {
            if(task) 
                WriteTask(beg, exist_task); 
            std::cout<<"Enter the name of the task: ";
            std::cin>>exist_task;
            beg = std::time(nullptr);
            task = true;

        } else if (oper == "end") {
            if(!task) {
                std::cout<<"\nThere is no current started task\n";
            } else {
                WriteTask(beg, exist_task); 
                task = false;
                exist_task ="";
            }

        } else if (oper == "status") {
            PrintTasks(beg, exist_task); 

        } else if (oper == "exit") {
            std::cout<<"\nExit program";
            return 0; 

        } else {
            std::cout<<"\nThe wrong command\n";
        }
    }

    return 1;
}



void WriteTask(std::time_t begin, std::string name) {

    std::time_t end = std::time(nullptr);
    double duration = std::difftime(end, begin)/3600;
    COMPLETED_TASKS.push_back({name, duration});
}


void PrintTasks(std::time_t begin, std::string name) {

    std::cout<<"Completed tasks:\n";
    for (auto& i : COMPLETED_TASKS) 
        std::cout<<"task - "<<i.name<<"  "
        <<"time spent - "<<i.duration<<"\n";

    if(name.size() == 0)
        std::cout<<"\nThe current task is missing"<<"\n";
    else 
        std::cout<<"\nCurrent task - "<<name<<" started at "
        <<std::put_time(std::localtime(&begin),"%H:%M")<<"\n\n";
}