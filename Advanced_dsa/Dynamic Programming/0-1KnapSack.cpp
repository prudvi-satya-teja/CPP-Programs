#include<bits/stdc++.h>
using namespace std;

//  Recursion 0 - 1 Knapsack
int knapsack(int val[], int wt[], int W, int n) { // O(2 ^ n)
    if(W == 0 || n == 0) {
        return 0;
    }

    if(wt[n-1] <= W) {  // Valid
        //include
        int ans1 = val[n-1] + knapsack(val, wt, W-wt[n-1],  n-1);
        //exclude
        int ans2 = knapsack(val, wt, W, n-1);
        return max(ans1, ans2);
    } else { // not valid
        return knapsack(val, wt, W, n-1);
    }
}

// Memoization 0-1 Knapsack  // O(n * W)
int knapsackMem(int val[], int wt[], int W, int n, vector<vector<int>>& dp) {
    if(W == 0 || n == 0) {
        return 0;
    }

    if(dp[n][W] != -1) {
        return dp[n][W];  
    }

    if(wt[n-1] <= W) {  // Valid
        //include
        int ans1 = val[n-1] + knapsackMem(val, wt, W-wt[n-1],  n-1, dp);
        //exclude
        int ans2 = knapsackMem(val, wt, W, n-1, dp);
        dp[n][W] = max(ans1, ans2);
    } else { // not valid
        dp[n][W] =  knapsackMem(val, wt, W, n-1, dp);
    }
    return dp[n][W]; // Return the calculated value
}


// Tabulattion (0-1 knapsack)  // O(n * W)
int knapsackTab(int val[], int wt[], int W) {
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
            int v = val[i-1];  // ith item val
            int w = wt[i-1];   // ith item wt
            if(w <= j) { // valid
                int incProfit = v + dp[i-1][j-w];
                int excProfit = dp[i-1][j];
                dp[i][j] = max(incProfit, excProfit);
            }
            else { // invalid
                int excProfit = dp[i-1][j];
                dp[i][j] = excProfit;

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

    // Recursion
    cout << "Recursion: " << knapsack(val, wt, W, 5) << endl;

    // Memoization
    vector<vector<int>> dp(6, vector<int>(W + 1, -1));

    cout << "Memoization: " << knapsackMem(val, wt, W, 5, dp) << endl;

     // Tabulation
    cout << "Tabulation: " << knapsackTab(val, wt, W) << endl;
    return 0;
}


// //  Memoization 0 - 1 Knapsack
// int knapsackMem(int val[], int wt[], int W, int n, int dp[6][8]) {
//     if(W == 0 || n == 0) {
//         return 0;
//     }

//     if(dp[n][W] != -1) {
//         return dp[n][W];  
//     }

//     if(wt[n-1] <= W) {  // Valid
//         //include
//         int ans1 = val[n-1] + knapsackMem(val, wt, W-wt[n-1],  n-1, dp);
//         //exclude
//         int ans2 = knapsackMem(val, wt, W, n-1, dp);
//         dp[n][W] = max(ans1, ans2);
//     } else { // not valid
//         dp[n][W] =  knapsackMem(val, wt, W, n-1, dp);
//         return dp[n][W];
//     }
// }

// int main() { 

//     int val[5] = {15, 14, 10, 45, 30};
//     int wt[5] = {2, 5, 1, 3, 4};
//     int W = 7;
//     // Recursion
//     cout<<knapsack(val, wt, W, 5);

//     // Memoization
//     int dp[6][W+1];
//     for(int i=0; i<6; i++) {
//         for(int j=0; j<6; j++) {
//             dp[i][j] = -1;
//         }
//     }

//     cout<<knapsackMem(val, wt, W, 5, dp);
//     return 0;
// }
