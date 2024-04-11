#include<bits/stdc++.h>

using namespace std;


  //new node creation  
   class Node{
   	public:
   		int data;
   		Node* next;
   		
   		Node(int data){
   			this->data=data;
   			this->next=NULL;
		   }
   };
   
   //insert at head 
   void Insertathead(Node* &head,int data){
   	
   	//creation of new node
   	Node* temp=new Node(data);
   	temp->next=head;
   	head=temp;
   	
   }
   
   //insert at tail
   void Insertattail(Node* &tail,int data){
   	
   	Node* temp=new Node(data);
   	tail->next=temp;
   	tail=temp;
   }
   
   
   //insert at position
   void Insertatposition(Node* &tail,Node* &head,int data ,int pos){
   	
   
   	if(pos==1){
   		Insertathead(head,data);
   		return;
	   }
	   	
	   Node* temp=head;
	   int count=1;
	   while(count<pos-1){
	   	temp=temp->next;
	   	count++;
	   }
	   
	   if(temp->next==NULL){
	   	Insertattail(tail,data);
	   	return;
	   }
	   
	   Node* nodetoinsert=new Node(data);
	   nodetoinsert->next=temp->next;
	   temp->next=nodetoinsert;
	   
	   
	   
	   
   }
   
   
   //printing linked list
   void printll(Node* &head){
   	
   	Node* temp=head;
   	
   	while(temp!=NULL){
   	    cout<<temp->data<<" -> ";
     	temp = temp->next;
       }
       cout<<endl;
   
   }
   
   int main(){

    Node* node1=new Node(1);
    
    Node* head=node1;
    Node* tail=node1;
    Insertathead(head,2);
    Insertathead(head,3);
    Insertathead(head,4);
    printll(head);
      
    
    
    Insertatposition(tail,head,6,2);
                                                  
   }
