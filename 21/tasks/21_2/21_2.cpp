#include <iostream>
#include <vector>

enum room_type {bedroom, kitchen, bathroom, childrens, live_room};
enum type_building {live_building, garage, barn, bathhouse};

struct room {
    room_type room; 
    double sq_room = 0; 
};

struct floor {
    int floor_num = 1;
    double ceil_height;
    int num_rooms;
    int min_num_rooms = 2;
    int max_num_rooms = 4;
    std::vector<room> rooms;
};

struct building {
    type_building type_b;   
    double sq_building;
    bool isFurnace = false;
    int num_floors = 1;
    int min_num_floors = 1;
    int max_num_floors = 3;
    std::vector<floor> floors;
};

struct plot {
    int plot_num;
    int num_buildings;
    int min_num_buildings = 0;
    int max_num_buildings = 4; 
    std::vector<building> buildings;
};

void FillRoom(room& r);

void FillFloor(floor& f);

void FillBuilding(building& b);

void FillPlot(plot& p);


int main() {

    int quantity_plot;
    double area_village = 600;
    double area_buildings = 0;
    std::cout<<"Enter the quantity of plots: ";
    std::cin>>quantity_plot;
    std::vector<plot> village;

    for (int i = 1; i <= quantity_plot; ++i) {
        plot p;
        p.plot_num = i;
        std::cout<<"\nEnter the information for plot number "<< i;
        FillPlot(p);
        village.push_back(p);
    }

    for (int i = 0; i < village.size(); ++i) {
        std::vector<building> b = village[i].buildings;
        
        for (int j = 0; j < b.size(); ++j) {
            area_buildings += b[j].sq_building;
        }
    }

    std::cout<<"\n\nThe percentage of land occupied by buildings "
    << area_buildings / area_village * 100; 

    return 0;
}



void FillRoom(room& r) {

    bool isRoomType;
    double sq;

    do {

        int type;
        isRoomType = true; 

        std::cout<<"Enter the number of the room type\n";
        std::cout<<"(0 - bedroom, 1 - kitchen, 2 - bathroom, 3- childrens, 4 - live_room): ";
        std::cin>>type;

        switch (type) {
            case 0: r.room = bedroom; break;
            case 1: r.room = kitchen; break; 
            case 2: r.room = bathroom; break; 
            case 3: r.room = childrens; break; 
            case 4: r.room = live_room; break; 
            default: isRoomType = false; std::cout<<"\nInvalid number\n";
        } 

    } while (!isRoomType); 

    do {

        std::cout<<"Enter the square of the room:  ";
        std::cin>>sq;

        if (sq > 0) r.sq_room = sq;
        else {
            std::cout<<"Incorrect area value:  ";
            continue;   
        } 
    
    } while (sq <= 0);

} 

void FillFloor(floor& f) {

    double height;
    std::vector<room> vector_rooms;
     
    do {
        std::cout<<"Enter the ceiling height:  ";
        std::cin>>height;

        if (height > 0) f.ceil_height = height;
        else std::cout<<"Incorrect height value\n";

    }  while (height <= 0);

    int min = f.min_num_rooms;
    int max = f.max_num_rooms;
    int num_rooms;

    do {
        std::cout<<"Enter the number of rooms " 
        <<"(a number from "<<min<<" to "<<max<<"):";
        std::cin>>num_rooms;

        if (num_rooms < min || num_rooms > max) 
            std::cout<<"The wrong number of rooms has been entered";

    } while (num_rooms < min || num_rooms > max);

    for (int i = 1; i <= num_rooms; ++i) {
        std::cout<<"\nEnter the information for room "<< i <<":\n";
        room r;
        FillRoom(r); 
        vector_rooms.push_back(r); 
    }

    f.rooms = vector_rooms;
} 



void FillBuilding(building& b) {
    
    double sq;
    std::vector<floor> vector_floors;
    int type_building;
    bool isBuildingType;   
     
    do {
        
        isBuildingType = true; 
   
        std::cout<<"Enter the number of the biulding type\n";
        std::cout<<"(0 - live_building , 1 - garage , 2 - barn , 3 - bathhouse): ";
        std::cin>>type_building;

        switch (type_building) {
            case 0: b.type_b = live_building; break;
            case 1: b.type_b = garage; break; 
            case 2: b.type_b = barn; break; 
            case 3: b.type_b = bathhouse; break; 
            default: isBuildingType = false; std::cout<<"\nInvalid number\n";
        } 

    } while (!isBuildingType);

    do {
        std::cout<<"Enter the building area:  ";
        std::cin>>sq;

        if (sq > 0) b.sq_building = sq;
        else std::cout<<"Incorrect square value\n";

    }  while (sq <= 0);

    b.sq_building = sq; 


    if (type_building == live_building) {
        int min = b.min_num_floors;
        int max = b.max_num_floors;
        int num_floors;
    
        do {
            std::cout<<"Enter the number of floors" 
            <<"(a number from "<<min<<" to "<<max<<"): ";
            std::cin>>num_floors;

            if (num_floors < min || num_floors > max) 
                std::cout<<"The wrong number of floors\n";

        } while (num_floors < min || num_floors > max);

        b.num_floors = num_floors;

        for (int i = 1; i <= num_floors; ++i) {
            std::cout<<"\nEnter the information for floor "<< i <<":\n";
            floor f;
            f.floor_num = i;
            FillFloor(f); 
            vector_floors.push_back(f); 
        }

        b.floors = vector_floors;
    }

    if (type_building == live_building || type_building == bathhouse) {
        int furnace;
        std::cout<<"\nIs there a furnace with a pipe in the building?\n";
        std::cout<<"Enter 1 if present or 0 if absent: ";
        std::cin>>furnace;

        if (furnace == 1) b.isFurnace = true;
    }
    
}


void FillPlot(plot& p) {

    int num_buildings;
    int min = p.min_num_buildings;
    int max = p.max_num_buildings;
    std::vector<building> buildings_vector;

    do {
        std::cout<<"\nEnter the number of buildings" 
        <<"(a number from "<<min<<" to "<<max<<"): ";
        std::cin>>num_buildings;

        if (num_buildings < min || num_buildings > max) 
            std::cout<<"The wrong number of buildings has been entered";

    } while (num_buildings < min || num_buildings > max);

    for (int i = 1; i <= num_buildings; ++i) {
        std::cout<<"\nEnter the information for building "<< i <<":\n";
        building b;
        FillBuilding(b); 
        buildings_vector.push_back(b); 
    }

    p.buildings = buildings_vector;
}









