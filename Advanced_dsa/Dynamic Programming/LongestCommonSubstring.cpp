#include<bits/stdc++.h>
using namespace std;

// Tabulation - O(n * m)
int longestCommonSubstring(string str1, string str2) {
    int n  = str1.length();
    int m = str2.length();

    int ans  = 0;

    int dp[n+1][m+1];
    //intialize 
    for(int i=0; i<n+1; i++) {
        dp[i][0] = 0;
    }

    for(int j=0; j<m+1; j++) {
        dp[0][j] = 0;
    }

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

int main() {

    string str1 = "abcde";
    string str2 = "abgce";  // lcs = "ab"   length = 2

    // Tabulation  
    cout<<longestCommonSubstring(str1,str2)<<endl;

    return 0;
}