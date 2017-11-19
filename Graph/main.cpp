#include "graph.h"
#include "graphutil.h"
#include "../myFunctions/functions.h"

using namespace std;

int main(int argc, char **argv) {

    auto *g = new Graph;
    auto *g2 = new Graph;
    // Undirected Graph
    g->randomInit(4000, 4000);
    // Directed Graph
    g2->randomInit(4000, 20000, true);





    // Undirected Graph
    auto start = myTime::start();
    GraphUtil::printShortestReach(g, 7, 8, true) ;
    GraphUtil::printShortestPath(g, 7, 8, true);
    myTime::stop(start, 3);

    start = myTime::start();
    GraphUtil::printShortestReach(g, 8, 7, true) ;
    GraphUtil::printShortestPath(g, 8, 7, true);
    myTime::stop(start, 3);

    start = myTime::start();
    GraphUtil::printShortestReach(g2, 7, 8, true) ;
    GraphUtil::printShortestPath(g2, 7, 8, true);
    myTime::stop(start, 3);

    start = myTime::start();
    GraphUtil::printShortestReach(g2, 9, 7, true) ;
    GraphUtil::printShortestPath(g2, 9, 7, true);
    myTime::stop(start, 3);


    delete g;
    delete g2;
    return 0;
}
