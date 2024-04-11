#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

//-------------------------------------------------------
//push at bottom 
void  pushatbottom(stack<int> &s,int data){
	if(s.empty()){
		s.push(data);
		return ;
	}
	
	int top=s.top();
	s.pop();
	pushatbottom(s,data);
	s.push(top);
 
}

//-------------------------------------------------------
//reverse a string 

string revstring( string str){
	
	  stack<char> st;
	  int idx=0;
	  while(idx<str.size()){
	   char ch=str[idx];
	  	st.push( ch);
	  	idx++;
	  }
	  string str2=" ";
	  while(!st.empty()){
	  	char curr=st.top();
	  	 st.pop();
	  	str2=str2+curr;
		  	  }
	  return str2;
}

//-------------------------------------------------------
//reverse a sentence

void reverseSentence(string s){
	
	stack<string> st;
	
	for(int i=0;i<s.size();i++){
		string word=" ";
		while(s[i]!=' '&&i<s.length()){
			word+=s[i];
			i++;
		}
		st.push(word);
	}
	
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}cout<<endl;
}


//-------------------------------------------------------
//reverse a stack

void reverseastack(stack<int> s){
	if(s.empty()){
		return;
	}
	int top=s. top();
	s.pop();
	reverseastack(s);
	pushatbottom(s,top);
	
	
		
}

//-------------------------------------------------------
//stock span problem

void span(int stocks[],int span[]){
	stack<int> s;
	span[0]=1;
	s.push(0);
	
	for(int i=1;i<7;i++){
		
		int currprice=stocks[i];
		while(!s.empty()&&currprice>stocks[s.top()]){
			s.pop();
		}
		if(s.empty()){
			span[i]=i+1;
		}
		else{
			int prevhigh=s.top();
			span[i]=i-prevhigh;
		}
		s.push(i);
	}
}
//------------------------------------------------------------------------
//next greater element

void nextgreaterele(stack<int> s, vector<int> v,int arr[]){
	
	for(int i=5-1;i>=0;i++){
	//while 
	while(!s.empty()&&arr[s.top()]<=arr[i]){
		s.pop();
	}
	
	//if-else
	if(s.empty()){
		 v.push_back(-1);
	}
	else {
		  v.push_back(arr[s.top()]);
	}
	
	//push in s
	s.push( i );
   }
   for(int i=0;i<5;i++){
		cout<< v[i]<<" ";
	}
}

 //-------------------------------------------------------
 //valid paranthesis
 bool validparanthesis(string st){
 	stack<char> s;
 	cout<<st<<" ";
 	for(int i=0;i<st.size();i++){
 		char ch=st[i];
 		if(ch=='('||ch=='{'||ch=='['){
 			s.push(ch);
		 } 
		 
	else{
	
	  if(ch==')'&&s.top()=='('||ch=='}'&&s.top()=='{'||ch==']'&&s.top()==']')
		{
			s.pop();
		}else return false;
	  
	  
}
   }
		
		if(s.empty()){
	 	return true;
	    }
	   else 
	      return false;
	 
	 
 }
 	
//-------------------------------------------------------
//duplicate paranthesis

bool isduplicate(string str){
	
	stack<char> s;
	for(int i=0;i<str.size();i++){
		char ch=str[i];
	
	if(ch==')'){
		int count=0;
	    while(s.top()!='('){
	    	s.pop();
	    	count++;
	    	
			
		}
		if(count<1){
			return true;
		}
		else {
			s.pop();
			
		}
		
		
	}
	
	else {
		s.push(ch);
	}
}
return false;
}
 	
//-------------------------------------------------------
//maximum area in the histogram

int*  nextsmallerleft(int heights[],int n){
	stack<int> s;
	int* nsl =new int[n];
	
	for(int i=0;i<n-1;i++){
		
		while(!s.empty()&&heights[s.top()]>=heights[i]){
			s.pop();
		}
		if(s.empty()){  
			nsl[i]=-1 ;
		}
		else{
			nsl[i]=s.top();
		}
		
		s.push(i);
		
		
	}
     return nsl;
}
	int* nextsmallerright(int heights[],int n){
	stack<int> s;
	int* nsr =new int[n];
	
	for(int i=n-1;i>=0;i--){
		
		while(!s.empty()&&heights[s.top()]>=heights[i]){
			s.pop();
		}
		if(s.empty()){  
			nsr[i]=6;
		}
		else{
			nsr[i]=s.top();
		}
		
		s.push(i);
		
		
	}
	return nsr;
}
 
 int maxarea(int heights[],int n){
 	
 	int* nsr =nextsmallerright(heights,n);
 	int* nsl =nextsmallerleft(heights,n);
 	 
 	int maxarea=0;
 	for(int i=0;i<n;i++){
 		
 		int right=nsr[i];
 		int left=nsl[i];
 		int area=heights[i]*(right-left-1);
 		 maxarea=max(maxarea,area);
 		
	 }
	 delete[] nsr;
	 delete[] nsl;
 	
 	return maxarea;
 	
 	
 }


 
int main(){
	int heights[6]={2,1,5,6,1,2};
	
	cout<<maxarea(heights,6);
	
	
	
	//duplicate paranthesis
/*
	string s=" (a+b())";
	cout<<isduplicate(s);
 */	
//-------------------------------------------------------/*
/*	//valid paranthesis
	string s="{()";
	cout<<validparanthesis(s);
	return 0;
*/
	
	
	
//-------------------------------------------------------
	
/*	//next greter elment

	int arr[5]={6,8,0,1,3};
	stack<int> s;
	
    vector<int> v;  
//	nextgreaterele(s, v,arr); 
	for(int i=4;i>=0;i++){
	//while 
	while(!s.empty()&&arr[s.top()]<=arr[i]){
		s.pop();
	}
	
	//if-else
	if(s.empty()){
		 v.push_back(-1);
	}
	else {
		  v.push_back(arr[s.top()]);
	}
	
	//push in s
	s.push( i );
   }
   for(int i=0;i<5;i++){
		cout<< v[i]<<" ";
		cout<<" 1";
	}
	
 */
//-------------------------------------------------------	
	//stock span problem
/*	 int stocks[7]={100,80,60,70,60,85,100};
	 int span[7] ;
	 
	 for(int i=0;i< 7;i++){
	 	cout<<span[i]<<" ";
	 }
	 */
	 
	
//-------------------------------------------------------	
	//reverse a  sentence
	
//	string s="Hey, prudvi how are you doing?";
//	reverseSentence( s);
	
//-------------------------------------------------------	
 //reverse a string 
/*		
	string s="prudvi";
	string res=revstring(s);
	cout<<res;
*/
//-------------------------------------------------------
//push at bottom

/*		s.push(1);
	s.push(2);
	s.push(3);
	
	pushatbottom(s,5);
	
    while(!s.empty()){
    	cout<<s.top()<<endl;
   	s.pop();
   	*/
//-------------------------------------------------------
	
}
	
  
