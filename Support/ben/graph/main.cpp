#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

void print(vector<int> *graph, int numberOfNodes) {
    for (int i = 0; i < numberOfNodes; i++) {
        vector<int>::iterator it;
        cout << "Node " << i << "\t";
        for (it = graph[i].begin(); it != graph[i].end(); it++) {
            cout << *it << ", ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
}

vector<int> *create(int numberOfNodes, int numberOfConnections, bool directed = false) {
    vector<int> *result = new vector<int>[numberOfNodes];

    int counter = 0;
    while (counter < numberOfConnections) {
        int source = rand() % numberOfNodes;
        int target = rand() % numberOfNodes;
        if (source != target) {
            if (find(result[source].begin(), result[source].end(), target) == result[source].end()) {
                result[source].push_back(target);
                if (!directed) {
                    result[target].push_back(source);
                }
                counter++;
            }
        }
    }
    for (int i = 0; i < numberOfNodes; i++) {
        sort(result[i].begin(), result[i].end());
    }
    print(result, numberOfNodes);
    return result;
}
//---------------------------------------------------------------------------------------------------------------------//

//----------------AUFGABE 6.1----------------//
bool allNodeAreReachable(vector<int> *graph, int NUMBER_OF_NODES, int start) {
    bool check = true;
    bool *visited = new bool[NUMBER_OF_NODES];
    for (int i = 0; i < NUMBER_OF_NODES; i++) {
        visited[i] = false;
    }

    list<int> visitElements;

    visited[start] = true; //Besuchtes Element auf True setzten, da schon besucht
    visitElements.push_back(start); //Besuchtes Element in Liste speichern

    while (!visitElements.empty()) {
        start = visitElements.front();
        //cout<<"Aktuelle Node: "<<start<<endl;
        visitElements.pop_front();


        //Alle Nodes überprüfen
        for (vector<int>::iterator iter = graph[start].begin(); iter != graph[start].end(); iter++) {
            //cout<<*iter<<": ";
            //cout<<endl;
            if (!visited[*iter]) {
                visited[*iter] = true;
                //cout<<visited[*iter]<<", ";
                //cout<<endl;
                //check = false;
                visitElements.push_back(*iter);
            }
            /*else{
                check = true;
            }*/
        }
        /*
        cout<<"-------VisitedElement--------"<<endl;
        for(list<int>::iterator it = visitElements.begin(); it != visitElements.end(); it++){
            cout<<*it<<", ";
        }
        cout<<endl;
        */
    }
    for (int i = 0; i < NUMBER_OF_NODES; i++) {
        if (visited[i] == true && check == true) {
            // cout<<visited[i]<<", ";
            check = true;
        } else check = false;
    }
    return check;
}

//----------------AUFGABE 6.2----------------//
int shortestReach(vector<int> *graph, int NUMBER_OF_NODES, int start, int end) {

}

//----------------AUFGABE 6.3----------------//
vector<int> getPath(vector<int> *graph, int NUMBER_OF_NODES, int start, int end) {
    bool *visited = new bool[NUMBER_OF_NODES];
    for (int i = 0; i < NUMBER_OF_NODES; ++i) {
        visited[i] = false;
    }
    cout << endl;
    cout << "<<<-----Aufgabe 6.3 alle Elemente von start bis end----->>>" << endl;
    cout << "Start: " << start << endl;
    cout << "Ende: " << end << endl;
    vector<int> visitedElements;
    vector<int>::iterator iter;
    visited[start] = true;

    vector<int>::iterator it;
    for (int i = start; i < end; i++) {
        for (it = graph[i].begin(); it != graph[i].end(); it++) {
            if (!visited[*it]) {
                visited[*it] = true;
                visitedElements.push_back(*it);
            }
        }
    }
    for (it = visitedElements.begin(); it != visitedElements.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;
    cout << "-----------------------" << endl;
    return visitedElements;
}

//----------------AUFGABE 6.4----------------//
vector<int> getMotherNodes(vector<int> *graph, int NUMBER_OF_NODES) {
    cout << endl;
    cout << "<<<-----Aufgabe 6.4 Mother Nodes----->>>" << endl;

    vector<int> motherNodes;
    vector<int>::iterator it;
    for (int i = 0; i < NUMBER_OF_NODES; i++) {
        if (allNodeAreReachable(graph, NUMBER_OF_NODES, i)) {
            motherNodes.push_back(i);
        }
    }
    /**/
    if (!motherNodes.empty()) {
        for (it = motherNodes.begin(); it != motherNodes.end(); it++) {
            cout << *it << ", ";
        }
    } else {
        cout << "Keine Mother Node vorhanden!" << endl;
    }
    cout << endl;
    cout << "-----------------------" << endl;

    return motherNodes;
}


//-----------------------------------MAIN--------------------------------------------//
int main(int argc, char **argv) {
    int start = 3;
    int end = 8;
    const int NUMBER_OF_NODES = 10;
    const int NUMBER_OF_CONNECTIONS = 14;
    //print(create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS), NUMBER_OF_NODES);
    /*
    if(allNodeAreReachable(create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS), NUMBER_OF_NODES, start) == true){
      cout<<"Alle Nodes sind erreichbar!"<<endl;
      cout <<"-----------------------"<< endl;
    }else{
      cout<<"Nicht alle Nodes erreicht!"<<endl;
      cout <<"-----------------------"<< endl;
    }
    */
    //getPath(create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS), NUMBER_OF_NODES, start, end);
    getMotherNodes(create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS, true), NUMBER_OF_NODES);

    return 0;
}