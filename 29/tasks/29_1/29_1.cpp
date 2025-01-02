#include <iostream>
#include <vector>
#include <set>

class Talent
{
public:
    
    virtual void show_talent() = 0;
    virtual std::string GetName() = 0;        
};

class Swimm : public Talent 
{
public:
       
    void show_talent() override
    {
        std::cout<<GetName()<<"!"<<std::endl;       
    };

    std::string GetName() override
    {
        return name;
    }

private:
    const std::string name = "Swimm";
};

class Dance : public Talent 
{
public:
          
    void show_talent() override
    {
        std::cout<<GetName()<<"!"<<std::endl;       
    }

    std::string GetName() override
    {
        return name;
    } 

private:
    const std::string name = "Dance";
};


class Count : public Talent 
{
public:
    
    void show_talent() {
        std::cout<<GetName()<<"!"<<std::endl;       
    };

    std::string GetName() 
    {
        return name;
    } 

private:
    const std::string name = "Count";
        
};




class Dog 
{ 
public:
    Dog(std::string in_name):
        name(in_name)
    {}
    
    std::string GetName() {
        return name;
    }

    void show_talents(){
        std::cout<<"This is "<<GetName() 
        <<" and it has some talents:\n"; 

        for (auto s : set_talents) 
            std::cout<<"It can \""<<s<<"\""<<std::endl;
        std::cout<<"\n";
    } 

    bool AddTalent(Talent* talent) {
        if(set_talents.count(talent->GetName()) == 0) {
            talents.push_back(talent);
            set_talents.insert(talent->GetName());
            return true;
        } else {
            return false;
        }

    }
    
private:
    std::string name;
    std::vector<Talent*> talents;
    std::set<std::string> set_talents;
};



int main ()
{
    Dog dog("Steve");
    std::cout<<dog.GetName()<<"\n\n";

    Talent* talent;
    
    Swimm* swimm = new Swimm;
    talent = swimm;
    talent->show_talent();
    dog.AddTalent(talent);
    dog.show_talents();

    Dance dance;
    talent = &dance;
    talent->show_talent();
    dog.AddTalent(talent);
    dog.show_talents();

    talent = new Count;
    talent->show_talent();
    dog.AddTalent(talent);
    dog.show_talents();
 
    return 0;
}




