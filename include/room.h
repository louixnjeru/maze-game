#pragma once

#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>

#include "enemy.h"

class Room {
    private:
        int x, y;
        int width, height;
        std::vector<int> items;
        std::vector<Enemy*> enemies;
        std::set<Room*> neighbours;

    public:
        Room(int x, int y, int width, int height);
        ~Room();

        int getX() { return this->x; };
        int getY() { return this->y; };

        bool checkCollision(Room *other);

        void addEnemy(Enemy *new_enemy);
        int getEnemyCount() { return this->enemies.size(); }

        double getDistanceToRoom(Room *other);

        void addNeighbour(Room* new_neighbour);
        void removeNeighbour(Room* neighbour);
        int getNeighbourCount() { return this->neighbours.size(); };

        const std::set<Room*> getNeighbours() { return this->neighbours; };
};