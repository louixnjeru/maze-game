#pragma once

#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>

#include "entity.h"

class Enemy : public Entity {
    public:
        Enemy(std::string name, double health);
};