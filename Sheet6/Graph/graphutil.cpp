#include "graphutil.h"
#include <stack>

/**
 * Return a Dijkstra entry object to analyse
 * @param g
 * @param start
 * @param end
 * @return
 */
vector<DijkstraEntry> GraphUtil::dijkstra(Graph *g, int start, int end) {
    vector<DijkstraEntry> entry((unsigned int) g->getNumberOfNodes());
    GraphUtil::dijsktra(g, entry, start, end);
    return entry;
}

/**
 * Dijsktra algorithm
 * @param g
 * @param entry
 * @param NodeId
 * @param end
 * @param lastSum
 */
void GraphUtil::dijsktra(Graph *g, vector<DijkstraEntry> &entry, int NodeId, int end, int lastSum) {
    // end is marked and there is no shorter path
    if (NodeId == end) return;
    entry[NodeId].node = NodeId;
    entry[NodeId].marked = true;
    auto updateEntry = [&entry, &lastSum, &NodeId](const Neighbours &obj) {
        if (!entry[obj.target].marked && (entry[obj.target].distance == -1 || entry[obj.target].distance > lastSum + obj.weight)) {
            entry[obj.target].node = obj.target;
            entry[obj.target].distance = lastSum + obj.weight;
            entry[obj.target].predecessor = NodeId;
        }
    };
    for_each(g->entry[NodeId].neighbours.begin(), g->entry[NodeId].neighbours.end(), updateEntry);

    int distance(0), node(0);
    bool first(true);
    auto getNext = [&entry, &first, &distance, &node](const DijkstraEntry &obj) {
        if (obj.node != -1 && !entry[obj.node].marked) {
            if (first) {
                node = obj.node;
                distance = entry[obj.node].distance;
                first = false;
            } else if (distance > entry[obj.node].distance) {
                distance = entry[obj.node].distance;
                node = entry[obj.node].node;

            }
        }
    };
    for_each(entry.rbegin(), entry.rend(), getNext);
    if (distance == 0) return;
    GraphUtil::dijsktra(g, entry, node, end, distance);
}

/**
 * Print the shortest path
 * @param g
 * @param start
 * @param end
 * @param printNext
 */
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

/**
 * Print the shortest reach
 * @param g
 * @param start
 * @param end
 * @param printNext
 */
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
            auto next2 = find_if(result.begin(), result.end(), [&end, &start](const DijkstraEntry &obj) {return obj.node != start && obj.node != end && obj.marked;});
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

/**
 * print true if all nodes are reachable from starting node - recusrive
 * @param g
 * @param visited
 * @param currentNode
 */
void GraphUtil::allNodesAreReachable(Graph *g, bool *visited, int currentNode) {
    visited[currentNode] = true;
    for_each(g->entry[currentNode].neighbours.begin(), g->entry[currentNode].neighbours.end(), [&](const Neighbours &obj){
        if(!visited[obj.target]){
            allNodesAreReachable(g, visited, obj.target);
        }
    });
}

/**
 * print true if all nodes are reachable from starting node
 * @param g
 * @param start
 * @return
 */
bool GraphUtil::allNodesAreReachable(Graph *g, int start) {
    if(start < 0 || start > g->getNumberOfNodes()) return false;
    auto *visited = new bool[g->getNumberOfNodes()]{false};
    allNodesAreReachable(g, visited, start);
    for (int i = 0; i < g->getNumberOfNodes(); ++i) {
        if (!visited[i]){
            delete visited;
            return false;
        }
    }
    delete visited;
    return true;
}

/**
 * Print all nodes which is connected with each other
 * @param g
 * @return
 */
vector<int> GraphUtil::getMotherNodes(Graph *g) {
    vector<int> result;
    for (int i = 0; i < g->getNumberOfNodes(); ++i) {
        if (allNodesAreReachable(g, i)) {
            result.push_back(i);
        }
    }
    return result;
}

/**
 * Print deep first search - recursive
 * @param g
 * @param visited
 * @param currentNode
 */
void GraphUtil::dfs(Graph *g, bool *visited, int currentNode) {
    visited[currentNode] = true;
    cout << currentNode << ",";
    for (Neighbours node : g->entry[currentNode].neighbours) {
        if (!visited[node.target]) {
            dfs(g, visited, node.target);
        }
    }
}

/**
 * print deep first search
 * @param g
 */
void GraphUtil::dfs(Graph *g) {
    auto *visited = new bool[g->getNumberOfNodes()]{false};
    dfs(g, visited, 0);
    cout << endl;
}

/**
 * print bread first search - recursive
 * @param g
 * @param values
 * @param currentNode
 * @param i
 */
void GraphUtil::bfs(Graph *g, deque<int> &values, int currentNode, int i) {
    for (auto v : g->entry[currentNode].neighbours) {
        if (find(values.begin(), values.end(), v.target) == values.end()) {
            values.push_back(v.target);
        };
    }
    if (++i < values.size()) {
        bfs(g, values, values[i], i);
    }
}

/**
 * print bread first search
 * @param g
 */
void GraphUtil::bfs(Graph *g) {
    deque<int> result = {0};
    bfs(g, result, 0, 0);
    for (int v : result) {
        cout << v << ", ";
    }
    cout << endl;
}

/**
 * return true if this two nodes are connected - recursive
 * @param g
 * @param values
 * @param currentNode
 * @param i
 * @param search
 * @return
 */
bool GraphUtil::connected(Graph *g, deque<int> &values, int currentNode, int i, int search) {
    for (auto v : g->entry[currentNode].neighbours) {
        if (find(values.begin(), values.end(), v.target) == values.end()) {
            values.push_back(v.target);
            if (v.target == search) {
                return true;
            }
        };
    }
    if (++i < values.size()) {
        return GraphUtil::connected(g, values, values[i], i, search);
    }
    return false;
}

/**
 * * return true if this two nodes are connected
 * @param g
 * @param nodeA
 * @param nodeB
 * @return
 */
bool GraphUtil::connected(Graph *g, int nodeA, int nodeB) {
    if (nodeA < 0 || nodeA >= g->getNumberOfNodes() || nodeB < 0 || nodeB >= g->getNumberOfNodes()) return false;
    if (nodeA == nodeB) return true;
    deque<int> result = {nodeA};
    bool res = GraphUtil::connected(g, result, nodeA, 0, nodeB);
    for (int v : result) {
        cout << v << ",";
    }
    cout << endl;
    return res;
}