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

    graph[0].push_back(Edge(0, 2));
    graph[0].push_back(Edge(0, 3));

    graph[1].push_back(Edge(1, 0)); 
    
    graph[2].push_back(Edge(2, 1)); 
    
    graph[3].push_back(Edge(3, 4)); 

}
void dfs(vector<Edge> graph[], int curr, bool vis[]) {
    vis[curr] = true;
    cout<< curr << " ";
    for(int i=0; i<graph[curr].size(); i++) {
        Edge e = graph[curr][i];
        if(!vis[e.dest]) {
            dfs(graph, e.dest, vis);
        }
    }
}
void topSort(vector<Edge> graph[], int curr, bool vis[], stack<int> &s) {
    vis[curr] = true;

    for(int i=0; i<graph[curr].size(); i++) {
        Edge e = graph[curr][i];
        if(!vis[e.dest]) {
            topSort(graph, e.dest, vis, s);
        }
    }
    s.push(curr);
}
void kosaraju(vector<Edge> graph[], int V) {
    //Step1
    stack<int> s ;
    bool vis[V] = {false};
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            topSort(graph, i, vis, s);
        }
    }

    //Step2
    for(int i=0; i<V; i++) {
        vis[i] = false;
    }
    vector<Edge> transpose[V];
    for(int i=0; i<V; i++) {
        for(int j=0; j<graph[i].size(); j++) {
            Edge e = graph[i][j];   // e.src -> e.dest
            transpose[e.dest].push_back( Edge(e.dest, e.src)); // reverse edge

        }
    }

    // Step3
    while(!s.empty()) {
        int curr = s.top();
        s.pop();
        if(!vis[curr]) {
            cout<<"SSC -> "<<" ";
            dfs(transpose, curr,vis);
            cout<<endl;
        }
    }
}

int main() {

    int V = 5;
    vector<Edge> graph[V];
    createGraph(graph);

    kosaraju(graph, V);

    return 0;
}