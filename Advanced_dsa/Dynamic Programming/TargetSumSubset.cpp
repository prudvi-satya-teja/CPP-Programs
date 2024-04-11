
#include<bits/stdc++.h>
using namespace std;

// Tabulation (Target sum Subset)  //O(n * Sum)
bool targetSumSubset(int arr[], int sum) {
    int n = 5;
    bool dp[n+1][sum+1];

    // i = items & j = target sum
    for(int i=0; i<n+1; i++) {
        dp[i][0]  =true;
    }
    for(int i=0; i<n+1; i++) {
        for(int j=1; j<sum+1; j++) {
            dp[i][j] = false;
        }
    }

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<sum+1; j++) {
            int v = arr[i-1];
            // include
            if(v <= j && dp[i-1][j-v] == true) {
                dp[i][j] = true;
            } 
            // exclude
            else if(dp[i-1][j] == true) {
                dp[i][j] = true;
            }
        }
    }

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][sum];

}

int main() {
    int arr[] = {4, 2, 7, 1, 3};
    int sum  = 10;
    cout<<targetSumSubset(arr, sum);

    return 0;
}