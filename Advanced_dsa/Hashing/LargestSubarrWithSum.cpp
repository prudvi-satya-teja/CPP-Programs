#include<bits/stdc++.h>

using namespace std;

int main() {//O(n)
    int arr[] = {15,-2, 2, -8, 1, 7, 10, 23};

    unordered_map<int,int> mp;
    //(sum, idx)

    int sum = 0;
    int len = 0;

    for(int j=0; j<8; j++) {
        sum+= arr[j];
        if(mp.find(sum) != mp.end()) {
            len = max(len, j-mp[sum]);
        } else {
            mp[sum] = j;
        }
    }
    cout<< len<<endl;
    return 0;
}

