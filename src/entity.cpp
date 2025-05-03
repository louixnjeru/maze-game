#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>

#include "entity.h"

std::string Entity::getName() { return name; }
void Entity::setName(std::string name) { this->name = name; }

double Entity::getHealth() { return health; }
void Entity::setHealth(double health) { this->health = health; }


Entity::Entity(std::string name, double health)
    : health {health}, name {name} {
    this->health = health;
    this->name = name;
}

Entity::Entity() : Entity{"None", 100} {}