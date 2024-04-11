#include<bits/stdc++.h>

using namespace std;

//--------------------------------------------------------------------------------------------------

//creating of a node
class Node{
	public:
		int data;
		Node* prev;
		Node* next;
		
		
		Node(int data){
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
		}
		~Node(){
			int val=this->data;
			if(next!=NULL){
				delete next;
				next=NULL;
			}
			cout<<"memory free for node"<<endl;
		}
};


//--------------------------------------------------------------------------------------------------

//finding length of double linked list 
int lengthdll(Node* &head){
	Node* temp=head;
	
	int cnt=1;
	while(temp->next!=NULL){
		cnt++;
		temp=temp->next;
	}
	 
	return cnt;
}


//--------------------------------------------------------------------------------------------------

//printing double linked list or traversing a double linked list
printdll(Node* &head,Node* &tail){
	
	Node* temp=head;
	
	while(temp!=NULL){
		cout<<temp->data<< " <=> ";
		temp=temp->next;
		
	}
 	cout<<" head "<<" : "<<head->data ;
 	cout<<"    tail "<<" : "<<tail->data<<endl;
    cout<<"length of dll : "<<lengthdll(head)<<endl;
	cout<<endl;
}

//--------------------------------------------------------------------------------------------------

//insert at head

void insertathead(Node* &head,int data){
	
	Node* temp=new Node(data);
	
    head->prev=temp;
    temp->next=head;
    
    head=temp;
	

}

//insert at tail
void insertattail(Node* &head,Node* &tail,int data){
	
	Node* temp=new Node(data);
	 
	
    tail->next=temp;
    temp->prev=tail;
    
    tail=temp;
     
}

//insert at position 

void insertatpos(Node* &head,Node* &tail,int data,int pos){
	
	if(pos==1){
		insertathead(head, data);
		return ;
	}
      Node* temp=head;
     int cnt=1;
     while(cnt<pos-1){
    	 
    	  temp= temp->next;
    	   cnt++;
	}
	
	if( temp->next==NULL){
		insertattail(head,tail,data);
		return ;
	}
	 
	 Node* node2insert= new Node(data);
  	node2insert->next= temp->next;
	 temp->next->prev=node2insert ;
		temp->next=node2insert;   
		node2insert->prev=temp;
}

//--------------------------------------------------------------------------------------------------

void deleteatpos(Node* &head,Node* &tail,int pos){
	if(pos==1){
		Node* temp=head;
		head=temp->next;
		temp->next=NULL;
		head ->prev=NULL;
		delete temp;
	}
	
	Node* temp=head;
	
	int cnt=1;
	while(cnt<=pos-1 ){
		 temp=temp->next;
		 cnt++;
	}
	
	if(temp->next ==NULL){
		tail=temp->prev;
	     temp->prev->next=NULL;
	     temp->prev=NULL;
	     delete temp;
	}
	
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	temp->next=NULL;
	temp->prev=NULL;
	delete temp;
	
	
	
}

//------------------------------------------------------------------------------------------------
   //reverse linked list
  Node* reversell(Node* &head,Node* &tail){
  	
  	Node* curr=head;
  	tail=head;
  	Node* prev=NULL;
  	Node* nextptr ;
  	
  	while(curr!=NULL){
  		nextptr =  curr->next;
  		curr->next=prev;
  		curr->prev=nextptr;
  		
  		prev=curr;
  		curr=nextptr;
		  		  	 
	 }
	 return prev;
  }


int main(){
	
	Node* node1=new Node(5);
	Node * head =node1;
	Node* tail=node1;
  
	printdll(head,tail);
	
	//cout<<"length of dll : "<<lengthdll(head)<<endl;
	
	insertathead(head,10);
	insertathead(head,15);
	 
	
	insertattail(head,tail,20);
	insertattail(head,tail,25);
 
	
	insertatpos(head,tail, 1,5);
	printdll(head,tail);
	
	deleteatpos(head,tail,3);
	printdll(head,tail);\
	
	 Node* newhead=reversell(head,tail );
	printdll(newhead,tail);
 
	
	
	
	
	return 0;
}
