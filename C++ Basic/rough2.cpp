#include <bits/stdc++.h>
#include <stack>
using namespace std;

//circular queue

class CircularQueue{
	
	public:
	int *arr;
	int front;
	int rear;
	int size;
	
	CircularQueue(){
		size=5;
		arr=new int[size];
		front=-1;
		rear=-1;
	}
	
	//enqueue operation
	 bool enqueue(int data){
		if(front==0&&rear==n-1||front+1-rear==0){
			cout<<"queue overflow"<<endl;
			return false;
		}
		else if(front== -1){
			front=rear=0;
			arr[front]=data;
		}
		else {
			rear++;
			arr[rear]=data;
		}
		return true;
	}
	
	//deque operation
	int  dequeue()
	{
		if(front==-1)
		cout<<"queue is empty"<<endl;
		return -1;
	}
	int ans =arr[front];
	 
	if(front==rear){//single element is present
		front=rear=-1;
		
	}
	else if(front==size==-1){
		front=0;
	}
	else {
		front++;
	}
	return ans;

	

};

int main(){
	CircularQueue c;
	
	cout<<c.enqueue(5)<<endl;
	cout<<c.enqueue(6)<<endl;
	cout<<c.dequeue()<<endl;
	cout<<c.dequeue()<<endl;
	
}

























































































//queue using linkedlist
		class Node{
			
			public:
			int data;
			Node* next;
			
			Node(int data){
				
				this->data=data;
				this->next=NULL;
			}
		};
		
class Queue{
	
	public:
 
	   Node* front;
	   Node* rear;
		
	Queue(){
		front=NULL;
		rear=NULL;
	}
	
	//empty
	bool isempty(){
		if(front==NULL&&tail==NULL){
			return true;
		}
		else
		return false;
	}
	
	//add
	void enqueue(int data){
			Node* temp=new Node(data);
		 
		 if(rear==NULL){
		 
             front=rear=temp;
             rear->next=front;
             
             cout<<"front : "<<front->data<<"   rear : "<< rear->data<<endl;
             return;
		 } 
		 
		 rear->next=temp;
             rear=temp;
             
             cout<< "front : "<<front->data<<"    rear : "<<rear->data<<endl;
		 
	}
	
	void dequeue(){
		if( isempty()){
			cout<<"it has no element"<<endl;
			front=NULL;
			rear=NULL;
 
			cout<< "front : "<<front <<"    rear : "<<rear <<endl;
			return ;
		}
		front=front->next;
		cout<< "front : "<<front->data<<"    rear : "<<rear->data<<endl;
	 
	}
	
	int peek(){
		if(front==NULL ){
			cout<<"it has no element"<<endl;
			return -1 ;
			
		}
		return  front->data;
		
	}
	
};

int main(){
	
	Queue q;
    cout<<q.isempty()<<endl;
      
    q.enqueue(19);
    q.enqueue(10);
    q.enqueue(20);
    
    q.dequeue();
    q.dequeue();
    q.dequeue();
      cout<<q.isempty()<<endl;
    
     
    cout<<q.peek()<<endl;
    q.dequeue();
     
    
    
}

 

   

