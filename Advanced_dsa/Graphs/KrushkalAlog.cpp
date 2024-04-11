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

    bool operator<(const Edge& e2) const {
        return this->wt < e2.wt; 
    }
 };

 void createGraph(vector<Edge>& edges) {
    //edges
    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 15));
    edges.push_back(Edge(0, 3, 30));
    edges.push_back(Edge(1, 3, 40));
    edges.push_back(Edge(2, 3, 50));

 }

static int n = 4;  // vertices
vector<int> par(n);
vector<int> rank_(n);

void init() {
        for(int i=0; i<n; i++) {
            par[i] = i;
            rank_[i]= 0;
        }
    } 


    // path compression
    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

     void unionop(int a, int b) {  
        int parA = find(a);
        int parB = find(b);

        if(rank_[parA] == rank_[parB]) {
            par[parB] = parA;
            rank_[parA]++;
        }
        else if(rank_[parA] < rank_[parB]) {
            par[parA] = parB;
        }
        else {
            par[parB] = parA;
        }

    }

void kruskalsMST(vector<Edge> edges, int V) {// O(V + ElogE)
    init();
    sort(edges.begin(),edges.end());  // o(Elog E)
    int mstCost = 0;
    int count = 0;

    for(int i=0; count<V-1 && i<edges.size(); i++) {  // O(V)
        Edge e = edges[i];
        //(src, dest, wt)

        int parA = find(e.src); // src = a
        int parB  = find(e.dest); // dest = b
        if(parA  != parB) {
            unionop(e.src, e.dest);
            mstCost += e.wt;
            count++;
        }
    }
    cout<<mstCost;
}

int main() {
    int V=4;
    vector<Edge>edges ;
    createGraph(edges);
    kruskalsMST(edges, V);

    return 0;
}