#pragma once

#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>

class Room;

class Maze {
    private:
        std::unordered_map<int,std::set<int>> adj;

        std::set<Room*> maxComponent;

        std::vector<Room*> rooms;

        void generateErdosRenyi(int n, double p);

        void generateVertexDuplication(int n, double p);

        void removeNode(int node);

        double getProbability();

        int getRandInt(int end);

        int getRandInt(int start, int end);

        void bfs(std::set<Room*> &visited, Room* source);

        void getMaxConnectedComponent();

    public:
        
        Maze(int n, double p, std::string mode, int map_size, int max_room_size);

        void addEdge(int i, int j);

        void printGraph();

        void getMaxConnectedComponentSize() { std::cout << "Max Connected Component Size: " << this->maxComponent.size() << "\n"; };
};
