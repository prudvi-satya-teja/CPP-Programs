 #include<bits/stdc++.h>
 using namespace std;

 class Edge {
    public:
    int dest;
    int cost;

    Edge(int d, int c) {
        this->dest = d;
        this->cost = c;
    }

    bool operator<(const Edge& e2) const {
        return this->cost > e2.cost; // Min-heap: changing the comparison
    }
 };

 int connectCities(int cities[][5]) {
    priority_queue<Edge> pq;
    bool vis[5] = {false};

    pq.push(Edge(0,0));
    int finalCost  = 0;

    while(!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();
        if(!vis[curr.dest]) {
            vis[curr.dest] = true;
            finalCost += curr.cost;

            for(int i=0; i<5; i++) {
                if(cities[curr.dest][i] != 0) {
                    pq.push(Edge(i, cities[curr.dest][i]));
                }
            }
        }
    }
    return finalCost;
 }
 
 int main() {
    int cities[5][5] = {{0, 1, 2, 3, 4},
                        {1, 0, 5, 0, 7},
                        {2, 5, 0, 6, 0},
                        {3, 0, 6, 0, 0},
                        {4, 7, 0, 0, 0}};
    
    cout<<connectCities(cities)<<endl;
 
    return 0;
 }