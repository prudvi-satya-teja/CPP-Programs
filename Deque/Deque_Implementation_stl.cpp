#include<bits/stdc++.h>
//#include<deque>

using namespace std;

//deque using arrays
class Deque{
	 int * arr;
	 int size;
	 int front;
	 int rear;
	 public:
	 	//constructor
	 	Deque(int n){
	 		size=n;
	 		arr=new int[n];
	 		front=-1;
	 		 rear=-1;
	 	}
	 		
     //push front function
     bool pushfront(int x){
     	if(isfull()){
     		return false;
		 }
		 else if(isempty()){
		 	front=rear=0;
		 }
		 else if(front==0&&rear!=size-1){
		 	front=size-1;
		 }
		 else{
		 	front--;
		 }
		 arr[front]=x;
		  return true;
     	
     	
	 }
	 
	 //push back function
	 bool pushrear(int x){
	 	if( isfull()){
     		return false;
		 }
		 else if(isempty()){
		 	front=rear=0;
		 }
		 else if( rear==size-1&&front!=0){
		   rear=0;
		 }
		 else{
		 	 rear++;;
		 }
		 arr[rear]=x;
		  return true;
     	
     	
	 }
	 	
 
	 
	 //pop front function
	 int popfront(){
	 	if(isempty()){
		
		cout<<"queue is empty"<<endl;
		return -1;
		 }
	
	int ans =arr[front];
	arr[front]=-1;
	 
	if(front==rear){//single element is present
		front=rear=-1;
		
	}
	else if(front==size-1){//to maintain cyclic array
		front=0;
	}
	else {//normal flow
		front++;
	}
	return ans;

	 	
	 }
	 //pop rear function
	 int poprear(){
	 	if(isempty()){//queuw is empty
		cout<<"queue is empty"<<endl;
		return -1;
	}
	int ans =arr[rear];
	arr[rear]=-1;
	 
	if(front==rear){//single element is present
		front=rear=-1;
		
	}
	else if( rear==0){//to maintain cyclic array
	     rear=size-1;
	}
	else {//normal flow
		 rear--;
	}
	return ans;
 }
 
 //get front
	 int getfront(){
	 	if(isempty()){
	 		return -1;
		 }
		 return arr[ front];
	 }
	 
	 //get rear
	 int getrear(){
	 	if(isempty()){
	 		return -1;
		 }
		 return arr[rear];
	 }
	 
	 //is empty
	 bool isempty(){
	 	if(front==-1){
	 		return true;}
	 		else {
	 			return false;
			 }
		 }
		 
		 //is full
		 bool isfull(){
		 	if((front==0)&&(rear==size-1)||front!=0&&rear==(front-1)%(size-1)){
		 		return true;
			 }
			 else {
			 	return false;
			 }
		 }
	 
};
int main(){
	
	Deque d(10) ;
	cout<<d.isempty()<<endl;
	cout<<d.popfront()<<endl;
		cout<<d.poprear()<<endl;
		d.pushfront(5);
		d.pushfront(6);
		d.pushrear(7);
		d.pushrear(9);
		
		cout<<d.getfront()<<endl;
		cout<<d.getrear()<<endl;
		
		d.popfront();
		d.poprear();
		d.poprear();
		cout<<d.getfront()<<endl;
		cout<<d.getrear()<<endl;
		
}







///-------------------------------------------------------------------------------------
//deque using stl
/*

int main(){
	
	deque<int> d;
	
	d.push_front(12);
	d.push_back(14);
	
	cout<<d.front()<<endl;
	cout<<d.back()<<endl;
	
	 d.pop_front();
	 
	 	cout<<d.front()<<endl;
	cout<<d.back()<<endl;
	
	d.pop_back();
	
	if(d.empty()){
		cout<<"queue is empty"<<endl;
	}else {
		cout<<"queue is not empty"<<endl;
	}
	 
	
	
}*/
