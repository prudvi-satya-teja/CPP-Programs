#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> st ;

    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(1);
    st.insert(2);

    for(auto i: st) {
        cout<<i<<" ";
    }

    st.erase(2);
    if(st.find(2) != st.end()) {
        cout<<"set contains 2"<<endl;
    }

    if(st.find(4) != st.end()) {
        cout<<"set contains 4"<<endl;
    }

    st.clear();
    cout<<st.size()<<endl;

    cout<<"empty or not : "<< st.empty()<<endl;
}