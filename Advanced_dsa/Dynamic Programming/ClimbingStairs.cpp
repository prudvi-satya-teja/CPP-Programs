#include<bits/stdc++.h>
using namespace std;

// Recursion
int countWays(int n, int ways[]) {
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        return 1;
    }
   return countWays(n-1, ways) + countWays(n-2, ways);
}


int main() {

    int steps = 5;  //  n =2 0
    int ways[steps+1] = {0};
    cout<<countWays(steps, ways);

    return 0;
}