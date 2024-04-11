#include<bits/stdc++.h>

using namespace std;


class Twostack{
	public:
		int *arr;
		int top1;
		int top2;
		int size;
		
		Twostack(int s){
			this->size=s;
			top1=-1;
			top2=s;
			arr=new int[s];
		}
		
		//push in stack1
		void push1(int num){
			if(top2-top1>1){
				top1++;
				arr[top1]=num;
			}else{
				cout<<" stack overflow"<<endl;
			}
		}
	 
	 //push in stack2
		void push2(int num){
			if(top2-top1>1){
				top2--;
				arr[top2]=num;
			}else{
				cout<<" stack overflow"<<endl;
			}
		}
		
		//pop in stack
		int pop1(){
			if(top1>=0){
				int ans =arr[top1];
				top1--;
				return ans;
			}
			else {
				cout<<"stack Underflow"<<endl;
				return -1;
			}
		}
		
		//pop in stack
		void pop2(){
			if(top2<size){
				int ans =arr[top2];
				top2++;
			//	return ans;
			}
			else {
				cout<<"stack Underflow"<<endl;
			//	return -1;
			}
		}
	
	
};

int main(){
	
	Twostack  st1(6);
	Twostack st2(5);
 
}

