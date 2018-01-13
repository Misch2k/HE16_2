#include "graphutil.h"
#include <stack>
#include <iostream>
#include <algorithm>

vector<DijkstraEntry> GraphUtil::dijkstra(Graph *g, int start, int end) {
    vector<DijkstraEntry> entry((unsigned int) g->getNumberOfNodes());
    GraphUtil::dijsktra(g, entry, start, end);
    return entry;
}

void GraphUtil::dijsktra(Graph *g, vector<DijkstraEntry> &entry, int NodeId, int end, int lastSum) {
    // end is marked and there is no shorter path
    if (NodeId == end) return;
    entry[NodeId].node = NodeId;
    entry[NodeId].marked = true;
    auto neighbors = g->getNeighbours(NodeId);
    auto weights = g->getWeights(NodeId);
    for (int i = 0; i < neighbors.size(); i++) {
        if (!entry[neighbors[i]].marked && (entry[neighbors[i]].distance == -1 || entry[neighbors[i]].distance > lastSum + g->getWeights(NodeId)[i])) {
            entry[neighbors[i]].node = neighbors[i];
            entry[neighbors[i]].distance = lastSum + g->getWeights(NodeId)[i];
            entry[neighbors[i]].predecessor = NodeId;
        }
    }


    int distance(0), node(0);
    bool first(true);
    auto getNext = [&entry, &first, &distance, &node](const DijkstraEntry &obj){
        if(obj.node != -1 && !entry[obj.node].marked){
            if(first){
                node = obj.node;
                distance = entry[obj.node].distance;
                first = false;
            }else if(distance > entry[obj.node].distance){
                distance = entry[obj.node].distance;
                node = entry[obj.node].node;
            }
        }
    };
    for_each(entry.rbegin(), entry.rend(), getNext);
    if (distance == 0) return;
    GraphUtil::dijsktra(g, entry, node, end, distance);
}

void GraphUtil::printShortestPath(Graph *g, int start, int end, bool printNext) {
    if (start < 0 || start >= g->getNumberOfNodes()) {
        cout << "Start value \"" << start << "\" is not in range!" << endl;
        return;
    } else if (end < 0 || end > g->getNumberOfNodes()) {
        cout << "End value \"" << end << "\" is not in range!" << endl;
        return;
    }

    vector<DijkstraEntry> result = GraphUtil::dijkstra(g, start, end);

    // Check if end is a node (also works for other data type)
    if (find_if(result.begin(), result.end(), [&end](const DijkstraEntry &obj) { return obj.node == end; }) == result.end()) {
        cout << "No connection from " << start << " to " << end << endl;
        if (printNext) {
            auto next2 = find_if(result.begin(), result.end(), [&end, &start](const DijkstraEntry &obj) { return obj.node != start && obj.node != end && obj.marked; });
            if (next2 != result.end()) {
                cout << "Test with " << next2->node << " instead" << endl;
            }
        }
        return;
    }

    // Loop true the result container and save the path into the stack
    int temp = end;
    stack<int> res;
    res.push(end);
    do {
        res.push(result[temp].predecessor);
        temp = result[temp].predecessor;
    } while (result[temp].node != start);

    // Output
    cout << "The shortest Path between \"" << start << "\" and \"" << end << "\" is:" << endl;
    while (!res.empty()) {
        cout << res.top();
        res.pop();
        if (!res.empty()) {
            cout << ", ";
        } else {
            cout << ";" << endl;
        }
    }

}

void GraphUtil::printShortestReach(Graph *g, int start, int end, bool printNext) {
    if (start < 0 || start >= g->getNumberOfNodes()) {
        cout << "Start value \"" << start << "\" is not in range!" << endl;
        return;
    } else if (end < 0 || end > g->getNumberOfNodes()) {
        cout << "End value \"" << end << "\" is not in range!" << endl;
        return;
    }

    vector<DijkstraEntry> result = GraphUtil::dijkstra(g, start, end);

    // Check if end is a node (also works for other data type)
    if (find_if(result.begin(), result.end(), [&end](const DijkstraEntry &obj) { return obj.node == end; }) == result.end()) {
        cout << "No connection from " << start << " to " << end << endl;
        if (printNext) {
            auto next2 = find_if(result.begin() + start + 1, result.end(), [&end](const DijkstraEntry &obj) { return obj.marked; });
            if (next2 != result.end()) {
                cout << "Test with " << next2->node << " instead" << endl;
            }
        }
        return;
    }
    int counter(1);
    int temp(end);
    do {
        counter++;
        temp = result[temp].predecessor;
    } while (result[temp].node != start);
    cout << "The path between \"" << start << "\" and \"" << end << "\" costs \"" << result[end].distance << "\" and has \"" << counter << "\" stations." << endl;
}
