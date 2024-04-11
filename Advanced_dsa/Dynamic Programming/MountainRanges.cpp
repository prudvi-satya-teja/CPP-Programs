#include<bits/stdc++.h>
using namespace std;

// Tabulation - O(n^2)
int mountainRanges(int n) {
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<n+1; i++) { // Ci
        dp[i] = 0;
        // i paris -> mountain ranges => Ci 
        // Ci -> BSt (i nodes) -> dp[i]
        for(int j=0; j<i; j++) {
            // ci = cj * ci-j-1
            int inside = dp[j];
            int outside = dp[i-j-1];
            dp[i]  += inside * outside;
        }
    }

    // n pairs
    return dp[n];
}

int main() {

    int  n = 3; //14

    // Tabulation
    cout<<mountainRanges(n);
    return 0;
}