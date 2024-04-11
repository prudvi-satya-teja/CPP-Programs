#include<bits/stdc++.h>
using namespace std;

static int n = 7;
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
        if(x == par[x]) {
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

int main() {

    init();
    cout<<find(3);
    unionop(1,3);
    cout<<find(3);
    unionop(2,4);
    unionop(3,6);
    unionop(1,4);

    cout<<find(3);
    cout<<find(4);
    unionop(1,5);

    return 0;
}