#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <sstream>
#include <deque>
using namespace std;

class Graph {
private:
  vector< vector<int> > neighbours;
  vector< vector<int> > weights;
public:
  Graph();
  void randomInit(int nNodes=10, int nConnections=15, bool directed=false);
  int getNumberOfNodes();
  vector<int> getNeighbours(int node);
  vector<int> getWeights(int node);
  void addNode(vector<int> neighbours, vector<int> weights);

  friend std::ostream& operator<<(std::ostream& s, const Graph & obj);

};
void hasCycle(Graph *g, deque<int> &values, int currentNode, int i, bool &cycle);
bool hasCycle(Graph *g);
std::ostream& operator<<(std::ostream& s, const Graph & obj);

#endif
