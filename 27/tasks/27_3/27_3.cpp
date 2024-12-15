#include <iostream>
#include <vector>
#include <ctime>


class Branch {
    
public:
    Branch(Branch* parent, std::string name) :
        name_ (name),
        parent_ (parent)
    {}

    void SetChildren(Branch* parent, std::string name)
    {
        childrens_.push_back(new Branch(parent, name));
    }

    std::vector <Branch*> GetChildrens()
    {
      return childrens_;
    }
    
    std::string GetName(){
        return name_;
    }

    Branch* getLargeBranch()
    {
        if (parent_ == nullptr) 
            return nullptr; 
        if (parent_->parent_ == nullptr) 
            return this;
        return parent_->getLargeBranch(); 
    }

    
private:
    Branch *parent_ = nullptr;
    std::vector <Branch*> childrens_;
    std::string name_ = "None";
    
};

void PrintTree(int level, Branch* branch) 
{

    std::string shift;
    if (level > 1) { 
        std::string whitespace((3 * level), ' ');
        shift += whitespace;
    }

    std::cout<<shift<<"Level: "<<level<<" Elf: "<< branch->GetName()<<"\n";     
    ++level;
    
    for(size_t i = 0; i < branch->GetChildrens().size(); ++i)
        PrintTree(level, branch->GetChildrens()[i]);        
}

Branch* FindName(Branch* branch, std::string name)
{
    if (branch->GetName() == name)
        return branch;
    
    if (branch->GetChildrens().size() > 0) {
        for(size_t i = 0; i < branch->GetChildrens().size(); ++i) {
            Branch* br = FindName(branch->GetChildrens()[i], name);
            if (br != nullptr) {
                return br;
            }        
        }    
    }

    return nullptr;
}


int GetCountElf(Branch* branch)
{
    int count_elf = 0;

    if(branch->GetName() != "None") ++count_elf; 
      
    for (int i = 0; i < branch->GetChildrens().size(); ++i) 
        if(branch->GetChildrens()[i]->GetName() != "None")
            ++count_elf;

    return count_elf;     
}





int main() 
{
    int level = 1;
    const int count_trees = 5;
    std::vector <Branch*> trees;
    std::srand(std::time(0)); 

    for (int i = 0; i < count_trees; ++i) {
        std::cout<<"\nFilling TREE "<< i + 1 <<"\n";
        Branch* branch = new Branch(nullptr, "None");
        trees.push_back(branch);
        int count_large = rand() % 3 + 2;  

        for (int j = 0; j < count_large; ++j) {
            std::string name;
            std::cout<<"\nFilling a large branch number "<< j + 1 <<"\n";
            std::cout<<"Elf on the big branch:  ";
            std::cin >> name;
            trees[i]->SetChildren(trees[i], name); 
                
            int count_middle = rand() % 2 + 2; 
            for (int k = 0; k < count_middle; ++k){
                std::cout<<"\nFilling a middle branch number "<< k + 1 <<"\n";
                std::cout<<"Elf on the middle branch : ";
                std::cin >> name;
                trees[i]->GetChildrens()[j]->SetChildren(trees[i]->GetChildrens()[j], name); 
            }
        }
    }

    for (size_t i = 0; i < trees.size(); ++i) 
    {
        std::cout<<"\nTREE "<< i + 1 <<"\n";
        PrintTree(level, trees[i]);
        std::cout<<"\n";
    }

    std::string name;
    std::cout << "Enter the name of elf: ";
    std::cin >> name;

    for (size_t i = 0; i < trees.size(); ++i) 
    {
        std::cout<<"TREE "<< i + 1 << "\n";
        Branch* br = FindName(trees[i], name);
        std::cout << "The found word: "<<br->GetName()<<std::endl;
        int count_elf = GetCountElf(br->getLargeBranch());
        std::cout << "Number of neighbors: "
        << count_elf - 1 <<std::endl;
    }
    
    return 0;
}