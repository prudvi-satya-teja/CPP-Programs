#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;
void mergesort(int [],int ,int );
void merge(int [],int,int, int);

void printarr(int arr[],int n){
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

void mergesort(int arr[],int si,int ei){
     if(si>=ei){
        return ;

     } 
    
      
    //kaam
    int mid=si+(ei-si)/2;
    mergesort(arr,si,mid);
    mergesort(arr,mid+1,ei);
    merge(arr,si,mid,ei);


}
void merge(int arr[],int si,int mid,int ei){
     
    int temp[ei]={};
    int i=si;
    int j=mid+1;
    int k=si;


     while(i<=mid&&j<=ei){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
     }


     while(i<=mid){
        temp[k++]=arr[i++];
        
     }

     while(j<=ei){
        temp[k++]=arr[j++];
      
     }

     for(int i=si;i<=ei;i++){

        arr[i]=temp[i];
     }

      for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
 
 int main(){

    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
       
       mergesort(arr,0,n-1);
       printarr(arr,n);
 }