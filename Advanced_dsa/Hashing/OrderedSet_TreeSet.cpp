#include<bits/stdc++.h>

using namespace std;

int main() {

    set<string> st ;
    st.insert("Delhi");
    st.insert("Mumbai");
    st.insert("Noida");
    st.insert("Bengaluru");

    for(string i: st) {
        cout<< i<<" ";
    }
    cout<<endl;

     unordered_set<string> st1 ;
    st1.insert("Delhi");
    st1.insert("Mumbai");
    st1.insert("Noida");
    st1.insert("Bengaluru");

    for(string i: st1) {
        cout<< i<<" ";
    }
    cout<<endl;
}