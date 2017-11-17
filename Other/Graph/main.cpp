#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

struct Node {
    int last = 0;
    int sum = 0;
    bool visited = false;
};

class SampleGraph {
public:
    static vector<int> *create(int numberOfNodes, int numberOfConnections, bool isDirected);

    static void print(vector<int> *graph, int numberOfNodes);
};

/**
 * Constructor
 * @param numberOfNodes
 * @param numberOfConnections
 * @param isDirected
 * @return
 */
vector<int> *SampleGraph::create(int numberOfNodes, int numberOfConnections, bool isDirected = false) {
    auto *result = new vector<int>[numberOfNodes];

    int counter = 0;
    while (counter < numberOfConnections) {
        int source = rand() % numberOfNodes;
        int target = rand() % numberOfNodes;
        if (source != target) {
            if (find(result[source].begin(), result[source].end(), target) == result[source].end()) {
                result[source].push_back(target);
                if (!isDirected) result[target].push_back(source);
                counter++;
            }
        }
    }
    for (int i = 0; i < numberOfNodes; i++) {
        sort(result[i].begin(), result[i].end());
    }

    return result;
}

/**
 * Print
 * @param graph
 * @param numberOfNodes
 */
void SampleGraph::print(vector<int> *graph, int numberOfNodes) {
    for (int i = 0; i < numberOfNodes; i++) {
        vector<int>::iterator it;
        cout << "Node " << i << "\t";
        for (it = graph[i].begin(); it != graph[i].end(); it++) {
            cout << *it << ", ";
        }
        cout << endl;
    }
}

/**
 * Tiefensuche
 * @param graph
 * @param numberOfNodes
 * @param visited
 * @param currentNode
 */
void dfs(vector<int> *graph, int numberOfNodes, bool *visited, int currentNode) {

    visited[currentNode] = true;
    cout << currentNode << ",";

    for (int node : graph[currentNode]) {
        if (!visited[node]) {
            dfs(graph, numberOfNodes, visited, node);
        }
    }
}

/**
 * Tiefensuche
 * @param graph
 * @param numberOfNodes
 */
void dfs(vector<int> *graph, int numberOfNodes) {
    auto *visited = new bool[numberOfNodes]{false};

    dfs(graph, numberOfNodes, visited, 0);
    cout << endl;

}


/**
 * Breitensuche
 * @param graph
 * @param values
 * @param currentNode
 * @param i
 */
void bfs(vector<int> *graph, deque<int> &values, int currentNode, int i) {
    for (int v : graph[currentNode]) {
        if (find(values.begin(), values.end(), v) == values.end()) {
            values.push_back(v);
        };
    }
    if (++i < values.size()) {
        bfs(graph, values, values[i], i);
    }
}

/**
 * Breitensuche
 * @param graph
 * @param size
 */
void bfs(vector<int> *graph, int size) {
    if (size == 0) return;
    deque<int> result = {0};
    bfs(graph, result, 0, 0);

    for (int v : result) {
        cout << v << ", ";
    }
    cout << endl;
}

/**
 * Connected
 * @param graph
 * @param numberOfNodes
 * @param nodeA
 * @param nodeB
 */
bool connected(vector<int> *graph, deque<int> &values, int currentNode, int i, int search) {
    for (int v : graph[currentNode]) {
        if (find(values.begin(), values.end(), v) == values.end()) {
            values.push_back(v);
            if (v == search) {
                return true;
            }
        };
    }
    if (++i < values.size()) {
        return connected(graph, values, values[i], i, search);
    }
    return false;
}

/**
 * Connected
 * @param graph
 * @param numberOfNodes
 * @param nodeA
 * @param nodeB
 * @return
 */
