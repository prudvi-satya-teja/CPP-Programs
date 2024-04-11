#include<iostream>
#include<vector>
#include<climits>
#include<math.h>
using namespace std;

                             //ARRAYS
//Arrays initialisation and taking input and printing the array 
// ---------------------------------------------------------------------------------------------
                            //finding max and min element
/*
int main()
{
    int n;
    cin>>n;
     
    int arr[n];

    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
    	cout<<arr[i];-
    }

    int maxno= INT_MIN,minno=INT_MAX;
    for(int i=0;i<n;i++)
    {
     maxno=max(maxno,arr[i]);
     minno=min(minno,arr[i]);
    }
    cout<<"max: "<<maxno<<" min: "<<minno;
    return 0;

}
*/

// ---------------------------------------------------------------------------------------------
                            //linear search and binary  search
/*
int linear_search(int arr[],int key,int n)
{

           
   	for(int i=0;i<n;i++)
   	
	{
       if(arr[i]==key)
       {
          return i;
       }
	}
	return -1;
}

int binary_search(int arr[],int key,int n)
{
	int low=0;
	int high=n;
	
           while(low<=high)
             {
             	int mid=low+high/2;

             	if(arr[mid]==key)
             	{
             		return mid;
             	}
             	else if(key>arr[mid])
           		  {
           		    	low=mid+1;
           		  }
             	else 
           	        {
           		        high=mid-1;
                 	}
           }
           return -1;
}

int main()
{
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int key;
	cin>>key;
    
 cout<<binary_search(arr,key,n);
 return 0;
     
}
// ---------------------------------------------------------------------------------------------
                        // Trapped Water
int trapped_water(int arr[],int n,int width)
{

    int leftmax[n],rightmax[n];
    leftmax[-1]=0,rightmax[n]=0;


    for(int i=0;i<n;i++)
    {
       leftmax[i]=max(arr[i],leftmax[i-1]);

    }
    for(int i=n-1;i>=0;i--)
    {
        rightmax[i]=max(arr[i],rightmax[i+1]);
    }
     int sum=0,curs;
    for(int i=0;i<n;i++)
    {
         curs=(min(leftmax[i],rightmax[i])-arr[i])*width;
            sum+=curs;
    }
    cout<<sum;
    return 0;
}

int main()
{
    int n;
    cin>>n;
    
     int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int width;
    cin>>width;

    trapped_water(arr,n,width);
    return 0;

}*/

// ---------------------------------------------------------------------------------------------
                    // buy and sell stocks

  /*

int buyandsellstocks(int arr[],int n)
{
    int buyprice=INT_MAX;
    int maxprofit=0;
    for(int i=0;i<n;i++){
        buyprice=min(buyprice,arr[i]);
        int profit=arr[i]-buyprice;
        maxprofit=max(profit,maxprofit);
    }
    cout<<maxprofit<<" ";return 0;
}
int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }

    buyandsellstocks(arr,n);
    return 0;
    
}*/

// ---------------------------------------------------------------------------------------------

/*

int main(){

    int n ;
    cin >> n ;

    int arr[n] ;
    for( int i=0 ; i<n ; i++ ){
        cin >> arr[i] ;
    }

    int count=0;
    
    for( int i=0 ; i<n; i++ ){
        for( int j=i+1 ;j<n;j++ ){
            if(arr[i] == arr[j]){
                count++ ;
                break ;
            }
        }
        if (count == 1){
            break ;
        }
    }

    if(count == 1){
        cout << "true";
    }
    else
        cout << "False";

    return 0;
}
*/

// ---------------------------------------------------------------------------------------------
/*
int main(){

    int n;
    cin >> n ;

    int arr[n];
    for( int i=0 ; i<n ;i++ ){
        cin >> arr[i];
    }

    int maxprofit=INT_MIN,curprofit,buyingprice=INT_MAX;
    for( int i=0 ; i<n ; i++ ){
        buyingprice = min(arr[i],buyingprice) ;
        curprofit=arr[i]-buyingprice;
        maxprofit=max(curprofit,maxprofit);
    }

    cout<<maxprofit;
}
*/

// ---------------------------------------------------------------------------------------------

/*
int main(){

    int n;
    cin >> n;

    int arr[n];
    for(int i=0 ; i<n; i++){
        cin >> arr[i];
    }
     
    int leftmaxarr[n];
    leftmaxarr[0]=arr[0];
    for(int i=1 ; i<n ; i++){
         leftmaxarr[i] = max( arr[i] , leftmaxarr[i-1]);
    }

    int rightmaxarr[n];
    rightmaxarr[n-1] = arr[n-1];
    for(int i=n-2 ; i>=0 ; i--){
        rightmaxarr[i] = max( arr[i] , rightmaxarr[i+1]);
    }
     
    int trappedwater,total=0;
    for(int i=0 ; i<n ;i++){
        trappedwater=(min(leftmaxarr[i] , rightmaxarr[i])) - arr[i];
         total+=trappedwater;
    }

    cout << total;
}
*/

// ---------------------------------------------------------------------------------------------
/*
int main(){

    int n;
    cin >> n;

    int arr[n];
    for(int i=0 ; i<n ;i++){
        cin >> arr[i];
    }

    cout << "[" ;
    for( int i=0 ; i<n ;i++){
        for( int j=i+1 ; j<n ; j++){
            for( int k=j+1 ; k<n ; k++){
                if( arr[i] + arr[j] + arr[k] == 0  && i!=j && j!=k && i!=k)
                {
                    cout << "[" << arr[i] << "," << arr[j] << "," << arr[k] <<"]";  
                }
            }
        }
    }

    cout << "]";
}
*/

// ---------------------------------------------------------------------------------------------
/*                          //decimal to binary
int main(){

    int n;
    cin >> n;

    int i=0,arr[32];
    while(n!=0)
    {
        arr[i]=n%2;
        n=n/2;
        i++;
    }

    for(int j=i-1;j>=0;j--){
        cout<<arr[j];
    }

}

 int main()
 {
    vector<int>v1{1,3,4,5};
    vector<int>v2;
    v2.empty();
    v2.swap(v1);
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(40);
    v1.push_back(50);
    v1.pop_back();
    v1.clear();
      cout<<*v1.cbegin();
 
 }*/

 // ---------------------------------------------------------------------------------------------
/*
int main(){

    int n;
    cin >> n;

    int arr[n];
     for(int i=0; i<n; i++){
        cin>>arr[i];
     }

     int mx=arr[0];
     for(int i=0; i<n; i++){
         mx=max(arr[i],mx);
     }

     int count[mx+1]={0};
     for(int i=0; i<n; i++){
        count[arr[i]]++;
         
     }
    
    int j=0;
    for(int i=1; i<mx+1; i++){
        cout<<count[i]<<" ";
         while(count[i]!=0){
            arr[j]=i;
            j++;
            count[i]--;
         }

     }

     for(int i=0; i<n; i++){
        cout << arr[i]<<" ";
     }
}*/

// ---------------------------------------------------------------------------------------------

int main() {

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int mx=arr[0];
    for(int i=0;i<n;i++){
        mx=max(mx,arr[i]);
    }


    int count[mx+1]= {0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
     
     int j=0;
    for(int i=1; i<mx+1; i++){
      while(count[i]!=0){
        arr[j]=i;
        j++;
        count[i]--;
      }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}