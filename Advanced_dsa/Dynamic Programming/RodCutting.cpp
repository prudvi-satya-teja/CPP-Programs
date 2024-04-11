#include<bits/stdc++.h>
using namespace std;

// Tabulattion (Rod cutting)  // O(n * W)
int rodCutting(int length[], int price[], int totRod) {
    // weight = length ; val = price ; W => totRod
    int n = 9;
    int dp[n+1][totRod+1];
    for(int i=0; i<n+1; i++) { // 0th col
        dp[i][0]  = 0;
    }
    for(int j=0; j<totRod+1; j++) {// 0th row
        dp[0][j] = 0;        
    }

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<totRod+1; j++) {
            if(length[i-1] <= j) { // valid
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            }
            else { // invalid
                 dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<totRod+1; j++) {
            cout<<dp[i][j]<< " ";
        }
        cout<<endl;
    }
    return dp[n][totRod];
}

int main() { 

    int length[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int price[8] = {1, 5, 8, 9, 10, 17, 17, 20};
    int totRod = 8;



    // Tabulation
    cout << "Tabulation: " << rodCutting(length, price, totRod) << endl;
    return 0;
}
