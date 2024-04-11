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


void bfs(vector<Edge> graph[]) {    // O(N)
    queue<int> q ;
    bool vis[graph->size()] = {false};
    q.push(0);  // source = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        if(!vis[curr]) {  // visit curr
            cout<<curr << " ";
            vis[curr] = true;
            for(int i=0; i<graph[curr].size(); i++) {
                Edge e = graph[curr][i];
                q.push(e.dest);
            }
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

    bfs(graph);

    
    return 0;
}