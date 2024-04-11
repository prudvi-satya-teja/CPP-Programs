#include<bits/stdc++.h>

using namespace std;

int searcht(int arr[],int tar,int si,int ei){
    
    if(si>ei){
    	return -1;
    }


	int mid=(si+ei)/2;

	if(tar==mid){
		return mid;
	}

	//line 1l
	if(arr[si]<=arr[mid]){
    if(arr[si]<=tar&&tar<=arr[ei]){
    	return searcht(arr,tar,si,mid-1);
    }
    else{
    	return searcht(arr,tar,mid+1,ei);
    }
}
else {
	if(arr[mid+1]<=tar&&tar<=arr[ei]){
		return searcht(arr,tar,mid+1,ei);
	}
	else {
		return searcht(arr,tar,si,mid-1);
	}
}
}
int main(){

	int arr[8]={4,5,6,7,0,1,2,3};

	int target=2;

	int f=searcht(arr,target,0,7);
     cout<<f;
}