#pragma once

#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>

class Entity {
    protected:
        std::string name;
        double health;
    
    public:
        std::string getName();
        void setName(std::string name);

        double getHealth();
        void setHealth(double health);

        Entity();
        Entity(std::string name, double health);

};