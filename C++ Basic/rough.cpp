#include<bits/stdc++.h>

using namespace std;

class Node{
	
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int data){
			this->data=data;
			this->left=NULL;
			this->right=NULL;
		}
};

Node* buildtree(Node* root){
	
	cout<<"enter the node data";
	int n;
	cin>>n;
	root=new Node(n);
	
	//base case
	if(n==-1){
		return NULL;
	}
	
	//left
	cout<<" enter the data for left child  of "<<n<<" :"<<endl;
	root->left=buildtree(root->left);
	cout<<" enter the data for right child of "<<n<<" :"<<endl;
	root->right=buildtree(root->right);
	
	return root;
	
	
}

//level order traversal

void levelordertraversal(Node* root){
	
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		
		 Node* temp=q.front();
		q.pop();
		
		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
			else{
				break;
			}
		}
		else{
			cout<<root->data;
	       	if(root->left!=NULL){
		     	q.push(root->left );
			
	     	}
	    	if(root->right!=NULL){
			    q.push(root->right);
	     	}
		
		}	
	}
}


int main(){
	
	Node* root=NULL;
	
    root=buildtree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    
    cout<<root->data<<endl;
    levelordertraversal(root);
	
	
	
	 
}







 
