#include <iostream>
#include <queue>
#include <climits> // For INT_MAX

using namespace std;

class Edge {
public:
    int src, dest, wt;
    Edge(int s, int d, int w) : src(s), dest(d), wt(w) {}
};

class Pair {
public:
    int n, path;
    Pair(int n, int path) : n(n), path(path) {}
};

// Comparison functor for min heap in priority_queue
struct Compare {
    bool operator()(const Pair& a, const Pair& b) {
        return a.path > b.path; // Greater than for min heap
    }
};

void createGraph(vector<Edge> graph[], int V) {
    graph[0].push_back(Edge(0, 1, 2));
    graph[0].push_back(Edge(0, 2, 4));

    graph[1].push_back(Edge(1, 3, 7));
    graph[1].push_back(Edge(1, 2, 1));

    graph[2].push_back(Edge(2, 4, 3));

    graph[3].push_back(Edge(3, 5, 1));

    graph[4].push_back(Edge(4, 3, 2));
    graph[4].push_back(Edge(4, 5, 5));
}

void dijkstra(vector<Edge> graph[], int V, int src) {
    int dist[V]; // Initialize distances array
    fill(dist, dist + V, INT_MAX); // Initialize distances to infinity
    dist[src] = 0; // Distance to source is 0

    bool vis[V] = {false}; // Visited array

    priority_queue<Pair, vector<Pair>, Compare> pq;
    pq.push(Pair(src, 0));

    while (!pq.empty()) {
        Pair curr = pq.top();
        pq.pop();

        if (vis[curr.n]) continue;
        vis[curr.n] = true;

        for (Edge e : graph[curr.n]) {
            int v = e.dest;
            int wt = e.wt;

            if (dist[curr.n] + wt < dist[v]) {
                dist[v] = dist[curr.n] + wt;
                pq.push(Pair(v, dist[v]));
            }
        }
    }

    // print all source to vertices shortest distances
    cout << "Vertex Distance from Source:\n";
    for (int i = 0; i < V; i++) {
        cout << i << " " << dist[i] << endl;
    }
}

int main() {
    const int V = 6;
    vector<Edge> graph[V];
    createGraph(graph, V);

    int src = 0;
    dijkstra(graph, V, src);

    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// class Edge {
//     public: 

//     int src;
//     int dest;
//     int wt;
    
//     Edge(int s, int d, int w) {
//         this->src = s;
//         this->dest = d;
//         this->wt = w;
//     }
// };

//  class  Pair implements comparable<Pair> {
//     public:
//         int n;
//         int path;

//         Pair(int n,int path) {
//             this->n = n ;
//             this->path = path;
//         }

//         public int compareTo(pair p2) {
//             return this.path - p2.path; // path based sorting
//         }
// };

// void createGraph(vector<Edge> graph[]) {

//     graph[0].push_back(Edge(0, 1, 2));
//     graph[0].push_back(Edge(0, 2, 4));

//     graph[1].push_back(Edge(1, 3, 7)); 
//     graph[1].push_back(Edge(1, 2, 1));
    
//     graph[2].push_back(Edge(2, 4, 3));
    
//     graph[3].push_back(Edge(3, 5, 1)); 
  
//     graph[4].push_back(Edge(4, 3, 2)); 
//     graph[4].push_back(Edge(4, 5, 5));

// }


// void dijkstra(vector<Edge> graph[], int src) {

//     int dist[6];  // dist[i] ->src to 1
//     for(int i=0; i<graph->size(); i++) {
//         if(i != src) {
//             dist[i] = 1e9 + 7;
//         }
//     }
//     bool vis[6] = {false};
//     priority_queue<Pair> pq;

//     pq.push(Pair(src, 0));

//     while(!pq.empty()) {
//         Pair curr = pq.front();
//         pq.pop();
//         if(!vis[curr.n]) {
//             vis[curr.n] = true;
//             // neighbours
//             for(int i=0; i<graph[curr.n].size(); i++) {
//                 Edge e = graph[curr.n][i];
//                 int u = e.src;
//                 int v = e.dest;
//                 int wt = e.wt;

//                 if(dist[u] + wt < dist[v] ) { // update distance of src to v;
//                     dist[v] = dist[u] + wt;
//                     pq.push(new Pair (v, dist[v]));
//                 }
//             }
//         }
//     }

//     // print all source to vertieces shortest dist
//     for(int i=0; i<dist.length; i++) {
//         cout<< dist[i] << " " ;
//     }

//     cout<<endl;
// }
// int main() {
 
//     int V = 6;
//     vector<Edge> graph[V];
//     createGraph(graph);

//     int src = 0;
    
//     dijkstra(graph,src);

    
//     return 0;
// }