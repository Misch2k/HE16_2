#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


class Neighbours {
public:
    int target;
    int weight;

    explicit Neighbours(int target = -1, int weight = 1);

    // To allow the sort algorithm
    bool operator<(const Neighbours &obj) {
        return target < obj.target;
    }
};


struct Entry {
    int value = 0;
    vector<Neighbours> neighbours;
};

class Graph {
public:
    vector<Entry> entry;
    Graph(int nNodes, int nConnections, bool directed = false);
    int getNumberOfNodes();

    friend ostream &operator<<(std::ostream &stream, const Graph &obj) {
        for (auto val : obj.entry) {
            stream << val.value << " : ";
            for (auto target : val.neighbours) {
                stream << target.target << "(" << target.weight << ")\t";
            }
            stream << endl;
        }
        return stream;
    }
};

#endif