#include<bits/stdc++.h>
using namespace std;

class Edge {
    public: 
    int src;
    int dest;

    Edge(int s, int d) {
        this->src = s;
        this->dest = d;
    }
};


void createGraph(vector<Edge> graph[]) {//O(V+E)

    graph[0].push_back(Edge(0, 1));
    graph[0].push_back(Edge(0, 2));
    graph[0].push_back(Edge(0, 3));

    graph[1].push_back(Edge(1, 0)); 
    graph[1].push_back(Edge(1, 2));
    
    graph[2].push_back(Edge(2, 0)); 
    graph[2].push_back(Edge(2, 1));
    
    graph[3].push_back(Edge(3, 0)); 
    graph[3].push_back(Edge(3, 4)); 
    // graph[3].push_back(Edge(3, 5)); 
  
    graph[4].push_back(Edge(4, 3));
    // graph[4].push_back(Edge(4, 5));

    // graph[5].push_back(Edge(5, 3));
    // graph[5].push_back(Edge(5, 4));

}
void dfs(vector<Edge> graph[], int curr, int par, int dt[], int low[], bool vis[], int time) {

    vis[curr] = true;
    dt[curr] = low[curr] = ++time;

    for(int i=0; i<graph[curr].size(); i++) {
        Edge e = graph[curr][i]; // e.src ----e.dest
        int neigh = e.dest;
        if(neigh == par) {
            continue;
        }
        else if(!vis[neigh]) {
            dfs(graph, neigh, curr, dt, low, vis, time);
            low[curr] = min(low[curr], low[neigh]);
            if(dt[curr] <low[neigh]) {
                cout<< "Bridge : " << curr << " -------" << neigh;
            }
        }
        else {
            low[curr] = min(low[curr], dt[neigh]);
        }
        
    }
    
}
void tarjanBridge(vector<Edge> graph[], int V) {
    int dt[V];
    int low[V];
    int time = 0;
    bool vis[V] = {false};

    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            dfs(graph, i, -1, dt, low, vis, time);
        }
    }
}

int main() {

    int V = 5;//6
    vector<Edge> graph[V];
    createGraph(graph);

    tarjanBridge(graph, V);

    
    return 0;
}