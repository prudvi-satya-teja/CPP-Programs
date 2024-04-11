#include<bits/stdc++.h>
using namespace std;

// Recursion 
int mcm(int arr[], int i , int j) { // i -> starting point   , j -> ending point 
    if(i == j) {
        return 0; // return matrix case;
    }

    int ans = INT_MAX;
    for(int k=i; k<=j-1; k++) {
        int cost1 = mcm(arr, i, k);// Ai....Ak => arr[i-1] x arr[k]
        int cost2 = mcm(arr, k+1, j);// Ak+1....Aj => arr[k] x arr[j]
        int cost3 = arr[i-1] * arr[k] * arr[j];
        int finalCost = cost1 + cost2 + cost3;
        ans = min(ans, finalCost);
    } 
    
    return ans; // mincost
}


// Recursion + Memoization - O(n ^ 2)
int mcmMem(int arr[], int i , int j, int **dp) {
    if(i == j) {
        return 0; // return matrix case;
    }

    if(dp[i][j] != -1)  {
        return dp[i][j];
    }

    int ans = INT_MAX;
    for(int k=i; k<=j-1; k++) {
        int cost1 = mcmMem(arr, i, k, dp);// Ai....Ak => arr[i-1] x arr[k]
        int cost2 = mcmMem(arr, k+1, j, dp);// Ak+1....Aj => arr[k] x arr[j]
        int cost3 = arr[i-1] * arr[k] * arr[j];
        int finalCost = cost1 + cost2 + cost3;
        ans = min(ans, finalCost);
    } 
    
    return dp[i][j] = ans; // mincost
}

// Tabulation - O(n ^ 2)
int mcmTab(int arr[], int n) {

    int dp[n][n];

     // initialization
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dp[i][j] = 0;
        }
    }
    // // initialization
    // for(int i=0; i<n; i++) {
    //     dp[i][i] = 0;
    // }

    // bottom-up
    for(int len=2; len<=n-1; len++) {
        for(int i=1; i<=n-len; i++) {
            int j = i+len-1; //col
            dp[i][j] = INT_MAX;
            for(int k=i; k<=j-1; k++) {
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j]; // Ak+1....Aj => arr[k] x arr[j]
                int cost3 = arr[i-1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost1 + cost2 + cost3);
            }
        }
        
    } 

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    return dp[1][n-1]; // mincost
}


int main() {

    int arr[] = {1, 2, 3, 4, 3};   // n = 5
    int n = 5;

    // // Recursion
    // // cout<< mcm(arr,1, n-1);

    // // Memoization
    // // int dp[n][n];
    // int **dp = new int*[n];
    // for(int i=0; i<n; i++) {
    //     dp[i] = new int[n];
    //     for(int j=0; j<n; j++) {
    //         dp[i][j] = -1;
    //     }
    // }

    // cout<<mcmMem(arr, 1, n-1, dp);

    //  // Free memory
    // for(int i = 0; i < n; i++) {
    //     delete[] dp[i];
    // }
    // delete[] dp;

    // Tabulation
    cout<<mcmTab(arr, n);

    return 0;
}