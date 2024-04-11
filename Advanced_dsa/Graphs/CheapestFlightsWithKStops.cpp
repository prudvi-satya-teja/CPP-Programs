#include<bits/stdc++.h>
using namespace std;

class Edge {
    public: 
    int src;
    int dest;
    int wt;

    Edge(int s, int d, int wt) {
        this->src = s;
        this->dest = d;
        this->wt = wt;
    }
};

void createGraph(int flights[][3], int size, vector<Edge> graph[]) {
    for(int i = 0; i < size; i++) {
        int src = flights[i][0];
        int dest = flights[i][1];
        int wt = flights[i][2];

        Edge e = Edge(src, dest, wt);
        graph[src].push_back(e);
    }
}

class Info {
    public:
    int v;
    int cost;
    int stops;

    Info(int v, int c, int s) {
        this->v = v;
        this->cost = c;
        this->stops = s;
    }
};

int cheapestFlight(int n, int flights[][3], int src, int dest, int k)  {
    vector<Edge> graph[n];
    createGraph(flights, n, graph);

    int dist[n];

    for(int i = 0; i < n; i++) {
        if(i != src) {
            dist[i] = INT_MAX;
        }
    }

    queue<Info> q ;
    q.push(Info(src, 0 , 0));

    while(!q.empty()) {
        Info curr =  q.front();
        q.pop();

        if(curr.stops > k) {
            break;
        }

        for(int i = 0; i < graph[curr.v].size(); i++) {
            Edge e = graph[curr.v][i];
            int u = e.src;
            int v = e.dest;
            int wt = e.wt;

            if(curr.cost + wt < dist[v] && curr.stops <= k) {
                dist[v] = curr.cost + wt;
                q.push(Info(v, dist[v], curr.stops+1));
            }
        }
    }

    if(dist[dest] == INT_MAX) {
        return -1;
    } else {
        return dist[dest];
    }
}

int main() {
    int n = 4;
    int flights[5][3] = {{0,1,100}, {1,2,100}, {2,0,100}, {1,3,600}, {2,3,200}};

    int src = 0, dest = 3, k = 1;
    cout << "Cheapest flight cost: " << cheapestFlight(n, flights, src, dest, k) << endl;

    return 0;
}



