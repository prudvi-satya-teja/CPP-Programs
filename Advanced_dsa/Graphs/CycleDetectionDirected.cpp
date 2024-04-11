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

void createGraph(vector<Edge> graph[]) { // TRUE- cycle

    // true
    // graph[0].push_back(Edge(0, 2));

    // graph[1].push_back(Edge(1, 0));
    
    // graph[2].push_back(Edge(2, 3)); 
    
    // graph[3].push_back(Edge(3, 0)); 

    // false
    graph[0].push_back(Edge(0, 1));
     graph[0].push_back(Edge(0, 2));

    graph[1].push_back(Edge(1, 3));
    
    graph[2].push_back(Edge(2, 3)); 

}

bool isCycleUtil(vector<Edge> graph[], int curr,  bool vis[], bool stack[]) {
    vis[curr] = true;
    stack[curr] = true;

    for(int i=0; i<graph[curr].size(); i++) {
        Edge e = graph[curr][i];
        if(stack[e.dest]) {
            return true;
        }
        else if(!vis[e.dest] && isCycleUtil(graph, e.dest, vis,  stack)) {  
                return true;
            }
        }
    
    stack[curr] = false;
    return false;
}

bool isCycle(vector<Edge> graph[]) {
    bool vis[5] = {false};
    bool stack[5]= {false} ;
    for(int i=0; i<graph->size(); i++) {
        if(!vis[i]) {
            if(isCycleUtil(graph, i, vis , stack)) {
                return true;
            }
        }
    }
    return false;
}


int main() {

     /*              
           1--->  0 ------->2
                   \         | 
                    \        |  
                      \      3 
               

    */

    
    int V = 4;
    vector<Edge> graph[V];
    createGraph(graph);

    
    cout<<isCycle(graph);

    
    return 0;
}