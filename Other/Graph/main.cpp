#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <deque>


using namespace std;

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
    if(size == 0) return;
    deque<int> result = {0};
    bfs(graph, result, 0, 0);

    cout << "BFS: ";
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
 * @return
 */
bool connected(vector<int> *graph, int numberOfNodes, int nodeA, int nodeB) {

}


int main() {
    srand(15);

    const int NUMBER_OF_NODES = 17;
    const int NUMBER_OF_CONNECTIONS = 10;

    vector<int> *graph = SampleGraph::create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS);

    //SampleGraph::print(graph, NUMBER_OF_NODES);

    //dfs(graph, NUMBER_OF_NODES);
    //cout << "DFS: " << endl;
    //dfs(graph, NUMBER_OF_NODES);
    //cout << "BFS: " << endl;
    //bfs(graph, NUMBER_OF_NODES);

    cout << endl << endl;

    //cout << (connected(graph, NUMBER_OF_NODES, 5, 13) ? "CONNECTED" : "NOT CONNECTED") << endl;



    return 0;
}