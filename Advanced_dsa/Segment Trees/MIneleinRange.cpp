#include<iostream> 
using namespace std;

static int tree[9];

void init(int n) {
    for(int i=0; i<4 *n; i++) {
        tree[i] = 0; // intialize all elements of tree to 0
    }
}


int   buildST(int arr[], int i, int start, int end) { // O(N)
    if(start == end) {
        tree[i] = arr[start];
        return arr[start];
    }

    int mid = (start + end) /2 ;
    buildST(arr, 2*i+1, start, mid); // left subtree = 2*i+1
    buildST(arr, 2*i+2, mid +1 , end); // right subtreee = 2* i+2
    tree[i] = min(tree[2*i+1] , tree[2*i+2]);
    return tree[i];

}


int getMinUtil(int i, int si, int sj, int qi, int qj) {// O(log n)
    if(si > qj || sj < qi) {   // non - overlapping
        return INT_FAST8_MAX;
    } 
    else if(si >= qi && sj <= qj) { // complete overlap
        return tree[i];
    }
    else {  //partial overlap
        int mid = (si + sj) / 2;
        int left = getMinUtil(2*i+1, si, mid, qi, qj);
        int right = getMinUtil(2*i+2, mid+1, sj, qi, qj);
        return min(left, right);
    }
} 

int getMin(int arr[], int qi, int qj, int n) {
    return getMinUtil(0, 0, n-1, qi, qj);

} 

// Update
void updateUtil(int i, int si, int sj, int idx, int newVal) {  // O(log n)
    if(si > sj || idx < si || idx > sj) {
        return;
    }

    if(si == sj) { // Leaf node
        tree[i] = newVal;
        return;
    }

    int mid = (si + sj) / 2;
    updateUtil(2 * i + 1, si, mid, idx, newVal); // Left child
    updateUtil(2 * i + 2, mid + 1, sj, idx, newVal); // Right child
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]); // Update parent node
}



void update(int arr[], int idx, int newVal) {// O(log n)
    int n = 9;
     updateUtil(0, 0, n-1, idx, newVal);  // segment tree updation
    arr[idx] = newVal;

   
}
int main() {
    int arr[] = {6, 8, -1, 2, 17, 1, 3, 2, 4};
    int n = 9;

    init(n);
    buildST(arr, 0, 0, n-1);

    // for(int i=0; i<32; i++) {
    //     cout<<tree[i]<<" ";
    // }

    cout<< getMin(arr, 2, 5, 9) <<endl;//17

    update(arr, 2, 11);
     cout<< getMin(arr, 2, 5, 9);//20
    return 0;
}
// For min replace all max with min 
//and in line 29 return int max in place int_min
//getmax with getmin and getmaxutil with getminUtil