#include<bits/stdc++.h>
using namespace std;

int main(){
	int k;
	int arr[20];
	for(int i=0;i<10;i++){
		
		cin>>k;
		arr[k]++;
	}
	for(int i=0;i<20;i++){
		cout<<arr[i]<<" ";
	}
}
