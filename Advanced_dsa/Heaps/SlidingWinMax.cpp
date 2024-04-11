#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Pair  {
    public:

    int val;
    int idx;

    Pair(int val, int idx) {
        this->val = val;
        this->idx = idx;
    }

   // Overloading less than operator for comparison
    bool operator<(const Pair& p2) const {
        // Descending order
        return this->val < p2.val;
    }
};

int main() {

    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k=3;   // window size
    int res[8-k+1] ;   // n-k+1

    priority_queue<Pair> pq ;

    //1st window
    for(int i=0; i<k ; i++) {
        pq.push(Pair(arr[i], i));
    }

    res[0] = pq.top().val;

    for(int i=k; i<8; i++) {
        while(pq.size() > 0 && pq.top().idx <= (i-k)) {
            pq.pop();
        }

        pq.push(Pair(arr[i], i));
        res[i-k+1] = pq.top().val;
    }

    //print result
    for(int i=0; i<8-k+1; i++) {
        cout<< res[i] << " " << endl;
    }


}