#include<bits/stdc++.h>
using namespace std;


int main() {
    map<string, int> mp;
 
    mp["India" ] = 100;
    mp["China"] = 150;
    mp["US"] = 50;
    mp["Indonesia"] = 6;
    mp["Nepal"] = 5;
    mp["Nepal"] = 50;

    set<string> keys ;
    for(auto i: mp) {
        keys.insert(i.first);
    } 

    for(auto i: keys) {
        cout<< i<< " " << mp[i] << endl;
    }
    cout<<endl;

    


}