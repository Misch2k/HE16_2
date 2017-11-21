#include "graph.h"
#include "graphutil.h"
#include "../../myFunctions/functions.h"

using namespace std;

int main(int argc, char **argv) {
    // Parameter to test the right method
    bool a_dfs(false);
    bool a_bfs(false);
    bool a_connected(false);
    int connected_from(3), connected_to(5);
    bool a_allNodesArReachable(false);
    int reachable_from(5);
    bool a_shortestReach(true);
    int shortestReach_from(0), shortestReach_to(3);
    bool a_printShortestPath(true);
    int shortestPath_from(3), shortestPath_to(0);
    bool a_getMotherNodes(false);

    srand(12);

    // undirected graph
    const int NUMBER_OF_NODES = 10;
    const int NUMBER_OF_CONNECTIONS = 10;
    auto *graph = new Graph(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS);


    //directed graph
    const int NUMBER_OF_NODES2 = 10;
    const int NUMBER_OF_CONNECTIONS2 = 10;
    auto *dirGraph = new Graph(NUMBER_OF_NODES2, NUMBER_OF_CONNECTIONS2, true);

    // Print the right graph
    if (a_dfs || a_bfs || a_connected || a_shortestReach) {
        cout << "Undirected graph" << endl;
        cout << "=================" << endl;
        cout << *graph << endl;
        cout << "=================" << endl << endl;
    }
    if (a_allNodesArReachable || a_printShortestPath || a_getMotherNodes) {
        cout << "Directed graph" << endl;
        cout << "=================" << endl;
        cout << *dirGraph << endl;
        cout << "=================" << endl << endl;
    }

    // Print test cases
    if (a_dfs) {
        cout << "DFS" << endl;
        cout << "=================" << endl;
        GraphUtil::dfs(graph);
        cout << "=================" << endl << endl;
    }

    if (a_bfs) {
        cout << "BFS" << endl;
        cout << "=================" << endl;
        GraphUtil::bfs(graph);
        cout << "=================" << endl << endl;
    }

    if (a_connected) {
        cout << "Connected " << endl;
        cout << "=================" << endl;
        cout << "Is " << connected_from << " connected with " << connected_to << "?" << endl;
        cout << (GraphUtil::connected(graph, connected_from, connected_to) ? "CONNECTED" : "NOT CONNECTED")<< endl;
        cout << "=================" << endl << endl;
    }

    if (a_allNodesArReachable) {
        cout << "All Nodes Are Reachable" << endl;
        cout << "=================" << endl;
        cout << "Are all nodes reachable from " << reachable_from << "?" << endl;
        cout << (GraphUtil::allNodesAreReachable(dirGraph, reachable_from) ? "ALL NODES ARE REACHABLE" : "NOT ALL NODES ARE REACHABLE") << endl;
        cout << "=================" << endl << endl;
    }

    if (a_shortestReach) {
        cout << "Shortest Reach " << endl;
        cout << "=================" << endl;
        cout << "How long is the shortest path between " << shortestReach_from << " and " << shortestReach_to << "?" << endl;
        GraphUtil::printShortestReach(graph, shortestReach_from, shortestReach_to, true);
        cout << "=================" << endl << endl;
    }


    if (a_printShortestPath) {
        cout << "Get shortest Path " << endl;
        cout << "=================" << endl;
        GraphUtil::printShortestPath(dirGraph, shortestPath_from, shortestPath_to, true);
        cout << "=================" << endl << endl;
    }

    if (a_getMotherNodes) {
        cout << "Get mother nodes" << endl;
        cout << "=================" << endl;
        vector<int> result = GraphUtil::getMotherNodes(dirGraph);
        cout << "This are all mother nodes in the directed graph:" << endl;
        for (int val : result) {
            cout << val << ", ";
        }
        cout << endl;
        cout << "=================" << endl << endl;
    }


    delete graph;
    delete dirGraph;
    return 0;
}
