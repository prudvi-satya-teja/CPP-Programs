#include<bits/stdc++.h>
using namespace std;

class Edge {
    public: 

    int source;
    int dest;
    int wt;

    
    Edge(int s, int d, int w) {
        this->source = s;
        this->dest = d;
        this->wt = w;
    }
};

int main() {

    /*
            (5)
        0 -------- 1
                 /   \
            (1) /     \   (3)
               /       \
               2 ------ 3
               |   (1)
           (2) |
               |
               4
    */

    int V = 5;
    //int graph[5];
    vector<Edge> graph[V];

    // 0   - vertex
    graph[0].push_back(Edge(0, 1, 5));

    // 1   - vertex
    graph[1].push_back(Edge(1, 0, 5)); 
    graph[1].push_back(Edge(1, 2, 1));
    graph[1].push_back(Edge(1, 3, 3));
    

    // 2   - vertex
    graph[2].push_back(Edge(2, 1, 1)); 
    graph[2].push_back(Edge(2, 3, 1));
    graph[2].push_back(Edge(2, 4, 2));
    

     // 3   - vertex
    graph[3].push_back(Edge(3, 1, 3)); 
    graph[3].push_back(Edge(3, 2, 1)); 
  
     // 4   - vertex
    graph[4].push_back(Edge(4, 2, 2)); 

    // 2's neighbours
    for(int i=0; i<graph[2].size(); i++) {
        Edge e = graph[2][i];   // src, dest, wt
        cout<< e.dest<<" ";
    }
    return 0;
}