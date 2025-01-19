#include <iostream>
#include <memory>

class Toy {
public:
    Toy(const std::string& name) {
       name_ = name;
    }

    std::string getNmae() {
       return name_;
    }

    ~Toy() {
       std::cout << "Toy " << name_ << " was dropped " << std::endl;
    }
       
    std::string getName()
    {
       return name_; 
    }

private:
   std::string name_;
};



class Dog
{
public:
    Dog(std::string _name, const std::shared_ptr<Toy>& t) : name(_name)
    {
        if (t.use_count() == 1)
            toy = t;
        else 
            std::cout << "Another dog is playing with this toy.";
            std::cout<<this->name <<" the dog didn't get a " 
            <<t->getName()<<" toy."<<std::endl;
    }
    Dog() : Dog("Snow") {}
    Dog(std::string _name) : name(_name) {};
    
    void getToy(const std::shared_ptr<Toy>& t) 
    {
        if (toy != t && toy != nullptr) {
            std::cout<<this->name <<" the dog already has a toy " 
            <<toy->getName()<<" toy"<<std::endl;
            return;
        } 
        
        if (toy == t) {
            std::cout<<"I already have this toy("<<toy->getName()
            <<")." << std::endl;
        }
        else if (t.use_count()  > 1) {
            std::cout << "Another dog is playing with this toy.";
            std::cout<<this->name <<" the dog didn't get a " 
            <<t->getName()<<" toy."<<std::endl;
            
        } else {
            toy = t;            
            std::cout<<this->name <<" the dog got a " <<toy->getName()
            <<" toy"<<std::endl;
        }
    }

    void dropToy() 
    {
        if (toy.use_count() == 1) 
            std::cout << "Nothing to drop." << std::endl;
        else {
            std::cout<<this->name <<" the dog threw the " <<toy->getName()
            <<" toy on the floor"<<std::endl;  
            toy = nullptr;
        }
    }
    
    virtual ~Dog()
    {
        std::cout<<"I am deleting Dog "<<name<<" and its toy!"<<std::endl;
    }

private:
    std::string name;
    std::shared_ptr<Toy> toy = nullptr;
}; 


int main () {
   
    std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");
    std::shared_ptr<Toy> bone = std::make_shared<Toy>("Bone");
   
    Dog s("Sharik");
    Dog b("Bobik");
    Dog n;
       
    s.getToy(ball);
    s.getToy(bone);

    Dog p("Pushok", ball);

    b.getToy(ball);
    s.dropToy();
    b.getToy(ball);
    p.getToy(bone);

    n.getToy(bone);
    p.dropToy();
    n.getToy(bone);
       
    std::cout<<"\n\n";

    return 0;
}