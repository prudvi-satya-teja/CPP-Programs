#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// ---------------------------------------------------------------------------------------------
int GetIthBit(int n,int i){

    int bitmask=1<<i;
    if((n&bitmask)==0){
        cout<<"0"<<" ";
    }
    else 
    cout<<"1"<<" ";

}

// ---------------------------------------------------------------------------------------------
int SetIthBit(int n,int i){

    int bitmask=1<<i;
    cout<<(n | bitmask)<<" ";

}

// ---------------------------------------------------------------------------------------------
int ClearIthBit(int n,int i){
    int bitmask=(~1<<i);
    cout<< (n & bitmask)<<" ";

}

// ---------------------------------------------------------------------------------------------
int UpdateIthBit(int n,int i,int newbit){
   if(newbit==0)
    ClearIthBit(n,i);
     else 
     SetIthBit(n,i);

 

}

// ---------------------------------------------------------------------------------------------
int UpdateIthBit2(int n,int i,int newbit){

    ClearIthBit(n,i);
    int bitmask=1<<newbit;
    cout<<(n|1<<bitmask);

}

// ---------------------------------------------------------------------------------------------
int ClearLastIBits(int n,int i){
    int bitmask=(~0<<i);
    cout<<(n&bitmask);

}

// ---------------------------------------------------------------------------------------------
int ClearBitsInRange(int n,int i,int j){
    int a=(~0)<<j+1;
    int b=(1<<i)-1;
    int bitmask=a|b;
    cout<<(n&bitmask);
}

// ---------------------------------------------------------------------------------------------
int Powerof2(int n){
    int bitmask=n&(n-1);
    if(bitmask==0){
        cout<<"power of 2";
    }
    else 
    {
        cout<<" not a Power of 2";
    }
}

// ---------------------------------------------------------------------------------------------
int CountSetBits(int n){
    int count=0;
    while(n>0){
        if((n&1)==1){
            count++;
        }
        n=n>>8;
    }
    cout<<count;

}

// ---------------------------------------------------------------------------------------------
int Fastexp(int a,int n){
    int sum=1;
     while(n>0){

        if((n&1)!=0){
         sum=sum*a;
     }
     a=a*a;
     n=n>>1;
}
cout<<sum;
}

 


int main(){

int a;
// cout<<"1"<<" ";
 cin>>a;

  int i;
   cin>>i;
 
 int k;
 cin>>k;
//cin>>j;

// int newbit;
// cin>>newbit;
 
//  pos(a,i,k);

}