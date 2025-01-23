#include <iostream>
#include <string>
#include <memory>

class Toy {
public:
    Toy(const std::string& name) 
    {
       name_ = name;
    }

    std::string getName() 
    {
       return name_;
    }
           
    ~Toy() 
    {
       std::cout << "Toy " << name_ << " was dropped " << std::endl;
    }

private:
   std::string name_;
};


class shared_ptr_toy 
{
private:
    Toy* toy = nullptr;
    int* count;

public:
    shared_ptr_toy(std::string name)
    {
        toy = new Toy(name);
        count = new int(1);
    }

    shared_ptr_toy(const shared_ptr_toy& t) 
    {
        toy = t.toy; 
        count = t.count;
        ++*count;
    }

    shared_ptr_toy & operator= (const shared_ptr_toy & t) 
    {
        if (this == &t) 
            return *this;
            
        if (toy != nullptr && *count == 1) {
            delete toy;
            delete count;
        } else     
            --*count;

        toy = t.toy; 
        count = t.count;
        ++*count;
        return *this;
    }
    
    void reset() 
    {
        if (*count == 1) {  
            delete toy;
            delete count; 
        } else 
            --*count;    
              
        count = nullptr;
        toy = nullptr;
    }

    ~shared_ptr_toy() 
    {        
        if (count != nullptr) 
            --(*count);

        if (count != nullptr && *count == 0) {
            delete count;
            delete toy;                
        }
    }    

    std::string getToyName()
    {
        if (toy == nullptr)
            return "Nothing";
        return toy->getName();    
    } 

    int use_count()
    {
        if (count == nullptr)
            return 0;
        return *count;   
    }
   
};

shared_ptr_toy make_shared_toy(std::string name)
{
    shared_ptr_toy toy(name);       
    return toy;
}

int main () {

   shared_ptr_toy toy_01 = make_shared_toy("ball");
   shared_ptr_toy toy_02(toy_01);
   shared_ptr_toy toy_03("duck");
   std::cout << "=================================================" << std::endl;
   std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
             << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
             << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
   std::cout << "=================================================" << std::endl;
   toy_02 = toy_03;
   std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
             << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
             << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
   std::cout << "=================================================" << std::endl;
   toy_01.reset();
   std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
             << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
             << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
   std::cout << "=================================================" << std::endl;

   return 0;    
}   


  
 







