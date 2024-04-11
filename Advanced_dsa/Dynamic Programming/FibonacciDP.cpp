#include<bits/stdc++.h>
using namespace std;


//Recursion
int fib(int n) {
    if(n == 0 || n==1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

// Memoization
int fibo(int n, int f[]) {    // O(N)   // before exponential now linear
    if(n == 0 || n == 1) {    
        return n; 
    }

    if(f[n] != 0) {   // fib(n) is already calculated
        return f[n];
    }

    f[n] = fibo(n-1, f) + fibo(n-2, f);
    return f[n];
}

// Tabulation 
int fibTabulation(int n) {
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1]  + dp[i-2];
    }
    return dp[n];
}


int main() {
    int n = 5;
    int f[5+1] = {0}; // 0, 0, 0
    cout<<fibo(n, f);
    

    cout<<fibTabulation(n)<<endl;
    return 0;
}