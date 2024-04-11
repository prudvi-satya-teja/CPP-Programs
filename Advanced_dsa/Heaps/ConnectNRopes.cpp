#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int ropes[5] = {2, 3, 3, 4, 6};

    priority_queue<int , vector<int>, greater<int>> pq ;

    for(int i=0; i<5; i++) {
        pq.push(ropes[i]);
    }

    int cost = 0;
    while(pq.size() > 1) {
        int mn = pq.top();
        pq.pop();
        int mn2 = pq.top();
        pq.pop();
        cost += mn + mn2;
        pq.push(mn+mn2);
    }

    cout<<"cost of connecting n ropes "<< cost<<endl;
}