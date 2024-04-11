#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void heapify(int arr[], int i, int size) {
    int left = 2 * i +1;
    int right = 2 * i +2;
    int maxIdx = i;

    if(left < size && arr[left] > arr[maxIdx]) {
        maxIdx = left;
    }
    if(right < size && arr[right] > arr[maxIdx]) {  
            maxIdx = right;
        }

        if(maxIdx != i) {
            // swap 
            int temp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = temp;

            heapify(arr, maxIdx, size);
        }
    }

void heapSort(int arr[], int n) {      // O(n log n)
    // step1 - build maxHeap
    for(int i=n/2; i>=0; i--) {
        heapify(arr, i, n);         // O(n log n)
    }

    // step2 - push largest at end
    for(int i=n-1; i>0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, 0, i);           // O(n log n)
    }
}

int main() {
    int arr[] = {1, 2, 4, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, size);

    //print
    for(int i=0; i<5; i++) {
        cout<< arr[i] <<"  ";
    }

}