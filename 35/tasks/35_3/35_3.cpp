#include <iostream>
#include <filesystem>
#include <vector>
#include <exception>

//namespace fs = std::filesystem; 

template<typename Iter> 
void PrintConteiner(Iter beg, Iter end);

void PrintFileSystem(std::filesystem::path path);


auto recursiveGetFileNamesByExtension =
[](std::filesystem::path path, const std::string extension)
{
    std::vector<std::string> file_names;
    std::string file_name;
    std::string ext = "." + extension; 

    for(auto& p: std::filesystem::recursive_directory_iterator(path)) 
        if(p.is_regular_file() && p.path().extension() == ext ) {
            file_name = p.path().filename().generic_string();
            file_names.push_back(file_name);
        }        
    
    return file_names;
}; 

int main()
{
    std::string path = "..\\";
    std::string ext_file = "exe";
    
   
    try
    {
        PrintFileSystem(path);
        std::cout<<"=======================================================\n";
        auto names =  recursiveGetFileNamesByExtension(path, ext_file);
        PrintConteiner(std::begin(names), std::end(names));
    }

    catch (...)
    {
        std::cerr << "No such file or directory";
    }
    
    return 0;
}




template<typename Iter> 
void PrintConteiner(Iter beg, Iter end)
{
    for (Iter it = beg; it != end; ++it)
        std::cout<<*it<<"\n";
        
    std::cout<<std::endl;
}


void PrintFileSystem(std::filesystem::path path) 
{
    for(auto& p: std::filesystem::recursive_directory_iterator(path)) {
        std::cout << p.path()<< "  "
        << p.is_regular_file() << "   "
        <<p.path().extension() <<"\n";  
    }

    std::cout<<"\n";
}