bool connected(vector<int> *graph, int numberOfNodes, int nodeA, int nodeB) {
    if (nodeA < 0 || nodeA >= numberOfNodes || nodeB < 0 || nodeB >= numberOfNodes) return false;
    if (nodeA == nodeB) return true;
    deque<int> result = {nodeA};
    bool res = connected(graph, result, nodeA, 0, nodeB);

    for (int v : result) {
        cout << v << ",";
    }
    cout << endl;

    return res;
}

/**
 * All Modes Are Reachable - rec
 * @param graph
 * @param visited
 * @param currentNode
 */
void allNodesAreReachable(vector<int> *graph, bool *visited, int currentNode) {
    visited[currentNode] = true;
    for (int node : graph[currentNode]) {
        if (!visited[node]) {
            allNodesAreReachable(graph, visited, node);
        }
    }
}

/**
 * All Nodes Are Reachable
 * @param graph
 * @param NUMBER_OF_NODES
 * @param start
 * @return
 */
bool allNodesAreReachable(vector<int> *graph, int NUMBER_OF_NODES, int start) {
    auto *visited = new bool[NUMBER_OF_NODES]{false};

    allNodesAreReachable(graph, visited, start);

    for (int i = 0; i < NUMBER_OF_NODES; ++i) {
        if (!visited[i]) return false;
    }
    return true;
}

/**
 * Shortest Reach - recursive
 * @param graph
 * @param visited
 * @param start
 * @param sumLast
 */
void shortestReach(vector<int> *graph, vector<Node> &visited, int start, int sumLast = 0) {
    visited[start].visited = true;
    for (int v : graph[start]) {
        if (visited[v].sum == 0 || visited[v].sum > sumLast + 1) {
            visited[v].sum = sumLast + 1;
            visited[v].last = start;
        }
    }
    auto next = make_pair<int, int>(0, 0);
    int i(0);
    for (Node v : visited) {
        if (!v.visited && v.sum != 0) {
            if (next.first == 0) {
                next.second = i;
                next.first = v.sum;
            } else if (next.first > v.sum) {
                next.first = v.sum;
                next.second = i;
            }
        }
        i++;
    }
    if (next.first == 0) return;
    shortestReach(graph, visited, next.second, next.first);

}

/**
 * Shortest reach
 * @param graph
 * @param NUMBER_OF_NODES
 * @param start
 * @param end
 * @return
 */
int shortestReach(vector<int> *graph, int NUMBER_OF_NODES, int start, int end) {
    if (start < 0 || start >= NUMBER_OF_NODES || end < 0 || end >= NUMBER_OF_NODES) return -1;
    if (start == end) return 0;
    vector<Node> visited((unsigned int) NUMBER_OF_NODES);
    shortestReach(graph, visited, start, 0);
    if (visited[end].last == 0) return -1;
    int counter = 0;
    int pointer = end;
    while (pointer != start) {
        pointer = visited[pointer].last;
        counter++;
    }
    return counter;

}

/**
 * Get the shortest path
 * @param graph
 * @param NUMBER_OF_NODES
 * @param start
 * @param end
 * @return
 */
vector<int> getPath(vector<int> *graph, int NUMBER_OF_NODES, int start, int end) {
    if (start == end) return vector<int>(0);
    vector<Node> visited((unsigned int) NUMBER_OF_NODES);
    vector<int> result;
    shortestReach(graph, visited, start, 0);
    if (visited[end].last == 0) return vector<int>(0);
    int pointer = end;
    while (pointer != start) {
        result.push_back(pointer);
        pointer = visited[pointer].last;
    }
    result.push_back(start);
    return result;
}

/**
 * Get mother nodes
 * @param graph
 * @param NUMBER_OF_NODES
 * @return
 */
vector<int> getMotherNodes(vector<int> *graph, int NUMBER_OF_NODES) {
    vector<int> result;
    for (int i = 0; i < NUMBER_OF_NODES; ++i) {
        if (allNodesAreReachable(graph, NUMBER_OF_NODES, i)) {
            result.push_back(i);
        }
    }
    return result;
}


