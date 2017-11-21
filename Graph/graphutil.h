#ifndef GRAPHUTIL_H
#define GRAPHUTIL_H
#include "graph.h"
#include <vector>
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
private:
    static vector<DijkstraEntry> dijkstra(Graph *g, int start, int end = -1);
    static void dijsktra(Graph *g, vector<DijkstraEntry> &entry, int start, int end, int lastSum = 0);

};

#endif

