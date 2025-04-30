#pragma once

#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>

class Enemy {
    private:
        std::string name;
        double health;

    public:
        Enemy(std::string name, double health);
};