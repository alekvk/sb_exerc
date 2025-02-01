#include <iostream>
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"

struct Movie 
{
    std::string name;
    std::string country;
    std::string date;
    std::string studio;
    std::vector<std::string> screenwriters;
    std::string director_film;
    std::vector<std::string> producers;
    std::map<std::string, std::string> actors;
};


void findActor(const std::string& name, std::vector<Movie> films)
{
    std::cout << "\nActor "<<name<< "(name or last name)\n";
    for (auto f : films)
        for (auto a : f.actors)
            if (a.second.find(name) != std::string::npos)
                std::cout<<"Film \""<<f.name<<"\", "<<"role \""<<a.first<<"\"\n";
}

std::vector<Movie> GetVectorMovies(const std::string& path) 
{
    std::vector<Movie> films;
    nlohmann::json dict;
    std::ifstream file(path);
   
    if (file.is_open()) {
        file >> dict;
        file.close();

        for (const auto& i : dict.items()) {
            Movie m;
            m.name = i.key();
            m.country = i.value()["country"];
            m.date = i.value()["date"]; 
            m.studio = i.value()["studio"];
            m.screenwriters = i.value()["screenwriters"]; 
            m.director_film = i.value()["director_film"];
            m.producers = i.value()["producers"];
            m.actors = i.value()["actors"];

            films.push_back(m);
        }
    } else 
        std::cout << "\nFile opening error\n";
    
    return films;
}


int main () {
   
    const std::string path  = "..\\movies.json";
    
    auto films = GetVectorMovies(path);

    findActor("John", films);
    findActor("Pfeiffer", films);
    findActor("Tommy Lee Jones", films);
 
    return 0;
}