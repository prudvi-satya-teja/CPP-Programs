// #include<bits/stdc++.h>
// using namespace std;

// // Recursion  - O(2^n)   -> n = 10^5 very slow 
// int countWays(int n) {
//     if(n < 0) {
//         return 0;
//     }
//     if(n == 0) {
//         return 1;
//     }
//     return countWays(n-1) + countWays(n-2);
// }

// // Memoization  - O(N)
// int countWaysMemoi(int n, int ways[]) {

//     if(n < 0) {
//         return 0;
//     }
//     if(n == 0) {
//         return 1;
//     }
//     if(ways[n] != 0) {  // already calcualated
//         return ways[n];
//     }

//     ways[n] = countWaysMemoi(n-1, ways)+ countWaysMemoi(n-2, ways);
//     return ways[n];

// }

//  // Tabulation  - O(N)
//  int countWaysTab(int n) {

//     int dp[n+1]  = {0};
//     dp[0] = 1;

//     for(int i=1; i<=n; i++) {
//         if(i == 1) {
//             dp[i] = dp[i-1];
//         } else {
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//     }
//     return dp[n];

// }

// int main() {

//     int n = 5;
//     int ways[6] = {0};

//     cout<<countWaysMemoi(n, ways);
//     cout<<countWaysTab(n);

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    cout<<str;
    cout<<str.length()<<endl;
    cout<<str.size()<<endl;

    return 0;
}