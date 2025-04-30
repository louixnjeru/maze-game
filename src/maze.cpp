#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <cstdlib>

#include "maze.h"
#include "room.h"

class Room;

void Maze::generateErdosRenyi(int n, double p) {
    for (int i { 1 }; i < n+1; ++i ) {
        for (int j { i+1 }; j < n+1; ++j ) {
            if (getProbability() < p) {
                rooms.at(i)->addNeighbour(rooms.at(j));
                rooms.at(j)->addNeighbour(rooms.at(i));
            }
        }
    }
}

void Maze::generateVertexDuplication(int n, double p) {
    
}

void Maze::removeNode(int node) {
    
}

double Maze::getProbability() {
    return (double)(rand() % 1000) / 1000;
}

int Maze::getRandInt(int end) {
    return (rand() % end) + 1;
}

int getRandInt(int start, int end) {
    return (rand() % (end - start)) - start + 1;
}

void Maze::bfs(std::set<int> &visited, std::set<int> &maxComponent, int node) {
    
}

Maze::Maze(int n, double p, std::string mode, int map_size, int max_room_size) {
    bool isCollison;
    while (rooms.size() < n) {
        isCollison = false;

        Room *newRoom = new Room(getRandInt(-map_size, map_size), getRandInt(-map_size, map_size), getRandInt(max_room_size), getRandInt(max_room_size));
        
        for (auto &r : rooms) {
            if (r->checkCollision(newRoom)) {
                isCollison = true;
                break;
            }
        }

        if (isCollison) {
            delete newRoom;
        } else {
            rooms.push_back(newRoom);
        }
    }

    generateErdosRenyi(n, p);

}

void Maze::addEdge(int i, int j) {
    
}

void Maze::printGraph() {
    
}

void Maze::getMaxConnectedComponent() {
    
}