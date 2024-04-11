#include<bits/stdc++.h>
using namespace std;


// Tabulattion (0-1 knapsack)  // O(n * W)
int minPartition(int arr[], int n) {

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }

    int W = sum / 2;

    //intialization
    int dp[n+1][W+1];
    for(int i=0; i<n+1; i++) { // 0th col
        dp[i][0]  = 0;
    }
    for(int j=0; j<W+1; j++) {// 0th row
        dp[0][j] = 0;        
    }

    // bottom up 
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            if(arr[i-1] <= j) { // valid
                dp[i][j] = max(arr[i-1] + dp[i-1][j-arr[i-1]], dp[i-1][j]);
            }
            else { // invalid
                dp[i][j] =  dp[i-1][j];
            }
        }
    }
    int sum1 =  dp[n][W];
    int sum2 = sum - sum1;
    return abs(sum1 - sum2);
}
int main() { 

    int nums[4] = {1, 6, 11, 5};
    int n = 4;

     // Tabulation
    cout << "Tabulation: " << minPartition(nums, n) << endl;
    return 0;
}
