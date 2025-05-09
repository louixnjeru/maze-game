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
        std::vector<std::vector<int>> adj;

        std::vector<double> eigenvectorCentrality;

        std::set<Room*> maxComponent;

        std::vector<Room*> rooms;

        int n, prob, maxRoomSize;

        void generateErdosRenyi(int n, double p);

        void generateVertexDuplication(int n, double p);

        void removeNode(int node);

        double getProbability();

        int getRandInt(int end);

        int getRandInt(int start, int end);

        void bfs(std::set<Room*> &visited, Room* source);

        void getMaxConnectedComponent();

        std::vector<double> getEigenVectorCentraility(int n);

        void createRooms(int n, int map_size, int max_room_size);

        void placeEnemies(int n, double p);

    public:
        
        Maze(int n, double p, std::string mode, int map_size, int max_room_size);
        ~Maze();

        void addEdge(int i, int j);

        void printGraph();

        void getMaxConnectedComponentSize() { std::cout << "Max Connected Component Size: " << this->maxComponent.size() << "\n"; };
};
