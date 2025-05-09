#pragma once

#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>

#include "room.h"
#include "entity.h"

class Player : public Entity {
    private:
        std::string name;
        double health;
        Room* location;


    public:
        Player(std::string name = "None", double health = 100);

        Room* getLocation() { return this->location; };
        void setLocation(Room* new_location) { this->location = new_location; };

        double getHealth() { return this->health; };
        std::string getName() { return this->name; };
};