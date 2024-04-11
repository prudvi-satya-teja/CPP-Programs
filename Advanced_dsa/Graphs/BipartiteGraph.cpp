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

    graph[1].push_back(Edge(1, 0)); 
    graph[1].push_back(Edge(1, 3));
    
    graph[2].push_back(Edge(2, 0)); 
    // graph[2].push_back(Edge(2, 4));
    
    graph[3].push_back(Edge(3, 1)); 
    graph[3].push_back(Edge(3, 4)); 
  
    // graph[4].push_back(Edge(4, 2)); 
    graph[4].push_back(Edge(4, 3));

}

bool isBipartite(vector<Edge> graph[]) {
    int col[5];

    for(int i=0; i<5; i++) {
        col[i] = -1;  // no color
    }

    queue<int> q ;

    for(int i=0; i<graph->size(); i++) {
        if(col[i] == -1) { // BFS
            q.push(i);
            col[i] = 0;    // yellow
           while(!q.empty()) {
                int curr = q.front();
                q.pop();

                for(int i=0; i<graph[curr].size(); i++) {
                    Edge e = graph[curr][i];  // e.dest
                   
                    if(col[e.dest] == -1) {
                        int nextCol = col[curr] == 0 ? 1 :0;
                        col[e.dest] = nextCol;
                         q.push(e.dest);
                    } else if(col[e.dest] == col[curr]) {
                        return false;    // NOT bipartite
                    }
                }
            
            }

        }
    }
   return true;

}

int main() {
    // if graph doesn't have cycles it is bipartite

     /*              
            1 ------- 3 
           /          | 
          0           |  
           \          | 
            2 ------- 4
            FALSE

    */

    
    int V = 5;
    vector<Edge> graph[V];
    createGraph(graph);

    cout<<isBipartite(graph);

    
    return 0;
}