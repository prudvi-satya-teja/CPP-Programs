#include<bits/stdc++.h>
using namespace std;

// Tabulation - O(n * m)   
// Hard level Problem
bool isMatch(string s, string p) {
    int n  = s.length();
    int m = p.length();

    bool dp[n+1][m+1];

    // initiaze
    dp[0][0] = true;

    for(int i=1; i<n+1; i++) {
        dp[i][0] = false;
    }

    for(int j=1; j<m+1; j++) {
            if(p[j-1] == '*') {
                dp[0][j] = dp[0][j-1]; 
            }
            else {
                dp[0][j] = false;
            }
    }

    // bottom up
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            // case ->  ith char == jth char || jth char == ?
            if(s[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            } 
            else  if(p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else {
                dp[i][j] = false;
            }
        }
    }

    // string ->n , pattern -> m
    return dp[n][m];
}

int main() {

    // string s = "baaabab";
    // string p = "*****ba*****ab";  // true

    string s = "abc";
    string p = "**d";  // false

    // Tabulation  
    cout<<isMatch(s, p)<<endl;

    return 0;
}