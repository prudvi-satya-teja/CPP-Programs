#include<bits/stdc++.h>

using namespace std;


//-----------------------------------------------------------------------
 
class Node{
	
	public:
		int data;
		Node* next;
		
		Node(int data){
			this -> data = data;
			this -> next =NULL;
		}
		
		~Node(){
			int value=this->data;
			//memory free
			if(this->next!=NULL){
				delete next;
				this->next=NULL;
			
			}	cout<<"memory is free for node with data :"<<value<<" "<<next<<endl;;
		}
};

//---------------------------------------------------------------

void Insertathead(Node* &head,int data){
	
	Node* temp = new Node(data);
	temp->next=head;
	head=temp;
}

void Insertattail(Node* &tail,int data){
	
	Node* temp = new Node( data);
	tail->next=temp;
	tail=temp;
}

void Insertatposition(Node* &tail,Node* &head,int data,int pos){
  
 	if(pos==1){
 		Insertathead(head,data);
 		return ;
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
//--------------------------------------------------------------

void printll(Node* &head,Node* &tail){
	
	Node* temp = head;
	
	while(temp!=NULL){
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<endl;
	
	 cout<<"head " <<head->data<<" ";
    cout<<"tail "<<tail->data<<endl;
}

//---------------------------------------------------------
//delete at position
 void deleteatposition(Node* &tail,Node* &head,int pos){
 	
 	if(pos==1){
 		
 		Node* temp=head;
 		head=head->next;
 		
 		temp->next=NULL;
 	    delete temp;
 		
	 }
	 
	 else{
	 	
	 	Node* curr=head;
	 	Node* prev=NULL;
	 	
	 	int count=1;
	 	while(count<pos){
	 		prev=curr;
	 		curr=curr->next;
	 		count++;
		 }
		 
		 prev->next=curr->next;
		
		 curr->next=NULL;
		 delete curr;
		  if(prev->next==NULL){
		 	tail=prev;
		 }
		 
	 }
 }
//--------------------------------------------------------- 
//delete by value
  void deletebyvalue(Node* &tail,Node* &head,int value){
  	
  	
  	 
  	if(head->data==value){
  		
  		Node* temp= head;
  		head=head->next;
  		temp->next=NULL;
  		delete temp;
  		
	  }
	else{
	
  	Node* curr=head;
	Node* prev=NULL;
  	while(curr->data!=value){
  		if(curr->next==NULL){
  			cout<<"value not found"<<endl;
  			return;
		  }
		  
		prev=curr;
		curr=curr->next;
		 
  	    }
  	    prev->next=curr->next;
  	    curr->next=NULL;
  	    delete curr;
  	    if(prev->next==NULL){
  	    	tail=prev;
		  }
	}
  	
  }
  //--------------------------------------------------------- 
  //reverse linked list
  Node* reversell(Node* &head){
  	
  	Node* curr=head;
  	Node* prev=NULL;
  	Node* nextptr ;
  	
  	while(curr!=NULL){
  		nextptr =  curr->next;
  		curr->next=prev;
  		
  		prev=curr;
  		curr=nextptr;
		  		  	 
	 }
	 return prev;
  }
   //--------------------------------------------------------- ------------------------
   
   //reverse k nodes
   
     Node* reversek(Node* &head,int k){
    	
   	Node* prevptr=NULL;
   	 Node* currptr=head;
   	 Node* nextptr;
   	
	int count=0;
   	while(currptr!=NULL && count <k){
   		nextptr=currptr->next;
   		currptr->next=prevptr;
   		prevptr=currptr;
   		currptr=nextptr;
   		count++;
	}
	
	if(nextptr!=NULL){
	    head->next=reversek(nextptr,k);
	}
	
   return prevptr;
	   
   }
   
    //--------------------------------------------------------- ------------------------
    
    //to make cycle
    void makecycle(Node* &head,int pos){
    	 Node* temp=head;
    	 Node* startNode;
    	 	
    	 	int count=1;
    	 	while(temp->next!=NULL){
    	 		if(count==pos){
    	 			startNode=temp;
				 }
				 temp=temp->next;
				 count++;
			 }
			 temp->next=startNode;
	}
	
	//to detect cycle 
      bool detectcycle(Node* &head){
      	Node* slow=head;
      	Node* fast=head;
      	
      	while(fast!=NULL&&fast->next!=NULL){
      		slow=slow->next;
      		fast=fast->next->next;
      		
      		if(fast==slow){
      			return true;
			  }
			  
		  }  
		  
		return false;  
	    
	  }
	  
	  //remove cycle
	  
	  void removecycle(Node* &head){
	  	
	  	Node* fast=head;
	  	Node* slow=head;
	  	
	  	do {
	  		slow=slow->next;
	  		fast=fast->next->next;
	  		
		  }while(slow!=fast);
		  
		  fast=head;
		  while(slow->next!=fast->next){
		  	slow=slow->next;
		  	fast=fast->next;
		  
	  }
	  slow->next=NULL;
}
   

int main(){
	
	Node* node1 = new Node(5);
	
	Node* head=node1;
	 Node* tail=node1;
	
	
 
   
    Insertathead(head,10);
    Insertathead(head,15);
    
    Insertattail(tail,20);
    Insertattail(tail,25);
    
    Insertatposition(tail,head,30,6);
    printll(head,tail);
  
    deleteatposition(tail,head,6);
// deleteatposition(tail,head,4);
    printll(head,tail);
     
    
     deletebyvalue(tail,head,215);
     printll(head,tail);
      
    
     Node* newhead=reversell(head);
     printll(newhead,tail);
      
      makecycle(head,6);
  //     printll(newhead,tail);
  cout<<detectcycle(head)<<endl;
  
     removecycle(head);
     cout<<detectcycle(head)<<endl;
      printll(newhead,tail);
     
      
       
      
    
    
    
    
    return 0;
   
   
}
