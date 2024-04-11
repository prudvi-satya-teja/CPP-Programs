#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
    priority_queue<int> pq;
    pq.push(3);      // O(log n)
    pq.push(4);
    pq.push(1);
    pq.push(7);
    
    while(!pq.empty()) {
        cout<<pq.top()<<endl;   // O(1)
        pq.pop();             // O(log n)
        
    }

    priority_queue<int, vector<int> ,greater<int>> pq1;
    pq1.push(3);
    pq1.push(4);
    pq1.push(1);
    pq1.push(7);

    while(!pq1.empty()) {
        cout<<pq1.top() << endl;
        pq1.pop();
    }
}