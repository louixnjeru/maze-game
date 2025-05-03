#pragma once

#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>

#include "room.h"

class Player {
    private:
        std::string name;
        double health;
        Room *location;


    public:
        Player(std::string name, double health);
};