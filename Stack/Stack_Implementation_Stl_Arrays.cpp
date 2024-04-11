#include<bits/stdc++.h>

using namespace std;

//--------------------------------------------------------------------------
//stack implementation using stl
/*
int main(){
	
	 //creation of stack
	 stack<int> s;
	 
	 //push operation 
	 s.push(1);
	 s.push(2);
	  s.push(3);
   	 s.push(4);
	 
	 
	 //pop operation 
	 s.pop();
	 s.pop();
	 s.pop();
     s.pop();
	 
	 
	 cout<<"printing top element "<<s.top()<<endl;
	 
	 if(s.empty()){
	 	cout<<" stack is empty "<<endl;
	 }
	 else{
	 
	 cout<<"stack is not empty "<<endl;
      }
	 
	 return 0;
}

*/
//--------------------------------------------------------------------------

 class Stack{
 	public:
 		int size;
 		int *arr;
 		int top=-1;
 		
 		Stack(int size){
 			this->size=size;
 		 arr= new  int [size];
		 }
		 
		 //push operation
		 void push(int element){
		 	if(top==size){
		 		cout<<"stack overflow"<<endl;
			 }
			 else{
			 	top++;
			 	arr[top]=element;
			 }
		 }
		 
		 //pop operation
		 void pop(){
		 	if(top==-1){
		 		cout<<"stack underflow"<<endl;
			 }
			 else {
			 	cout<<"poped out element is : "<<arr[top]<<endl;;
			 	top--;
			 }
		 }
		 
		 //peek operation
		 void peek(){
		 	if(top==-1){
		 		cout<<"stack underflow"<<endl;
			 }
			 else {
			 	cout<<"top element is : "<<arr[top]<<endl;
			 }
		 }
		 
		 //isempty operation
		 void isempty(){
		 	if(top==-1){
		 		cout<<" stack is empty"<<endl;
			 }
			else {
				cout<<" stack is not empty"<<endl;
			}
		 }
 };
  
 int main(){
 	
 	Stack st(5);
 	
 	st.push(5);
 	st.push(10);
 	st.push(15);
 //	st.push(20);
 //	st.push(25);
 	
 	st.peek();
 	
 	st.pop();
 	st.pop();
 	st.pop();
 	st.isempty();
 	
 }
