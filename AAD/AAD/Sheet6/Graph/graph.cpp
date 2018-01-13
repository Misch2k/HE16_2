//
// Created by Michel on 20.11.2017.
//
#include "graph.h"

Neighbours::Neighbours(int target, int weight) : target(target), weight(weight) {
};


void Graph::addNode(vector<int> neighbours, vector<int> weights) {
    for(int i = 0 ; i < neighbours.size(); i++){
    this->entry.emplace_back(Neighbours(neighbours[i], weights[i]));
    }
}

Graph::Graph(int nNodes, int nConnections, bool directed) {
    {
        Entry v;
        for (int i = 0; i < nNodes; i++) {
            v.value = i;
            entry.push_back(v);
        }
    }
    int counter = 0;
    while (counter < nConnections) {
        int source = rand() % nNodes;
        int target = rand() % nNodes;
        if (source != target) {
            auto func = [&target](const Neighbours &obj) { return obj.target == target; };
            if (find_if(entry[source].neighbours.begin(), entry[source].neighbours.end(), func) == entry[source].neighbours.end()) {
                entry[source].neighbours.emplace_back(target);
                if (!directed) {
                    entry[target].neighbours.emplace_back(source);
                }
                counter++;
            }
        }
    }
    for (int i = 0; i < nNodes; i++) {
        sort(entry[i].neighbours.begin(), entry[i].neighbours.end());
    }

    for (auto &e : entry) {
        for (auto &v : e.neighbours) {
            v.weight = rand() % 20 + 1;
        }
    }

    if (!directed) {
        for (auto &e : entry) {
            for (auto &v : e.neighbours) {
                auto func = [&e](const Neighbours &obj) { return obj.target == e.value; };
                auto index = find_if(entry[v.target].neighbours.begin(), entry[v.target].neighbours.end(), func) - entry[v.target].neighbours.begin();
                entry[v.target].neighbours[index].weight = v.weight;
            }
        }
    }
}

int Graph::getNumberOfNodes(){
    return entry.size();
}