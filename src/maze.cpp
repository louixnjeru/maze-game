#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <cmath>

#include "maze.h"
#include "room.h"
#include "enemy.h"

class Room;

void Maze::generateErdosRenyi(int n, double p) {
    for (int i { 0 }; i < n; ++i ) {
        for (int j { i+1 }; j < n; ++j ) {
            if (getProbability() < p) {
                //std::cout << i << '\t' << j << '\n';
                rooms.at(i)->addNeighbour(rooms.at(j));
                rooms.at(j)->addNeighbour(rooms.at(i));
                this->adj.at(i).at(j) = 1;
                this->adj.at(j).at(i) = 1;
            }
        }
    }
}

std::vector<double> Maze::getEigenVectorCentraility(int n) {
    std::vector<double> degreeCentrality(n, 1);
    std::vector<double> normalisedCentrality(n, 0);

    for (int i {0}; i < 2; ++i) {
        double normaliser{0};

        for (int i{0}; i < n; ++i) {
            for (int j{0}; j < n; ++j) {
                normalisedCentrality.at(i) += this->adj.at(i).at(j) * degreeCentrality.at(i);
            }
            normaliser += std::pow(normalisedCentrality.at(i), 2);
        }

        normaliser = std::sqrt(normaliser/n);

        for (int i{0}; i < n; ++i) {
            normalisedCentrality.at(i) /= normaliser;
        }

        degreeCentrality = normalisedCentrality;
    }

    return normalisedCentrality;

}

void Maze::generateVertexDuplication(int n, double p) {}
void Maze::removeNode(int node) {}

double Maze::getProbability() {
    return (double)(rand() % 1000) / 1000;
}

int Maze::getRandInt(int end) {
    return (rand() % end) + 1;
}

int Maze::getRandInt(int start, int end) {
    return (rand() % (end - start)) + start + 1;
}

void Maze::bfs(std::set<Room*> &visited, Room* source) {

    std::queue<Room*> q;
    q.emplace(source);
    std::set<Room*> currentComponent {source};
    Room* curr;
    
    while (!q.empty()){
        curr = q.front();
        q.pop();
        visited.insert(curr);

        for (auto nei : curr->getNeighbours()) {
            if (visited.count(nei) == 0) {
                visited.insert(nei);
                q.emplace(nei);
                currentComponent.insert(nei);
            }
        }
    }

    //std::cout << "C Size:" << currentComponent.size() << '\n';
    if (currentComponent.size() > this->maxComponent.size()) {
        this->maxComponent = currentComponent;
    }

}

void Maze::createRooms(int n, int map_size, int max_room_size) {
    bool isCollison;
    while (this->rooms.size() < n) {
        isCollison = false;

        Room *newRoom = new Room(getRandInt(-map_size, map_size), getRandInt(-map_size, map_size), getRandInt(max_room_size), getRandInt(max_room_size));
        for (auto &r : this->rooms) {
            if (r->checkCollision(newRoom)) {
                //std::cout << "**" << newRoom->getX() << ", " << newRoom->getY() << "**\n";
                isCollison = true;
                break;
            }
        }

        if (isCollison) {
            delete newRoom;
        } else {
            this->rooms.push_back(newRoom);
        }
    }
};

void Maze::placeEnemies(int n, double p) {
    for (int i {0}; i < n; ++i) {
        while (this->eigenvectorCentrality.at(i) > 1) {
            if (getProbability() < (1-p)/2) {
                Enemy* newEnemy = new Enemy("Enemy", 100);
                this->rooms.at(i)->addEnemy(newEnemy);
            }
            this->eigenvectorCentrality.at(i) -= 1;
        }
        double pr {getProbability()};
        std::cout << pr << "-" << this->eigenvectorCentrality.at(i) << " ";
        if (pr < this->eigenvectorCentrality.at(i)) {
            Enemy* newEnemy = new Enemy("Enemy", 100);
            this->rooms.at(i)->addEnemy(newEnemy);
        }
        

    }
    std::cout << "\n";
}



Maze::Maze(int n, double p, std::string mode, int map_size, int max_room_size) {
    this->adj = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
    this->createRooms(n, map_size, max_room_size);
    this->generateErdosRenyi(n, p);
    this->getMaxConnectedComponent();
    this->eigenvectorCentrality = this->getEigenVectorCentraility(n);
    this->placeEnemies(n, p);

    /*
    for (auto v : this->eigenvectorCentrality ) {
        std::cout << v << " ";
    }
    */
    std::cout << std::endl;
    for (auto r : this->rooms ) {
        std::cout << r->getNeighbourCount() << "-" << r->getEnemyCount() << " ";
    }
    std::cout << std::endl;
    
}

Maze::~Maze() {
    for (auto r : this->rooms) {
        delete r;
    }
    this->rooms.clear();
    //std::cout << "Maze destructed" << std::endl;
}

void Maze::addEdge(int i, int j) {}

void Maze::printGraph() {
    for (auto r: this->rooms) {
        std::cout << "(" << r->getX() << ", " << r->getY() << ")  ->  ";
        for (auto nei: r->getNeighbours()) {
            std::cout << "(" << nei->getX() << ", " << nei->getY() << ") " << /*nei->getDistanceToRoom(r) <<*/ ", ";
        }
        std::cout << '\n';
    }
}

void Maze::getMaxConnectedComponent() {
    std::set<Room*> visited;

    for (auto room: this->rooms) {
        if (visited.count(room) == 0) {
            this->bfs(visited, room);
        }
    }
}