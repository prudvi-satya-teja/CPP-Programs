#include<bits/stdc++.h>

using namespace std;

int main() {

    //create 
    unordered_map<string,int>  mp ;


    //Insert - O(1)
    mp["India"] = 100;
    mp["China"] = 150;
    mp["US"] = 50;
    mp.insert({"Idonesia", 25});

    // for(auto i: mp) {
    //     cout<< i.first<< " "<< i.second <<endl;
    // }


    // at - O(1)
    int population = mp.at("India");
    cout<< population<<endl;


    // find()  - O(1)
     if(mp.find("India") != mp.end()) {
        cout<< mp["India"]<<endl;
     }

     //erase()  - O(1)
     cout<<mp.erase("Nepal")<<endl;
     cout<<mp.erase("China")<<endl;
     
    // for(auto i: mp) {
    //     cout<< i.first<< " "<< i.second <<endl;
    // }

    cout<<mp.size()<<endl;

    cout<<mp.empty()<<endl;
    mp.clear();
    cout<<mp.empty();
     


}


//Linked hash map 