#include<bits/stdc++.h>

using namespace std;

int main() {//O(n)

    int arr[] = {10, 2, -2, -20, 10};
    int k = -10;

    unordered_map<int,int> mp ;
    //(sum , count)
    mp.insert({0,1});

    int sum = 0;
    int ans = 0;
    for(int j=0; j<5; j++) {
        sum+= arr[j]; // sum(j)
        if(mp.find(sum-k) != mp.end()) {
            ans += mp[sum-k];
        }
       mp[sum]++;
    }
    cout<<ans<<endl;


}