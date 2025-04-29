#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>

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

void Room::addEnemy() {
    
}