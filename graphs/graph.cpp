#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Graph{

public:
    int numberOfNodes;
    vector<vector<int>> adjacentList;
    Graph(){
        numberOfNodes = 0;
        adjacentList = {};
    }

    void addVertex(){
        
        adjacentList.push_back({});
        numberOfNodes++;
    }

    void addEdge(int node1, int node2){
        adjacentList[node1].push_back(node2);
        adjacentList[node2].push_back(node1);
    }
};


int main(){
    Graph myGraph = Graph();
    cout << "initalized graph" << endl;
    myGraph.addVertex();
    myGraph.addVertex();
    myGraph.addVertex();
    myGraph.addVertex();
    myGraph.addVertex();
    myGraph.addVertex();
    myGraph.addVertex();
    myGraph.addEdge(3,1);
    myGraph.addEdge(3,4);
    myGraph.addEdge(4,2);
    myGraph.addEdge(4,5);
    myGraph.addEdge(1,2);
    myGraph.addEdge(1,0);
    myGraph.addEdge(0,2);
    myGraph.addEdge(6,5);
    int index = 0;
    for (vector<int> vec : myGraph.adjacentList){
        cout << "for node " << index << endl;
        for(int num : vec){
            cout << "has connection " << num << endl;
        }
        index++;
    }

    return 0;
}
