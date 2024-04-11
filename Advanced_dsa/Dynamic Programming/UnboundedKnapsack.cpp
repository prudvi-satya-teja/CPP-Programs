#include<bits/stdc++.h>
using namespace std;

// Tabulattion (Unbounded knapsack)  // O(n * W)
int Unboundedknapsack(int val[], int wt[], int W) {
    int n = 6;
    int dp[6][W+1];
    for(int i=0; i<6; i++) { // 0th col
        dp[i][0]  = 0;
    }
    for(int j=0; j<W+1; j++) {// 0th row
        dp[0][j] = 0;        
    }

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            if(wt[i-1] <= j) { // valid
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            }
            else { // invalid
                 dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<8; j++) {
            cout<<dp[i][j]<< " ";
        }
        cout<<endl;
    }
    return dp[n][W];
}

int main() { 

    int val[5] = {15, 14, 10, 45, 30};
    int wt[5] = {2, 5, 1, 3, 4};
    int W = 7;

    // Tabulation
    cout << "Tabulation: " << Unboundedknapsack(val, wt, W) << endl;
    return 0;
}
