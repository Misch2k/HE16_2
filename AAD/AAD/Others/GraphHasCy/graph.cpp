#include "graph.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

Graph::Graph() {
}

void Graph::addNode(vector<int> neighbours, vector<int> weights) {
    this->neighbours.push_back(neighbours);
    this->weights.push_back(weights);
}

void Graph::randomInit(int nNodes, int nConnections, bool directed) {
    vector<int> v;
    for (int i = 0; i < nNodes; i++) {
        neighbours.push_back(v);
    }
    int counter = 0;
    int max = nConnections * 5;
    while (counter < nConnections || counter > max) {
        int source = rand() % nNodes;
        int target = rand() % nNodes;
        if (source != target) {
            if (find(neighbours[source].begin(), neighbours[source].end(), target) == neighbours[source].end()) {
                neighbours[source].push_back(target);
                if (!directed) {
                    neighbours[target].push_back(source);
                }
                counter++;
            }
        }
    }
    for (int i = 0; i < nNodes; i++) {
        sort(neighbours[i].begin(), neighbours[i].end());
    }

    for (vector<int> v : neighbours) {
        vector<int> w;
        for (int i = 0; i < v.size(); i++) {
            int cost = rand() % 20 + 1;
            w.push_back(cost);
        }
        weights.push_back(w);
    }

    if (!directed) {
        for (int i = 0; i < weights.size(); i++) {
            for (int j = 0; j < weights.at(i).size(); j++) {
                int source = i;
                int target = neighbours.at(i).at(j);
                int weight = weights.at(i).at(j);
                int index = find(neighbours.at(target).begin(), neighbours.at(target).end(), source) - neighbours.at(target).begin();
                weights[target][index] = weight;
            }
        }
    }
}

int Graph::getNumberOfNodes() {
    return neighbours.size();
}

vector<int> Graph::getNeighbours(int node) {
    return neighbours.at(node);
}

vector<int> Graph::getWeights(int node) {
    return weights.at(node);
}

std::ostream &operator<<(std::ostream &s, const Graph &obj) {
    for (int i = 0; i < obj.neighbours.size(); i++) {
        vector<int>::iterator it;
        s << "Node " << i << "\t";
        for (int j = 0; j < obj.neighbours[i].size(); j++) {
            s << obj.neighbours[i].at(j) << "(" << obj.weights[i].at(j) << "), ";
        }
        s << endl;
    }
    return s;
}


void hasCycle(Graph *g, deque<int> &values, int currentNode, int i, bool &cycle) {
    for (auto v : g->getNeighbours(currentNode)) {
        if (find(values.begin(), values.end(), v) == values.end()) {
            values.push_back(v);
        } else {
            cycle = true;
            return;
        };
    }
    if (++i < values.size()) {
        hasCycle(g, values, values[i], i, cycle);
    }
};

bool hasCycle(Graph *g) {
    deque<int> result;
    bool cycle = false;
    for (int i = 0; i < g->getNumberOfNodes(); i++) {
        if (!cycle) {
            result.clear();
            result.push_back(i);
            hasCycle(g, result, i, 0, cycle);
        } else {
            return true;
        }
    }
    return false;
};


