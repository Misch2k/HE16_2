#include <iostream>
#include "graphgen.h"
#include "graph.h"

int main() {

        cout << "Has Cycle" << endl;
        cout << "=================" << endl;
        auto result = hasCycle(GraphGenerator::createGraph1());
        cout << "The Graph " << (result ? "has a cycle" : "don't hava a cycle") << endl;
        result = hasCycle(GraphGenerator::createGraph2());
        cout << "The Graph " << (result ? "has a cycle" : "don't hava a cycle") << endl;
        result = hasCycle(GraphGenerator::createGraph3());
        cout << "The Graph " << (result ? "has a cycle" : "don't hava a cycle") << endl;
        result = hasCycle(GraphGenerator::createGraph4());
        cout << "The Graph " << (result ? "has a cycle" : "don't hava a cycle") << endl;
        result = hasCycle(GraphGenerator::createGraph5());
        cout << "The Graph " << (result ? "has a cycle" : "don't hava a cycle") << endl;
        cout << "=================" << endl << endl;

return 0;
}