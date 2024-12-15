#include <iostream>
#include <cmath>
#include <vector>

enum Task { N, A, B, C };

class PersonCompany 
{

public:
      
    PersonCompany(std::string name) : name_(name)
    {} 
   
    std::string GetName() 
    {
        return name_;
    }

private:
    std::string name_;
}; 


class Employee : public PersonCompany  
{
public:
    
    Employee (std::string name, Task task = N, bool IsBusy = false) :
            task_(task), isBusy_(IsBusy), PersonCompany(name)  
    {}

    std::string getNameTask() {
        if (task_ == A) return "A";
        else if (task_ == B) return "B";
        else if (task_ == C) return "C";
        else return "N";
    }

    void SetBusy(bool isBusy)
    {
        isBusy_ =  isBusy;   
    }

    void SetTask(Task name) {
        task_ = name;
    }

    bool GetBusy() 
    {
        return isBusy_;
    }

private:
    bool isBusy_;
    Task task_;
};


class Manager : public PersonCompany
{
public:
   
    Manager(int id_manager, std::string name, int num_employees) : 
        id_manager_(id_manager),
        num_employees_(num_employees),
        PersonCompany(name)
    {
        for (int i = 0; i < num_employees_; ++i)
        {
            std::string name; 
            std::cout<<"Enter the name of the employee: ";
            std::cin>>name;
            Employee* empl = new Employee(name);
            employees.push_back(empl);
        }        
    }

    int GetIdManager() 
    {
        return id_manager_;
    } 

    int GetEmployeesSize() 
    {
        return employees.size();
    } 

    std::vector<Employee*> GetEmployees() 
    {
        return employees;
    } 
    
private:
    int id_manager_;
    int num_employees_;
    std::vector<Employee*> employees;
};


class Head : public PersonCompany {
public:

    Head(std::string name, int num_teams) :
        num_teams_(num_teams),
        PersonCompany(name)
            
    {
        for (int i = 1; i <= num_teams; ++i)
        {
            int num;
            std::string name;
            std::cout <<"Enter the number of employees in the team "<< i <<": ";
            std::cin >> num;
            std::cout<<"Enter the name of the manager: ";
            std::cin >> name; 
            Manager* manager = new Manager(i, name, num);
            managers.push_back(manager);

        }
    } 

    bool TaskStart(int taskID) {

        bool allEmployeesAreBusy = true;

        for (int i = 0; i < managers.size(); ++i){
            Manager* manager = managers[i];
            srand(taskID + manager->GetIdManager());
            int numberTasks = rand() % (manager->GetEmployeesSize() + 1);
            
            for (int j = 0; j < manager->GetEmployeesSize() && numberTasks > 0; ++j){
                Task typeTask = static_cast<Task>(rand() % 3 + 1);
                Employee* empl = manager-> GetEmployees()[j];

                if (!(empl->GetBusy())) {
                    empl->SetTask(typeTask);
                    empl->SetBusy(true);
                    --numberTasks;
                    allEmployeesAreBusy = false;
                }
            }
        }
        return allEmployeesAreBusy;   
    } 

    
    void PrintEmployees() 
    {
        for (size_t i = 0; i < managers.size(); ++i) {
            std::cout<< "  Team  " << i + 1 << ":\n"; 
            for (int j = 0; j < managers[i]->GetEmployeesSize(); ++j) {
                Employee* empl = managers[i]->GetEmployees()[j];
                std::cout<< j + 1 << " "    
                <<"employee: " << empl->GetName() << "  "
                <<"busy status: " <<empl->GetBusy() << "  "
                <<"task name: "<<empl->getNameTask() << "\n";
                
        }
        std::cout <<"\n";
    }
   
}


private:
    int num_teams_;
    std::vector<Manager*> managers;   

}; 



int main() 
{
    int num_teams;
    std::string name_head;
    std::cout<<"Enter the name of the head of the company: ";
    std::cin>>name_head;
    std::cout<<"Enter the number of commands: ";
    std::cin>>num_teams;
    Head* head = new Head(name_head, num_teams); 

    while(true) {
        int taskID;
        std::cout<<"Enter the task ID: ";
        std::cin>>taskID;
                   
        if (head->TaskStart(taskID)){
            std::cout << "All workers are busy" << "\n";
            head->PrintEmployees();
            delete head;
            head = nullptr;
            return 0;
        }

        head->PrintEmployees();
    }

    return 1; 
}