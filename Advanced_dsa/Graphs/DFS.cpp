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


void createGraph(vector<Edge> graph[]) {

    graph[0].push_back(Edge(0, 1, 1));
    graph[0].push_back(Edge(0, 2, 1));

    graph[1].push_back(Edge(1, 0, 1)); 
    graph[1].push_back(Edge(1, 3, 1));
    
    graph[2].push_back(Edge(2, 0, 1)); 
    graph[2].push_back(Edge(2, 4, 1));
    
    graph[3].push_back(Edge(3, 1, 1)); 
    graph[3].push_back(Edge(3, 4, 1)); 
    graph[3].push_back(Edge(3, 5, 1)); 
  
    graph[4].push_back(Edge(4, 2, 1)); 
    graph[4].push_back(Edge(4, 3, 1));
    graph[4].push_back(Edge(4, 5, 1));

    graph[5].push_back(Edge(5, 3, 1));
    graph[5].push_back(Edge(5, 4, 1));
    graph[5].push_back(Edge(5, 6, 1));

    graph[6].push_back(Edge(6, 5, 1));

}

void dfs(vector<Edge> graph[], int curr, bool vis[]) {  // O(V+E)
    //visit
    cout<< curr <<" ";
    vis[curr] = true;

    for(int i=0; i<graph[curr].size(); i++) {
        Edge e = graph[curr][i];
        if(!vis[e.dest]) {
            dfs(graph, e.dest, vis);
        }
    }

} 

int main() {

     /*              
            1 ------- 3 
           /          | \
          0           |  5 -- 6
           \          | /
            2 ------- 4

    */

    
    int V = 7;
    vector<Edge> graph[V];
    createGraph(graph);

    bool vis[V] = {false};

    dfs(graph, 0, vis);

    
    return 0;
}