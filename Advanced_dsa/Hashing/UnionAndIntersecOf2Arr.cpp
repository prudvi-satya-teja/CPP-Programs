#include<bits/stdc++.h>

using namespace std;

int main() {

    int arr1[3] = {7, 3, 9};
    int arr2[6] = {6, 3, 9, 2, 9 , 4};

    unordered_set<int> st;

    //union
    for(int i=0; i<sizeof(arr1)/sizeof(0); i++) {
        st.insert(arr1[i]);
    }

    for(int i=0; i<sizeof(arr2)/sizeof(0); i++) {
        st.insert(arr2[i]);
    }

    cout<<"union " << st.size();

    //intersection
    st.clear();

    int count = 0;
    for(int i=0; i<sizeof(arr1)/sizeof(0); i++) {
        st.insert(arr1[i]);
    }

     for(int i=0; i<sizeof(arr2)/sizeof(0); i++) {
        if(st.find(arr2[i]) != st.end()) {
            count++;
            st.erase(arr2[i]);
        }
    }

    cout<<"intersection " << count;
    
}