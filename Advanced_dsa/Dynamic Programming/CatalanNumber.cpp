#include<bits/stdc++.h>
using namespace std;

// Recursion
int catalanRec(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }

    int ans  = 0; // Cn
    for(int i=0; i<=n-1; i++) {
        ans += catalanRec(i) * catalanRec(n-i-1);
    }

    return ans;
}

// Memoization
int catalanMem(int n, int dp[]) {
    if(n == 0 || n == 1) {
        return 1;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int ans = 0;
    for(int i=0; i<=n-1; i++) {
        ans += catalanMem(i, dp) * catalanMem(n-i-1, dp); // Ci = Cj * Ci-j-1
        dp[n] = ans;
    }

    return dp[n];
}

// Tabulation - O(n*m)
int catalanTab(int n) {
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++) { // Ci
        dp[i] = 0;
        for(int j=0; j<i; j++) {
            dp[i]  += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

int main() {

    int  n = 5;

    // // // Recursion
    // cout<<catalanRec(n)<<endl;

    // // Memoization
    // int dp[n+1];
    // for(int i = 0; i<n+1; i++) {
    //     dp[i] = -1;
    // }
    // cout<<catalanMem(n, dp)<<endl;

    // Tabulation
    cout<<catalanTab(n);


    return 0;
}