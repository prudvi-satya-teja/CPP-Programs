#include<bits/stdc++.h>
using namespace std;


int main() {


    map<string,int>  mp ;

    //Insert - O(1)
    mp["India"] = 100;
    mp["China"] = 150;
    mp["US"] = 50;
    mp.insert({"Idonesia", 25});

    unordered_map<string,int>  mp1 ;

    //Insert - O(1)
    mp1["India"] = 100;
    mp1["China"] = 150;
    mp1["US"] = 50;
    mp1.insert({"Idonesia", 25});


    for(auto i: mp) {
        cout<<i.first<<" ";
    }
    cout<<endl;

      for(auto i: mp1) {
        cout<<i.first <<" ";
    }
}