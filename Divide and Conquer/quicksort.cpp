#include<bits/stdc++.h>
using namespace std;

int  partition(int [],int ,int);
void printarr(int []);
 
void quicksort(int arr[],int si,int ei){

     if(si>=ei){
     	return;
     }
	
	int pidx=partition(arr,si,ei);
	quicksort(arr,si,pidx-1);
	quicksort(arr,pidx+1,ei);
}

int partition(int arr[],int si,int ei){
    
    int pivot=arr[ei];
    int i=si-1; //to make place foe els smaller than pivot

    for(int  j=si;j<ei;j++){
    	if(arr[j]<=pivot){
    		i++; 
    		int temp=arr[j];
    		arr[j]=arr[i];
    		arr[i]=temp;
    	}
    }

     

    i++;
    arr[ei]=arr[i];
    arr[i]=pivot;
 
    return i;
}

void printarr(int arr[]){
	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	     }
    cout<<endl;
}


int main(){

     int arr[6]={8,14,7,6,1,-5};
	 quicksort(arr,0,5);
	 printarr(arr);
}