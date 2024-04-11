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

    graph[0].push_back(Edge(0, 1, 2));
    graph[0].push_back(Edge(0, 2, 4));

    graph[1].push_back(Edge(1, 2, -4)); 

    graph[2].push_back(Edge(2, 3, 2));
    
    
    graph[3].push_back(Edge(3, 4, 4)); 
  
    graph[4].push_back(Edge(4, 1, -1)); 

}

void createGraph2(vector<Edge>& graph) {

    graph.push_back(Edge(0, 1, 2));
    graph.push_back(Edge(0, 2, 4));
    graph.push_back(Edge(1, 2, -4)); 
    graph.push_back(Edge(2, 3, 2));
    graph.push_back(Edge(3, 4, 4)); 
    graph.push_back(Edge(4, 1, -1)); 

}
void bellmanFord(vector<Edge> graph, int src, int V) {
    int dist[5];
    for(int i=0; i<5; i++) {
        if(i != src) {
            dist[i] = INT_MAX;
        }
    }
    dist[src] = 0;

    //alog

    for(int i=0; i<V-1; i++) {
        //edges -O(E)
        for(int j=0; j<5; j++) {
                Edge e = graph[j];
                // u , v, w
                int u = e.src;
                int v = e.dest;
                int wt = e.wt;

                //relaxation step
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

    //print
    for(int i=0; i<5; i++) {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}


int main() {
 
    int V = 5;
    // vector<Edge> graph[V];
    vector<Edge> graph;


    createGraph2(graph);

    int src = 0;
    
    bellmanFord(graph,src, V);

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

// //Edge[]
// void createGraph(vector<Edge> graph[]) {

//     graph[0].push_back(Edge(0, 1, 2));
//     graph[0].push_back(Edge(0, 2, 4));

//     graph[1].push_back(Edge(1, 2, -4)); 

//     graph[2].push_back(Edge(2, 3, 2));
    
    
//     graph[3].push_back(Edge(3, 4, 4)); 
  
//     graph[4].push_back(Edge(4, 1, -1)); 

// }

// void bellmanFord(vector<Edge> graph[], int src) {
//     int dist[5];
//     for(int i=0; i<5; i++) {
//         if(i != src) {
//             dist[i] = INT_MAX;
//         }
//     }
//     dist[src] = 0;

//     //alog
//     int V= 5;

//     for(int i=0; i<V-1; i++) {
//         //edges -O(E)
//         for(int j=0; j<5; j++) {
//             for(int k=0; k<graph[j].size(); k++) {
//                 Edge e = graph[j][k];
//                 // u , v, w
//                 int u = e.src;
//                 int v = e.dest;
//                 int wt = e.wt;

//                 //relaxation step
//                 if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
//                     dist[v] = dist[u] + wt;
//                 }
//             }
//         }
//     }

//     //print
//     for(int i=0; i<5; i++) {
//         cout<<dist[i]<<" ";
//     }
//     cout<<endl;
// }


// int main() {
 
//     int V = 5;
//     vector<Edge> graph[V];


//     createGraph(graph);

//     int src = 0;
    
//     bellmanFord(graph,src);

//     return 0;
// }