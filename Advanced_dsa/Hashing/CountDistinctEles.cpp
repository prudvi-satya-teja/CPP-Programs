#include<bits/stdc++.h>

using namespace std;

int main() {
    int num[] = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};
    int n = sizeof(num) / sizeof(0);
    
    unordered_set<int> st ;

    for(int i=0; i<n; i++) {
        st.insert(num[i]);
    }

    cout<<st.size();
}