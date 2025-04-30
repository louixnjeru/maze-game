#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <cmath>

#include "room.h"

Room::Room(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

bool Room::checkCollision(Room *other) {
    return  this->x > other->x + other->width &&
            this->x + this->width < other->x &&
            this->y > other->y + other->height &&
            this->y + this->height < other->y;
}

void Room::addEnemy(Enemy *new_enemy) {
    this->enemies.push_back(new_enemy);
}

double Room::getDistanceToRoom(Room *other) {
    double x_diff {std::pow(other->x - this->x, 2)};
    double y_diff {std::pow(other->y - this->y, 2)};

    return std::sqrt(x_diff + y_diff);
}

void Room::addNeighbour(Room* new_neighbour) {
    this->neighbours.insert(new_neighbour);
}

void Room::removeNeighbour(Room* neighbour) {
    this->neighbours.erase(neighbour);
}