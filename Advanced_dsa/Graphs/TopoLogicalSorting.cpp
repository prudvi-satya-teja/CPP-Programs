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
    graph[2].push_back(Edge(2, 3));
    graph[3].push_back(Edge(3, 1));
    graph[4].push_back(Edge(4, 0));
    graph[4].push_back(Edge(4, 1));
    graph[5].push_back(Edge(5, 0));
    graph[5].push_back(Edge(5, 2));
}

//O(V+E)
void topSortUtil(vector<Edge> graph[], int curr, bool vis[], stack<int>& s) {
    vis[curr] = true;

    for(int i = 0; i < graph[curr].size(); i++) {
        Edge e = graph[curr][i];
        if(!vis[e.dest]) {
            topSortUtil(graph, e.dest, vis, s);
        }
    }
    s.push(curr);
}

void topSort(vector<Edge> graph[]) {
    int V = 6; // Correct number of vertices
    bool vis[V] = {false};
    stack<int> s;
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            topSortUtil(graph, i, vis, s);
        }
    }

    while(!s.empty())  {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    int V = 6; // Correct number of vertices
    vector<Edge> graph[V];
    createGraph(graph);
    topSort(graph);
    return 0;
}
