//
//#include<bits/stdc++.h>
//using namespace std;
//
//class Node {
//    
//    public:
//    int data;
//    Node* left;
//    Node* right;
//
//    Node(int data) {
//        this->data = data;
//        this->left = NULL;
//        this->right = NULL;
//    }
//};
//
//Node* lowComAnc(Node* root, int n1, int n2) {
//    if(root == NULL || root->data == n1 || root->data == n2) {
//        return root;
//    
//
//    if(root->left == NULL) {
//        return root->right;
//    }
//    if(root->right == NULL) {
//        return root->left;
//    }
//    
//}
//}
//
//
//int main() {
//
//    Node* root = new Node(1);
//
//    root->left = new Node(2);
//    root->right = new Node(3);
//
//    root->left->left = new Node(4);
//    root->left->right = new Node(5);
//
//    root->right->right = new Node(6);
//    vector<int> v;
//
//    int n1, n2;
//    Node* leftroot = lowComAnc(root, n1,n2);
//    Node* rightroot = lowComAnc(root, n2,n2);
//
//    for(auto i: v) {
//        cout<<i<<" ";
//    }
//    cout<< v.size();
//    return 0;
//} 
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
bool topSortUtil(vector<Edge> graph[], int curr,  bool vis[], stack<int> s) {
    vis[curr] = true;

    for(int i=0; i<graph[curr].size(); i++) {
        Edge e = graph[curr][i];
        if(!vis[e.dest]) {
            topSortUtil(graph,e.dest, vis, s);
        }
    }
    s.push(curr);
}

void topSort(vector<Edge> graph[]) {
    bool vis[5] = {false};
    stack<int>  s;
    for(int i=0; i<graph->size(); i++) {
        if(!vis[i]) {
            topSortUtil(graph, i, vis , s);  // modified dfs
        }
    }

    while(!s.empty())  {
        cout<< s.top()<<" ";
        s.pop();
    }
}


int main() {

    int V = 5;
    vector<Edge> graph[V];
    createGraph(graph);
    
    topSort(graph);

    
    return 0;
}
