#include<iostream> 
using namespace std;

static int tree[8];

void init(int n) {
    for(int i=0; i<4 *n; i++) {
        tree[i] = 0; // intialize all elements of tree to 0
    }
}


int   buildST(int arr[], int i, int start, int end) {
    if(start == end) {
        tree[i] = arr[start];
        return arr[start];
    }

    int mid = (start + end) /2 ;
    buildST(arr, 2*i+1, start, mid); // left subtree = 2*i+1
    buildST(arr, 2*i+2, mid +1 , end); // right subtreee = 2* i+2
    tree[i] = tree[2*i+1] + tree[2*i+2];
    return tree[i];
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;

    init(n);
    buildST(arr, 0, 0, n-1);

    for(int i=0; i<32; i++) {
        cout<<tree[i]<<" ";
    }
    return 0;
}