#include <iostream>
#include <map>
#include <exception>
//#include <limits>

class Shop;

class NegativeNumberException: public std::exception
{
public:    
    const char* what() const noexcept override
    {
        return "Negative number";
    }
};


class Basket: public NegativeNumberException 
{
public: 
    Basket(Shop* _shop): shop(_shop)
    {} 

    void add(std::string art, int count);
    void remove(std::string art, int count);
    void print();
    void buy() { basket = {}; }
private:
    Shop* shop;
    std::map<std::string, int>  basket;         
};

class Shop
{
    friend void Basket::add(std::string art, int count);
    friend void Basket::remove(std::string art, int count);
public:
    void fill(std::string art, int count);
    void print();
private:
    std::map<std::string, int>  database; 
};


int main()
{
    Shop* shop = new Shop();
    std::string item, oper;
    int count;
    
    while(item != "stop") {
       
        std::cout<<"Enter item (enter \"stop\" to stop fill) ";
        std::cin>>item;

        if (item == "stop")
            continue;

        std::cout<<"Enter quantity ";
        std::cin>>count;

        try
        {
            shop->fill(item, count);    
        }

        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }

        //std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.ignore(1000, '\n');
        
    }

    shop->print();
    Basket* basket = new Basket(shop);
      
    while(oper != "stop") {
        try
        {  
            std::cout<<"Enter oper(add, remove, buy, print, stop) ";
            std::cin>>oper;
        
            if (oper == "add") {
                std::cout<<"Enter item and quantity ";
                std::cin>>item>>count;
                basket->add(item, count);

            } else if (oper == "remove") {
                std::cout<<"Enter item and quantity ";
                std::cin>>item>>count;
                basket->remove(item, count);

            } else if (oper == "print") {
                basket->print();

            } else if (oper == "buy") {
                basket->buy();

            } else if (oper == "stop") {
                continue;

            } else
                std::cout<<"Wrong option\n"; 
        }

        catch(const NegativeNumberException& x)
        {
            std::cerr << "Caught exception" << x.what() << std::endl; 
        }
     
        catch(const std::exception& x)
        {
            std::cerr << "Caught exception" << x.what() << std::endl; 
        }

        catch(...)
        {
            std::cerr << "Caught exception ..." << std::endl; 
        }
    }
    
    shop->print();
    delete basket; 
    delete shop;
    
 
    return 0;
} 

void Basket::add(std::string art, int count)
    {
        if(!shop->database.count(art)) 
        {
            std::cout<<"\nThe product is missing\n";
            return;
        }
        
        if(count < 0) { 
            throw NegativeNumberException();
        }
        
        if(shop->database[art] < count) { 
            throw std::exception();
        }
        
        shop->database[art] -= count;
        basket[art]+= count; 
    }

void Basket::remove(std::string art, int count)
{   
    if(count < 0) 
        throw NegativeNumberException();
    
    if(basket[art] < count)  
        throw std::exception();
    
    basket[art] -= count; 
    shop->database[art] += count;

    if (basket[art] == 0)
        basket.erase(art);
}

void Basket::print()
{
        for(auto[k,v] : basket)
            std::cout<<"Item "<<k<<"  "<<"quantity "<<v<<"\n";
}

void Shop::fill(std::string art, int count) 
{
    
    if(count < 0)
    {
        throw std::invalid_argument("count");
    }
    
    database[art] += count;
}

void Shop::print()
{
    for(auto[k,v] : database)
        std::cout<<"Item "<<k<<"  "<<"quantity "<<v<<"\n";
}




