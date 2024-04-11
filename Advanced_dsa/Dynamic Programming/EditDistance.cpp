#include<bits/stdc++.h>
using namespace std;



// Tabulation - O(n * m)
int stringConversion(string str1, string str2) {
    int n  = str1.length();
    int m = str2.length();

    int dp[n+1][m+1];
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<m+1; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                int ans1 = dp[i-1][j];
                int ans2 = dp[i][j-1];
                dp[i][j] = max(ans1, ans2);
            }
        }
    }

    int lcsLen = dp[n][m];
    
    return (n - lcsLen) + (m - lcsLen);
}



int main() {

    string str1 = "pear";
    string str2 = "sea";  

    // Tabulation  
    cout<<stringConversion(str1,str2)<<endl;

    return 0;
}