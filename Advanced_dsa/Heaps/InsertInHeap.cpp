#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Heap {
    vector<int> arr;

    void heapify(int i) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int minIdx = i;

        if(left <arr.size() && arr[minIdx] > arr[left]) {   //<  for max heap 
            minIdx  = left;
        }

        if(right < arr.size() && arr[minIdx] > arr[right]) {  //<  for max heap
            minIdx = right;
        }

        if(minIdx != i) {
            // swap 
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;

            heapify(minIdx);
        }
    }

    public:
        void push(int data) {
            // add at last index
            arr.push_back(data);

            int x = arr.size() -1;  // x is child index
            int par = (x-1) / 2; // par index


            while(arr[x] < arr[par]) {         // O(log n)     //> for max heap
                // swap
                int temp = arr[x];
                arr[x] = arr[par];
                arr[par] = temp;


                x = par;
                par = (x-1) /2;
            }
        }


        int top() {
            return arr[0];
        }

        int pop() {
            int data = arr[0];

            // step1 - swap first and last
            int temp = arr[0];
            arr[0] = arr[arr.size()-1];
            arr[arr.size()-1] = temp;

            // step - 2 : delete last
            arr.pop_back();

            // step - 3:  Heapify
            heapify(0);
            return data;
        }

        bool empty() {
            return arr.size() == 0;
        }
};


int main() {
    
    Heap* pq = new Heap();
    pq->push(3);
    pq->push(4);
    pq->push(1);
    pq->push(5);

    while(!pq->empty()) {              //heap sort  //O(n log n)
        cout<< pq->top()<<endl;
        pq->pop();
    }
    delete pq;
    return 0;
}