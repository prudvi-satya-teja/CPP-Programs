#include<bits/stdc++.h>
using namespace std;

//  Tabulation (CoinChage)  // O(n * sum)
int coinChange(int coins[], int sum) {
    int n = 3;
    int dp[n][sum+1];

    // initialize sum = 0
    // i -> coins, j -> sum / change
    for(int i=0; i<n+1; i++) { // 0th col
        dp[i][0]  = 1;
    }

    for(int j=1; j<sum+1; j++) {// 0th row
        dp[0][j] = 0;        
    }

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<sum+1; j++) {
            if(coins[i-1] <= j) { // valid
                dp[i][j] = dp[i][j-coins[i-1]] +  dp[i-1][j];
            }
            else { // invalid
                 dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i=0; i<n+1; i++) {
        for(int j=0; j<sum+1; j++) {
            cout<<dp[i][j]<< " ";
        }
        cout<<endl;
    }
    return dp[n][sum];
}

int main() { 

    int coins[] = {1,2,3};
    int sum = 4; // ans = 4
    

    // Tabulation
    cout << "Tabulation: " << coinChange(coins, sum) << endl;
    return 0;
}
