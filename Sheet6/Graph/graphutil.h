#ifndef GRAPHUTIL_H
#define GRAPHUTIL_H
#include "graph.h"
#include <vector>
#include <deque>
using namespace std;


struct DijkstraEntry {
  int node = -1;
  int distance = -1;
  bool marked = false;
  int predecessor = -1;
};

class GraphUtil {
public:
    static void printShortestPath(Graph *g, int start, int end, bool printNext = false);
    static void printShortestReach(Graph *g, int start, int end, bool printNext = false);
    static bool allNodesAreReachable(Graph *g, int start);
    static vector<int> getMotherNodes(Graph *g);
    static void dfs(Graph *g);
    static void bfs(Graph *g);
    static bool connected(Graph *g, int nodeA, int nodeB);

private:
    static vector<DijkstraEntry> dijkstra(Graph *g, int start, int end = -1);
    static void dijsktra(Graph *g, vector<DijkstraEntry> &entry, int start, int end, int lastSum = 0);
    static void allNodesAreReachable(Graph *g, bool *visited, int currentNode);
    static void dfs(Graph *g, bool *visited, int currentNode);
    static void bfs(Graph *g, deque<int> &values, int currentNode, int i);
    static bool connected(Graph *g, deque<int> &values, int currentNode, int i, int search);
};

#endif

