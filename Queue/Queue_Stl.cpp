#include<bits/stdc++.h>
#include<queue>

using namespace std;
 
//------------------------------------------------------------
//circular queue using arrays
/*
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



*/



//----------------------------------------------------------
//queue using array immplementation
/*
class Queue{
	
	int* arr;
	int front;
	int rear;
	int size;
	
	public:
		Queue(){
			size=100;
			arr=new int[size];
			front=-1;
			rear=-1;
		}
		
		bool isempty(){
		      
		     	if(front==-1||front>rear){
			   
		     	return true;
			 }
			  return false;
		}
		
		void enqueue(int data){
			if(rear==size-1){
				cout<<" queue overflow"<<endl;
				return ;
			}
			  rear++;
			  arr[rear]=data;
			  
			  if(front==-1){
			  	front++;
			  }
		}
		
		 void  dequeue(){
			if(front==-1||front>rear){
				cout<<"no elements in queue";
				return;
			}
		  
				 front++;
		 
		 }
		int  peek(){
			if(front==-1||front>rear){
				cout<<"no elements in queue"<<endl;
				return -1;
			}
		  return arr[front];
		}
		
	};


int main(){
	
	Queue q;
          
    cout<<q.isempty()<<endl;
    
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7); 
    
	cout<<q.isempty()<<endl;
    

    
    
    cout<<"front : "<<q.peek()<<endl;
    
    q.dequeue(); 
	cout<<"front : "<<q.peek()<<endl;
    q.dequeue();
	cout<<"front : "<<q.peek()<<endl;
	q.dequeue();
	cout<<"front : "<<q.peek()<<endl;
	         
	
}*/
//------------------------------------------------------------------------------
//queue stl

/*
int main(){
	
	//create a queue
	
	queue<int> q;
	
	q.push(11);
	cout<<" front of q is :"<<q.front()<<endl;
	
	q.push(15);
	cout<<" front of q is :"<<q.front()<<endl;
	q.push(13);
	cout<<" front of q is :"<<q.front()<<endl;
	
	cout<<" size of queue is:"<<q.size()<<endl;
	q.pop();
	
	cout<<" size of queue is:"<<q.size()<<endl;
	cout<<" front of q is :"<<q.front()<<endl;

	
	if(q.empty()){
		cout<<" queue is empty"<<endl;
	}else {
		cout<<" queue is not empty"<<endl;
	}
}*/
