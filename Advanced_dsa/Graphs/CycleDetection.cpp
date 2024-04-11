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


void createGraph(vector<Edge> graph[]) {

    graph[0].push_back(Edge(0, 1));
    graph[0].push_back(Edge(0, 2));
    graph[0].push_back(Edge(0, 3)); 

    graph[1].push_back(Edge(1, 0));
    graph[1].push_back(Edge(1, 2)); 
    
    graph[2].push_back(Edge(2, 0)); 
    graph[2].push_back(Edge(2, 1));
    
    
    graph[3].push_back(Edge(3, 0)); 
    graph[3].push_back(Edge(3, 4)); 
  
    graph[4].push_back(Edge(4, 3)); 
   

}

bool detectCycleUtil(vector<Edge> graph[], bool vis[], int curr, int par) {
    vis[curr] = true;

    for(int i=0; i<graph[curr].size(); i++) {
        Edge e = graph[curr][i];
        //case 3
        if(!vis[e.dest] ) {
            if(detectCycleUtil(graph, vis, e.dest, curr)) {  
                return true;
            }
        }
        // case 1
        else if(vis[e.dest] && e.dest != par) {
            return true;
        }
        // case 2 ->do nothing ->continue
    }
    return false;
}

bool detectCycle(vector<Edge> graph[]) {
    bool vis[5] = {false};
    for(int i=0; i<graph->size(); i++) {
        if(!vis[i]) {
            if(detectCycleUtil(graph, vis , i, -1)) {
                return true;
                //cycle exits in one of the paths
            }
        }
    }
    return false;
}


int main() {

     /*              
             0 ------- 3 
           / |         | 
          1  |         |  
           \ |         4 
             2 

    */

    
    int V = 5;
    vector<Edge> graph[V];
    createGraph(graph);

    
    cout<<detectCycle(graph);

    
    return 0;
}