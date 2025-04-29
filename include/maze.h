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

        std::vector<Room*> rooms;

        void generateErdosRenyi(int n, double p);

        void generateVertexDuplication(int n, double p);

        void removeNode(int node);

        double getProbability();

        int getRandInt(int end);

        void bfs(std::set<int> &visited, std::set<int> &maxComponent, int node);

    public:
        
        Maze(int n, double p, std::string mode);

        void addEdge(int i, int j);

        void printGraph();

        void getMaxConnectedComponent();
};
