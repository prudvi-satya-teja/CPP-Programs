#include<bits/stdc++.h>

using namespace std;

int main() {

    unordered_set<string> cities;

    cities.insert("Delhi");
    cities.insert("Mumbai");
    cities.insert("Noida");
    cities.insert("Bengaluru");


    for(string i: cities) {
        cout<<i <<endl;
    }
}