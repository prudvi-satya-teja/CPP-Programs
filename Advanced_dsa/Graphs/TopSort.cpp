#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src, dest;
    Edge(int s, int d) : src(s), dest(d) {}
};

void createGraph(vector<Edge> graph[]) {
    graph[2].push_back(Edge(2, 3));
    graph[3].push_back(Edge(3, 1));
    graph[4].push_back(Edge(4, 0));
    graph[4].push_back(Edge(4, 1));
    graph[5].push_back(Edge(5, 0));
    graph[5].push_back(Edge(5, 2));
}

void calIndeg(vector<Edge> graph[], int indeg[], int V) {
    for(int i = 0; i < V; i++) {
        for(Edge e : graph[i]) {
            indeg[e.dest]++;
        }
    }
}

void topSort(vector<Edge> graph[], int V) {
    int *indeg = new int[V]{0};
    calIndeg(graph, indeg, V);
    queue<int> q;

    for(int i = 0; i < V; i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for(Edge e : graph[curr]) {
            indeg[e.dest]--;
            if(indeg[e.dest] == 0) {
                q.push(e.dest);
            }
        }
    }
    delete[] indeg;
}

int main() {
    int V = 6; // Number of vertices
    vector<Edge> graph[V];
    createGraph(graph);
    topSort(graph, V);
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// class Edge {
// public:
//     int src;
//     int dest;

//     Edge(int s, int d) {
//         this->src = s;
//         this->dest = d;
//     }
// };

// void createGraph(vector<Edge> graph[]) {

//     graph[2].push_back(Edge(2, 3));

//     graph[3].push_back(Edge(3, 1));

//     graph[4].push_back(Edge(4, 0));
//     graph[4].push_back(Edge(4, 1));

//     graph[5].push_back(Edge(5, 0));
//     graph[5].push_back(Edge(5, 2));
// }

// void calIndeg(vector<Edge> graph[], int indeg[]) {
//     // Initialize in-degrees to 0
//     for (int i = 0; i < V; i++) {
//         indeg[i] = 0;
//     }

// // Calculate in-degrees
//     for(int i=0; i<5; i++) {
//         int v = i;
//         for(int j=0; j<graph[v].size(); j++) {
//             Edge e = graph[v][j];
//             indeg[e.dest]++;
//         }
//     }

// }

// void topSort(vector<Edge> graph[]) {
//     int indeg[5] = {0};
//     calIndeg(graph,indeg);
//     queue<int> q ;

//     for(int i=0; i<5; i++) {
//         if(indeg[i] == 0) {
//             q.push(i);
//         }
//     }

//     //bfs
//     while(!q.empty())  {
//         int curr = q.front();
//         q.pop();
//         cout<<curr<<" ";  // topological sort print

//         for(int i=0; i<graph[curr].size(); i++) {
//             Edge e = graph[curr][i];
//             indeg[e.dest]--;
//             if(indeg[e.dest] == 0) {
//                 q.push(e.dest);
//             }
//         }
//     }
// }

// int main() {
//     int V = 6; // Correct number of vertices
//     vector<Edge> graph[V];
//     createGraph(graph);
//     topSort(graph);
//     return 0;
// }
