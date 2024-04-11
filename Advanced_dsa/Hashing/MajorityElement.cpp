#include<bits/stdc++.h>

using namespace std;

int main() {

    int arr[] = {1, 3, 2, 5, 1, 3, 1, 5, 1};
    int size = 9;
    unordered_map<int,int> mp ;
    for(int i: arr) {
        if(mp.find(i) != mp.end()) {
            mp[i]++;
        } else {
            mp[i]= 1;
        }
    }

    for(auto i : mp) {
        if(mp[i.first] > (size/3)) {
            cout<< i.first<<" ";
        } 
    }

}