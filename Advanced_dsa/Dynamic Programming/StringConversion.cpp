#include<bits/stdc++.h>
using namespace std;


// Tabulation - O(n * m)
int editDistance(string str1, string str2) {
    int n  = str1.length();
    int m = str2.length();

    // create
    int dp[n+1][m+1];

    // intialize
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<m+1; j++) {
            if(i == 0) {
                dp[i][j] = j;
            }
            if(j == 0) {
                dp[i][j] = i;
            }
        }
    }

    // bottom up
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(str1[i-1] == str2[j-1]) { // same
                dp[i][j] = dp[i-1][j-1];
            } else { // diff
                int add = dp[i-1][j] + 1;
                int del = dp[i][j-1] + 1;
                int rep = dp[i-1][j-1] + 1;
                dp[i][j] = min(add, min(del, rep));
            }
        }
    }

    return dp[n][m];
}

int main() {

    string str1 = "intention";
    string str2 = "execution";  

    // Tabulation  
    cout<<editDistance(str1,str2)<<endl;

    return 0;
}