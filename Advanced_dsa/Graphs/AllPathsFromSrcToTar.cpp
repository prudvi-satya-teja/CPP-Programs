#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src, dest;
    Edge(int s, int d) : src(s), dest(d) {}
};

void createGraph(vector<Edge> graph[]) {

    graph[0].push_back(Edge(0, 3));
    graph[2].push_back(Edge(2, 3));
    graph[3].push_back(Edge(3, 1));
    graph[4].push_back(Edge(4, 0));
    graph[4].push_back(Edge(4, 1));
    graph[5].push_back(Edge(5, 0));
    graph[5].push_back(Edge(5, 2));
}

//exponential  time complexit
void printAllpath(vector<Edge> graph[], int src, int dest, string path) {
    if(src == dest) {
        cout<< path  << dest<<endl;
        return;
    }

    for(int i=0; i<graph[src].size(); i++) {
        Edge e = graph[src][i];
        printAllpath(graph, e.dest, dest, path+to_string(src));
    }
}
int main() {
    int V = 6; // Number of vertices
    vector<Edge> graph[V];
    createGraph(graph);

    int src = 5, dest = 1;
    printAllpath(graph,src, dest, "");

    return 0;
}
