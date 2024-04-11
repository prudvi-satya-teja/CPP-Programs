#include<iostream> 
using namespace std;
int tree[32];

void init(int n) {
    for(int i=0; i<4 *n; i++) {
        tree[i] = 0; // intialize all elements of tree to 0
    }
}

int   buildST(int arr[], int i, int start, int end) {// O(n)
    if(start == end) {
        tree[i] = arr[start];
        return arr[start];
    }

    int mid = (start + end) /2 ;
    int leftSum = buildST(arr, 2*i+1, start, mid); // left subtree = 2*i+1
    int rightSum= buildST(arr, 2*i+2, mid +1 , end); // right subtreee = 2* i+2
    tree[i] = leftSum + rightSum;
    return tree[i];
}


int getSumUtil(int i, int si, int sj, int qi, int qj) {
    if(qj <= si || qi >= sj) {   // non - overlapping
        return 0;
    } 
    else if(si >= qi && sj <= qj) { // complete overlap
        return tree[i];
    }
    else {  //partial overlap
        int mid = (si + sj) / 2;
        int left = getSumUtil(2*i+1, si, mid, qi, qj);
        int right = getSumUtil(2*i+2, mid+1, sj, qi, qj);
        return left + right;
    }
} 

int getSum(int arr[], int qi, int qj, int n) {
    return getSumUtil(0, 0, n-1, qi, qj);

} 

// Update
void updateUtil(int i, int si, int sj, int idx, int diff) {  // O(log n)
    if(idx < si || idx  > sj  ) {
        return;
    }

    tree[i] += diff;
    if(si != sj) {  // non-leaf
        int mid = (si + sj) / 2;
        updateUtil(2 * i + 1, si, mid, idx, diff); //left
        updateUtil(2 * i + 2, mid + 1, sj, idx, diff); // right
    }
}


void update(int arr[], int idx, int newVal) {
    int n = 8;
    int diff = newVal - arr[idx];
    arr[idx] = newVal;

    updateUtil(0, 0, n-1 , idx, diff);  // segment tree updation
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;

    init(n);
    buildST(arr, 0, 0, n-1);

    for(int i=0; i<32; i++) {
        cout<<tree[i]<<" ";
    }

    cout<< getSum(arr, 1, 4, n) << endl;// 18
    update(arr, 2,2);
    for(int i=0; i<32; i++) {
        cout<<tree[i]<<" ";
    }

    cout<< getSum(arr, 1, 4, n) << endl;//17

    return 0;
}