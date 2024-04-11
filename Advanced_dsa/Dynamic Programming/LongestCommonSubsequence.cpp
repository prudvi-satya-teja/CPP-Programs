#include<bits/stdc++.h>
using namespace std;

// Recursion
int lcs(string str1, string str2, int n, int m) {
    if(n == 0 || m == 0) {
        return 0;
    }

    if(str1[n-1] == str2[m-1]) {
        return lcs(str1, str2, n-1, m-1) + 1;
    }
    else {
        int ans1 = lcs(str1, str2, n-1, m);
        int ans2 = lcs(str1, str2, n, m-1);
        return max(ans1, ans2);
    }
}

// lcs2 = Memoization code
int lcs2(string str1, string str2, int n, int m, int dp[7][6]) {
    if(n == 0 || m == 0) {
        return 0;
    }

    if(dp[n][m] != -1) {
        return dp[n][m];
    }

    if(str1[n-1] == str2[m-1]) {
        return dp[n][m] = lcs(str1, str2, n-1, m-1) + 1; 
    }
    else {
        int ans1 = lcs(str1, str2, n-1, m);
        int ans2 = lcs(str1, str2, n, m-1);
        return dp[n][m] = max(ans1, ans2);
    }
}

// Tabulation - O(n * m)
int lcsTab(string str1, string str2) {
    int n  = str1.length();
    int m = str2.length();

    string lcs = "";
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

     // Backtrack to find LCS
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "Longest Common Subsequence: " << lcs << endl;
    return dp[n][m];
}

int main() {

    string str1 = "abcdge";
    string str2 = "abedg";  // lcs = "abdg"   length = 4

    // Recursion
    cout<<lcs(str1, str2, 6, 5)<<endl;

    // Memoization lcs  - 2
    int n = 6;
    int m = 5;

    int dp[7][6];
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<m+1; j++) {
            dp[i][j] = -1;
        }
    }
    cout<<lcs2(str1, str2, n, m, dp)<<endl;

    // Tabulation  lcs - 3

    cout<<lcsTab(str1,str2)<<endl;

    return 0;
}