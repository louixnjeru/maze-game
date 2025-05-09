#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>

#include "room.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"

Player::Player(std::string name, double health) : Entity{name, health} {

}