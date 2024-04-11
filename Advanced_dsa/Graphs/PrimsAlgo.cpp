#include<bits/stdc++.h>
using namespace std;

class Edge {
    public: 

    int src;
    int dest;
    int wt;
    
    Edge(int s, int d, int w) {
        this->src = s;
        this->dest = d;
        this->wt = w;
    }
};

//Edge[]
void createGraph(vector<Edge> graph[]) {

    graph[0].push_back(Edge(0, 1, 10));
    graph[0].push_back(Edge(0, 2, 15));
    graph[0].push_back(Edge(0, 3, 30));

    graph[1].push_back(Edge(1, 0, 10)); 
    graph[1].push_back(Edge(1, 3, 40));

    graph[2].push_back(Edge(2, 0, 15));
    graph[2].push_back(Edge(2, 3, 50));
    
    
    graph[3].push_back(Edge(3, 1, 40)); 
    graph[3].push_back(Edge(3, 2, 50)); 

}

class Pair {
    public:
    int v;
    int cost;

    Pair(int v, int c) {
        this->v = v;
        this->cost = c;
    }
};

struct Compare {
    bool operator()(const Pair& a, const Pair& b) {
        return a.cost > b.cost; // Greater than for min heap
    }
};


void prims(vector<Edge> graph[]) {
    int V=4;
    bool vis[V] = {false};

     priority_queue<Pair, vector<Pair>, Compare> pq;
    pq.push(Pair(0,0));
    int finalCost = 0; // MST Cost / total min weight

    while(!pq.empty()) {
        Pair curr = pq.top();
        pq.pop();

        if(!vis[curr.v]) {
            vis[curr.v] = true;
            finalCost += curr.cost;

            for(int i=0; i<graph[curr.v].size(); i++) {
                Edge e = graph[curr.v][i];
                pq.push(Pair(e.dest,e.wt));
            }
        }

    }

    cout<< "final cost " << finalCost <<endl;
}
int main() {
 
    int V = 4;
    vector<Edge> graph[V];
    createGraph(graph);
    prims(graph);

    return 0;
}