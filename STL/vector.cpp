#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v;

    for(int i=0; i<10; i++) {
        v.push_back(i);
    }

    for(auto i : v) {
        cout << i<< " ";
    }

    v.pop_back();
      for(auto i : v) {
        cout << i<< " ";
    }

    
}