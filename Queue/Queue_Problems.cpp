#include<bits/stdc++.h>
#include<queue>
#include<stack>

using namespace std;


//----------------------------------------------------------
//queue using deque

class Queue{
	
	public:
		deque<int> d;
		
		void enqueue(int data){
			d.push_back(data);
		}
		
		int dequeue(){
			int a=d.front();
			 d.pop_front();
			 return a;
		}
		
		int qfront(){
			return d.front();
		}
		int qrear(){
			return d.back();
		}
		
};

int main(){
	
 Queue q;
 q.enqueue(1);
 q.enqueue(2);
 q.enqueue(3);
  
 cout<<"front :"<<q.qfront()<<" "<<"rear : "<<q.qrear()<<endl;
 cout<<q.dequeue()<<endl;
  cout<<"front :"<<q.qfront()<<" "<<"rear : "<<q.qrear()<<endl;
 cout<<q.dequeue()<<endl;
  cout<<"front :"<<q.qfront()<<" "<<"rear : "<<q.qrear()<<endl;
 cout<<q.dequeue()<<endl;
  cout<<"front :"<<q.qfront()<<" "<<"rear : "<<q.qrear()<<endl;
 
}

//---------------------------------------------------------
//stack using deque
/*
class Stack{
	
	public:
		deque<int> d;
		
		void push(int data){
			d.push_back(data);
		}
		
		int pop(){
			int a=d.back();
			 d.pop_back();
			 return a;
		}
		
		int top(){
			return d.back();
		}
		
};

int main(){
	
 Stack st;
 st.push(1);
 st.push(2);
 st.push(3);
 
 cout<<"peek or top : "<<st.top();
 cout<<st.pop()<<endl;
 cout<<st.pop()<<endl;
 cout<<st.pop()<<endl;
 
	

}*/
//-----------------------------------------------------------
//queue reversal
/*
void queuereversal(queue<int> q){
	
	 stack<int> st;
	 
	 while(!q.empty()){
	 	st.push(q.front());
	 	q.pop();
	 }
	 
	 while(!st.empty()){
	 	q.push(st.top());
	 	st.pop();
	 	
	 }
	 
	 while(!q.empty()){
	 	 cout<<q.front()<<" ";
	 	q.pop();
	 }
	 
	
	
	
}

int main(){
	queue<int> q;
	
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		q.push(5);
		q.push(6);
		
		queuereversal(q);
	
}
*/

//--------------------------------------------------------------------------------
//iterative two halves of a queue
/*
void interleave(queue<int> q){
	queue<int> firsthalf;
	int size=q.size();
	
	for(int i=0;i<size/2;i++){
		firsthalf.push(q.front());
		q.pop(); 
	}

	while(!firsthalf.empty()){
		q.push(firsthalf.front());
	     firsthalf.pop();
	     q.push(q.front());
	     q.pop();
	}
		while(!q.empty()){
			cout<<q.front();
			q.pop();
			
		}
	
}

int main(){
	queue<int> q;
	  
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		q.push(5);
		q.push(6);
		q.push(7);
		q.push(8);
		q.push(9);
		q.push(10);
		
		interleave(q);
		
		 
		 
	
}
*/

//--------------------------------------------------------------------------------
//print non repeating character iin a stream of characters
/*
void printNonRepeating(string str){
	int  freq[26]={0} ;
	
	queue<char> q;
	for(int i=0;i<str.size();i++){
		char ch=str[i];
		q.push(ch);
		freq[ch-'a']++;
	 
		while(!q.empty()&&freq[q.front()-'a']>1){
			q.pop();
		}
		if(q.empty()){
			cout<<"-1"<<" ";
			
		}else
		cout<< q.front()<<" ";
	}
	cout<<endl;
}

int main(){
	string str="a bbccxb";
	printNonRepeating(str);
}





*/

//---------------------------------------------------------------------------------

//stack using two queues
/*

class Stack{
public:	
	queue<int> q1;
	queue<int> q2;
	
	bool empty(){
		return q1.empty()&&q2.empty();
	}
	
	void push2(int data){
		if(!q1.empty()){
			q1.push(data);
		}else{
			q2.push(data);
		}
	}
	
	int pop2(){
		if(empty()){
			cout<<"stack emptY";
			return -1;
		}
		int top=-1;
		
		//case1
		if(!q1.empty()){
		 
		while(!q1.empty()){
			 
			 top=q1.pop();
			 
			if(q1.empty()){
				break;
			}
			q2.add(top);
			
		}
 
		//case2
		else{
		   	while(!q2.empty()){
		 topo=q2.pop();
	 
			if(q2.empty()){
				break;
			}
			q1.add(top);
		}
		return top;
	}
}
	
	int peek(){
			if(!q1.empty()){
		 
		while(!q1.empty()){
			int ele=q1.top();
			q1.pop();
			q2.add(top);
			
		}
	}
		//case2
		else{
		   	while(!q2.empty()){
			int ele=q2.top();
			q1.pop();		 
			q1.add(top);
		}
		return ele;
	}
		
	}
	
	 
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    while(!s.empty()){
    	cout<<s.peek()<<endl;
    	s.pop();
	}
}
*/

//--------------------------------------------------------------------------------
 

//queue using two stacks
/*	
	class Queue{
		public:
		
		stack<int> s1;
		stack<int> s2;
		
		bool  empty(){
			return s1.empty();
		}
		
		//O(N)
		void add(int data){
			while(!s1.empty()){
				 int ele=s1.top();
				 s1.pop();
				 s2.push(ele);
			}
			
			s1.push(data);
			
			while(!s2.empty()){
				int ele=s2.top();
				s2.pop();
				s1.push(ele);
			}
			
		}
		
		//remove element
		 int remove(){
			if(s1.empty()){
			   cout<<" queuen is empty"<<endl;
			   return -1;	
			}
			
			int ele= s1.top();
			s1.pop();
			return ele;
		} 
		 int  peek(){
			if(s1.empty()){
			   cout<<" queuen is empty"<<endl;
			   return -1;	
			}
			
			int ele= s1.top();
		 
			return ele;
		} 
		
 	
		
	};
	
	int main(){
		Queue q;
	    
	    cout<<q.empty()<<endl;
	    
	    q.add(1);
	    q.add(3);
	    q.add(2);
	     cout<<q.empty()<<endl;
	    
	    while(!q.empty()){
	    	cout<<q.peek();
	    	q.remove();
		}
	}
	*/
	

//--------------------------------------------------------------------------------	
	
	 
	
 
