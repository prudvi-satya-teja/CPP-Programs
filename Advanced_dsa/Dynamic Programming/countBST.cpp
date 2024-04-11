#include<bits/stdc++.h>
using namespace std;

// Tabulation - O(n^2)
int countBSTs(int n) {
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<n+1; i++) { // Ci
        dp[i] = 0;
        // Ci -> BSt (i nodes) -> dp[i]
        for(int j=0; j<i; j++) {
            // ci = cj * ci-j-1
            int left = dp[j];
            int right = dp[i-j-1];
            dp[i]  += left * right;
        }
    }

    return dp[n];
}

int main() {

    int  n = 5;

    // Tabulation
    cout<<countBSTs(n);
    return 0;
}