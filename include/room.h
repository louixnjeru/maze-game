#pragma once

#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>

class Room {
    private:
        int x, y;
        int width, height;
        std::vector<int> items;
        std::vector<int> enemies;

    public:
        Room(int x, int y, int width, int height);

        bool checkCollision(Room *other);

        void addEnemy();
};