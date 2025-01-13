#include <iostream>
#include <vector>
#include <algorithm>

class Talent
{
public:
    virtual void show_talent() = 0;
    virtual std::string GetName() = 0;
    virtual ~Talent() { std::cout << "~Talent()" << std::endl; } 
};   

class Swimm : public Talent 
{
public:
       
    void show_talent() override
    {
        std::cout<<"It can \""<<GetName() <<"\""<<std::endl;       
    };

    std::string GetName() override
    {
        return name;
    }

    ~Swimm() {std::cout << "~Swimm()" << std::endl;} 

private:
    const std::string name = "Swimm";
};

class Dance : public Talent 
{
public:
          
    void show_talent() override
    {
        std::cout<<"It can \""<<GetName() <<"\""<<std::endl;        
    }

    std::string GetName() override
    {
        return name;
    } 

    ~Dance() {std::cout << "~Dance" << std::endl;} 

private:
    const std::string name = "Dance";
};


class Count : public Talent 
{
public:
    
    void show_talent() 
    {
        std::cout<<"It can \""<<GetName() <<"\""<<std::endl;        
    };

    std::string GetName() 
    {
        return name;
    } 

    ~Count() {std::cout << "~Count" << std::endl;} 

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

    void show_talents()
    {
        std::cout<<"This is "<<GetName() 
        <<" and it has some talents:\n"; 

        for (auto t : talents ) 
            t->show_talent();   
        std::cout<<"\n";
    } 

    bool AddTalent(Talent* talent) {

        if (!FindTalent(talent)) { 
            talents.push_back(talent);
            return true;
        } else {
            return false;
        }
    }

    ~Dog() 
    {
        for(size_t i = 0; i < talents.size(); ++i)
            delete talents[i];    
    } 
    
private:
 
    bool FindTalent(Talent* talent) 
    {    
        auto result{std::find_if(begin(talents), end(talents), [talent](Talent* t) {
            return t->GetName() == talent->GetName();
        })};

        if (result == end(talents))
            return false;
        else 
            return true;
    }

    std::string name;
    std::vector<Talent*> talents;
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

    Dance* dance = new Dance;
    talent = dance;
    talent->show_talent();
    dog.AddTalent(talent);
    dog.show_talents();

    talent = new Count;
    talent->show_talent();
    dog.AddTalent(talent);
    dog.show_talents();

    return 0;
}