int main() {
    // Parameter to test the right method
    bool a_dfs(false);
    bool a_bfs(false);
    bool a_connected(false);
    int connected_from(3), connected_to(5);
    bool a_allNodesArReachable(false);
    int reachable_from(5);
    bool a_shortestReach(false);
    int shortestReach_from(7), shortestReach_to(0);
    bool a_printShortestPath(false);
    int shortestPath_from(0), shortestPath_to(7);
    bool a_getMotherNodes(true);

    srand(15);

    // undirected graph
    const int NUMBER_OF_NODES = 10;
    const int NUMBER_OF_CONNECTIONS = 10;
    vector<int> *graph = SampleGraph::create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS);

    //directed graph
    const int NUMBER_OF_NODES2 = 10;
    const int NUMBER_OF_CONNECTIONS2 = 20;
    vector<int> *dirGraph = SampleGraph::create(NUMBER_OF_NODES2, NUMBER_OF_CONNECTIONS2, true);

    // Print the right graph
    if (a_dfs || a_bfs || a_connected || a_shortestReach) {
        cout << "Undirected graph" << endl;
        cout << "=================" << endl;
        SampleGraph::print(graph, NUMBER_OF_NODES);
        cout << "=================" << endl << endl;
    }
    if (a_allNodesArReachable || a_printShortestPath || a_getMotherNodes) {
        cout << "Directed graph" << endl;
        cout << "=================" << endl;
        SampleGraph::print(dirGraph, NUMBER_OF_NODES2);
        cout << "=================" << endl << endl;
    }

    // Print test cases
    if (a_dfs) {
        cout << "DFS" << endl;
        cout << "=================" << endl;
        dfs(graph, NUMBER_OF_NODES);
        cout << "=================" << endl;
    }

    if (a_bfs) {
        cout << "BFS" << endl;
        cout << "=================" << endl;
        bfs(graph, NUMBER_OF_NODES);
        cout << "=================" << endl;
    }

    if (a_connected) {
        cout << "Connected " << endl;
        cout << "=================" << endl;
        cout << "Is " << connected_from << " connected with " << connected_to << "?" << endl;
        cout << (connected(graph, NUMBER_OF_NODES, connected_from, connected_to) ? "CONNECTED" : "NOT CONNECTED")
             << endl;
    }

    if (a_allNodesArReachable) {
        cout << "All Nodes Are Reachable" << endl;
        cout << "=================" << endl;
        cout << "Are all nodes reachable from " << reachable_from << "?" << endl;
        cout << (allNodesAreReachable(dirGraph, NUMBER_OF_NODES2, reachable_from) ? "ALL NODES ARE REACHABLE"
                                                                                  : "NOT ALL NODES ARE REACHABLE")
             << endl;
    }

    if (a_shortestReach) {
        cout << "Shortest Reach " << endl;
        cout << "=================" << endl;
        cout << "How long is the shortest path between " << shortestReach_from << " and " << shortestReach_to << "?"
             << endl;
        cout << shortestReach(graph, NUMBER_OF_NODES, shortestReach_from, shortestReach_to) << endl;
    }


    if (a_printShortestPath) {
        cout << "Get shortest Path " << endl;
        cout << "=================" << endl;
        vector<int> result = getPath(dirGraph, NUMBER_OF_NODES2, shortestPath_from, shortestPath_to);
        reverse(result.begin(), result.end());
        cout << "The shortest path between " << shortestPath_from << " and " << shortestPath_to << " is:" << endl;
        for (int val : result) {
            cout << val << ", ";
        }
        cout << endl;
    }

    if (a_getMotherNodes) {
        cout << "Get mother nodes" << endl;
        cout << "=================" << endl;
        vector<int> result = getMotherNodes(dirGraph, NUMBER_OF_NODES2);
        cout << "This are all mother nodes in the directed graph:" << endl;
        for (int val : result) {
            cout << val << ", ";
        }
        cout << endl;
    }

    return 0;
}