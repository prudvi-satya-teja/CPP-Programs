#include <bits/stdc++.h>
using namespace std;

int main() {
    int  t ;
    cin >> t;

    for(int i=0; i<t; i++) {
        int n ;
        cin >> n;

        int arr[2*n];
        for(int j=0; j<2*n; j++) {
            cin >> arr[j];
        }

       sort(arr,arr+(2*n));
       int sum = 0;
       
       for(int j=0; j<2*n; j+=2) {
            sum += arr[j];
        }
        
        cout<<sum<<endl;
    }

}
