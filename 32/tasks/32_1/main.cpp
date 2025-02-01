#include <iostream>
#include <map>
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



int main () {

    const std::string path  = "..\\movie.json";
    std::ofstream file(path);
    Movie m;
    
    m.name = "Wolf";
    m.country = "United States";
    m.actors = {{"Will Randall", "John Nicholson"}, {"Laura Alden", "Michelle Pfeiffer"}};
    m.date = "1994";
    m.studio = "Columbia Pictures";
    m.screenwriters = {"Jim Harrison", "Wesley Strick"};
    m.director_film = "Mike Nichols";
    m.producers = {"Douglas Wick", "Neal A. Machlis"}; 
    
    
    if (file.is_open())
    {
        nlohmann::json dict;

        dict["name"] = m.name;
        dict["country"] = m.country;
        dict["date"] = m.date;
        dict["studio"] = m.studio;
        dict["screenwriters"] = m.screenwriters;
        dict["director_film"] = m.director_film;
        dict["producers"] = m.producers;
        dict["actors"] = m.actors;
      
        file << dict;
        file.close();
    }

    return 0;
}