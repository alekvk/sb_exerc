#include <iostream>
#include <vector>
#include <algorithm>


template <typename KeyT, typename ValT>
struct Data
{
    KeyT key;
    ValT value;

    Data()
    {};
    Data(KeyT _key, ValT _value) : 
    key(_key), value(_value)
    {};
};

template <typename KeyT, typename ValT>
class Registry 
{
public:
    Registry() 
    {}    

    Registry(KeyT k, ValT t) 
    {
        reg.push_back({k, t});
    }    
   
    void add(KeyT k, ValT v)
    {
        reg.push_back({k, v});
    }
 
    void remove(KeyT key)  
    {
        std::cout<<"Remove by key \""<<key<<"\""<<"\n"; 
        
        reg.erase(std::remove_if(reg.begin(), reg.end(), 
            [key](Data<KeyT, ValT> d){
                return  d.key == key;  
        }), reg.end());
    }
   
    void print()
    {
        std::cout << "Registry:\n";
        for (Data r : reg)
            std::cout << "key: "<< r.key 
            << "  value: " << r.value << "\n";
    }

    void find(KeyT key)
    {
        std::cout<<"Search by key \""<<key<<"\""<<"\n"; 

        auto it{std::find_if(begin(reg), end(reg), 
            [key](Data<KeyT, ValT> d) {
                return  d.key == key;
        })};

        while (it != reg.end()) 
        {
            std::cout<<"key:" << it->key << " "<<"value:"<<it->value<<"  ";
            it = find_if(it + 1, reg.end(), 
                [key](Data<KeyT, ValT> d) {
                    return  d.key == key;
            });
        }
        std::cout<<"\n\n";
    } 

private:
    std::vector<Data<KeyT, ValT>> reg;
};


int main(){
      
    Registry r("gg", 0);
    r.add("ff", 0);
    r.add("gg", 1);
    r.add("ff", 1);
    r.add("gg", 2);
    r.add("ff", 2);
    r.add("gg", 3);
    r.add("ff", 3);
         
    r.print();
    r.find("gg");
    r.remove("gg");
    r.print();
    r.find("gg");

    Registry r2("bb", 0.0);
    r2.add("ll", 0.0);
    r2.add("bb", 0.1);
    r2.add("ll", 0.1);
    r2.add("bb", 0.2);
    r2.add("ll", 0.2);
    r2.add("bb", 0.3);
    r2.add("ll", 0.3);

    r2.print();
    r2.find("ll");
    r2.remove("ll");
    r2.print();
    
    Registry<double, std::string>* r3 = new Registry<double, std::string>();
    r3->add(5.5, "rrr");
    r3->add(10.5, "rrr");
    r3->add(5.5, "sss");
    r3->add(10.5, "sss");
    
    r3->print();
    r3->find(10.5);
    r3->remove(10.5);
    r3->print();
        
    delete r3;
    
    return 0;
}


