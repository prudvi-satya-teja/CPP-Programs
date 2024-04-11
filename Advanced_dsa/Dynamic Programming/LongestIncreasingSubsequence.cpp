#include<bits/stdc++.h>
using namespace std;

// Tabulation - O(n * m)

int lcs(int arr1[], int  arr2[], int n, int m) {
    // int n  = sizeof(arr1)  / sizeof(arr1[0]);
    // int m = sizeof(arr2) / sizeof(arr2[0]);

    //intialize
    int dp[n+1][m+1];
    for(int i=0; i<n+1; i++) {
        dp[i][0] = 0;
    }
    for(int j=0; j<m+1; j++) {
         dp[0][j] = 0;
    }

    // bottom up
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(arr1[i-1] == arr2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                int ans1 = dp[i-1][j];
                int ans2 = dp[i][j-1];
                dp[i][j] = max(ans1, ans2);
            }
        }
    }
    return dp[n][m];
    
}
int lis(int arr[], int n) {
    //  int n  = sizeof(arr) / sizeof(arr[0]);

    set<int>  set;
    for(int i=0; i<n; i++) {
        set.insert(arr[i]);
    }

    int  arr2[n];

    int i = 0;
    for(int num: set) {
        arr2[i] = num;
        i++;
    }

    sort(arr2, arr2+n); // ascending
    return lcs(arr, arr2, n, n);
}

int main() {

    int arr[] = {50, 3, 10, 7,40, 80};

    // Tabulation  LIS
    cout<<lis(arr, 6)<<endl;

    return 0;
}