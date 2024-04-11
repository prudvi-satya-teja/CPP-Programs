#include<bits/stdc++.h>
using namespace std;

int minJumps(int nums[], int n) {
    int dp[n];

    for(int i=0; i<n; i++) {
        dp[i] = -1;
    }

    dp[n-1] = 0;

    for(int i=n-2; i>=0; i--) {
        int steps = nums[i];
        int ans = INT_MAX;
        for(int j=i+1; j<=i+steps && j<n; j++) {
            if(dp[j] != -1) {
                ans = min(ans, dp[j]+1);
            }
        }
        if(ans != INT_MAX) {
            dp[i] = ans;
        }
    }

    // dp[i] -> 0 to n-1
    return dp[0];
}

int main() {

    int nums[] = {2, 3, 1, 1, 4}; // min jumps = 2
    cout<<minJumps(nums, 5);

    return 0;
}