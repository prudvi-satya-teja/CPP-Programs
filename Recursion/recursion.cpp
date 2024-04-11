#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// ---------------------------------------------------------------------------------------------
//print n to 1 decreasing order
int PrintDecr(int n){
	if(n == 1){
		cout << n << " ";
		return 0;
	}
    cout << n << " ";
	PrintDecr(n-1);
}

// ---------------------------------------------------------------------------------------------
//print 1 to n increaing order
int PrintInc(int n){
	if(n==1){
		cout<<n<<" ";
		return 0;
	}
    PrintInc(n-1);
    cout<<n<<" ";

}
// ---------------------------------------------------------------------------------------------
//print factorial of a number n
int fact(int n){
	if(n==0){
		return 1;
	}
    int fnm1=fact(n-1);
    int fn=n*fnm1;
    return fn;
}

// ---------------------------------------------------------------------------------------------
//print sum of first n natural numbers
int sumn(int n){
	if(n==1){
        return 1;
	}
   int snm1=sumn(n-1);
   int sum=n+snm1;
   return sum;
}

// ---------------------------------------------------------------------------------------------
//nth fibonacci number
int fibo(int n){
	if(n==1){
		return 1;
	}
	if(n==0){
		return 0; 
	}
	int firsttr=fibo(n-1);
	int secondtr=fibo(n-2); 
    int sum=firsttr+secondtr;
    return sum;
}
// ---------------------------------------------------------------------------------------------
//check the array is sorted or not
	int issorted(int arr[],int n){
     
     if(n==1){
     	return true;
     }
     return (arr[0]<arr[1])&&(issorted(arr+1,n-1));
}

// ---------------------------------------------------------------------------------------------
//first occurence in the array
int firstocc(int arr[],int key,int n,int i){
	if(i==n){
		return -1;
	}
	if(key==arr[i]){
		return i+1;
	}
	return firstocc(arr,key,n,i+1);
}

// ---------------------------------------------------------------------------------------------
//last occurence from starting of the array
int lastoccurence(int arr[], int key, int n, int i) {
	 if(i==n){
	 	return -1;
	 }
	  int isfound=lastoccurence(arr,key,n,i+1);
	  if(isfound == -1 && arr[i] == key ){
	     return i;
	  } 
	  return isfound;
}

// ---------------------------------------------------------------------------------------------
//last occurence in the array
int lastocc(int arr[],int key,int n,int i){
	if(i==n+1){
		return -1;
	}
	if(key==arr[n-i]){
          return n-i+1;
	}
	return lastocc(arr,key,n,i+1);
}

// ---------------------------------------------------------------------------------------------
//print x power n
int  power(int x,int n){
	if(n==0){
		return 1;
	}
    return x*power(x,n-1);
}
// ---------------------------------------------------------------------------------------------
//print xpower n optimised approach
int optimised_approach(int x,int n){
	if(n==0){
		return 1;
	}
	int  a=optimised_approach(x,n/2);
	int halfpowersum=a*a;
	if(n%2!=0){
	 halfpowersum=x*halfpowersum;
	}
	return halfpowersum;
}
// ---------------------------------------------------------------------------------------------
//Tiling problem
int tiling(int n){
	if(n==0||n==1){
		return 1;
	}
	//kaam
	//choices
	//vertical 
	int fnm1=tiling(n-1);

	//horizontal
	int fnm2=tiling(n-2);
	return fnm1+fnm2;
}

// ---------------------------------------------------------------------------------------------
//remove duplicates in a string

   void removeDuplicates(string str,int idx,string str1,bool map[]){
   	if(idx==str.length()){
   		cout<<str;
   		return;
   	}
   	char currChar=str[idx];
   	if(map[currChar-'a']== true){
   		removeDuplicates(str,idx+1,str,map);
   	}
   	else
   	{
   		map[currChar-'a']=true;
   		removeDuplicates(str,idx+1,str+currChar,map);
   	}
   }

// ---------------------------------------------------------------------------------------------
//friend pairing problem
int pairing(int n){
	if(n==1||n==2){
		return n;
	}
	return pairing(n-1)+(n-1)*pairing(n-2);
}

// ---------------------------------------------------------------------------------------------
int printbinstrings(int n,int lastplace,string str){
	//base case
	if(n==0){
		cout<<str<<endl;
		return 0;
	}

	//work
	printbinstrings(n-1,0,str+'0');
	if(lastplace==0){
		printbinstrings(n-1,1,str+'1');
	}
     return 0;
}
 
// ---------------------------------------------------------------------------------------------

void removeDuplicates(string str, int idx, string result, bool map[]) {
    if (idx == str.length()) {
        cout << result << endl;
        return;
    }

    char currChar = str[idx];
    if (map[currChar - 'a'] == false) {
        map[currChar - 'a'] = true;
        removeDuplicates(str, idx + 1, result + currChar, map);
    } else {
        removeDuplicates(str, idx + 1, result, map);
    }
}

int main() {
    string input = "examplestring";
    bool map[26] = { false }; // Initialize a boolean array to track character occurrences
    removeDuplicates(input, 0, "", map);
    return 0;
}


// ---------------------------------------------------------------------------------------------
//binary strings problem

      int main(){
     int n=5;
     int arr[5]={1,2,3,4,5};
     string str;
 //   PrintDecr(n);
 //   PrintInc(n);
 //   cout<<fact(n);
 //  cout<<sumn(n);
 // cout<<fibo(n);
   cout<<(issorted(arr,n));
  // cout<<(firstocc(arr,key,n,i));
  //cout<<(lastoccurence(arr,key,n,i)); 
 //cout<<optimised_approach(2,10);
    // cout<<tiling(5);
   //  cout<<pairing(4);
    //removeduplicates();
    // printbinstrings(3,0,str);
    // string str="adityacollege";
    
    // removeDuplicates(str,0,"",bool arr[25]);
     return 0;
     




}

