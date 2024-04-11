#include<bits/stdc++.h>

using namespace std;
 
	class Node{
	            public:
               int data;
	            Node* next;
	
	           Node(int data){
		             this->data=data;
		             this->next=NULL;
	           }
	       };
	           
 
	
	     class Stack{
	     	public:
	     		 	Node* top=NULL;
	     	
	   
	     	 
	     	//push operation
	        void push( int data){
		
	             Node* temp=new Node(data);
	             temp->next=top;
		         top=temp;
             	}
	
         	//pop operation
            void  pop (){
		        if(top==NULL){
		          	cout<<"stack underflow"<<endl;
		          	return ;
		        }
				else {
			     cout<<" poped element : "<< top->data<<endl;
			     top= top->next;
		       }
         	}
	
	     //peek operation
	       int  peek(  ){
		     if(top==NULL){
			    cout<<" stack underflow "<<endl;
	     	}
		    else {
			    cout<<" top : "<< top->data<<endl;
		        }
	       }
	
	       //isempty operation
        	bool isempty(){
		        return top==NULL; 
			}
			
			void display(){
				while(top!=NULL){
 	 
 		  cout<<top->data<<" "<<endl;
 		      top=top->next;
 		
	 }
			}
 
	     	
		 
};
	
 

int main(){
	
	  Stack st;
	
 	st.push(6);
 	st.push(7);
 	st.push(8);
 	
 	st.display();
	
 	st.pop();
 	st.pop();
 	cout<<st.isempty()<<endl;
 	return 0;
	 
}
