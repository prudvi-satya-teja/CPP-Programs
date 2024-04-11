#include<bits/stdc++.h>
#include<queue>

using namespace std;

// Node creation
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


// binary tree building
class Binarytree{
	private:
	int idx = -1;
	public:
		 
		Node* buildBinaryTree(int nodes[], int size){
			idx++;
			if(idx >= size || nodes[idx]==-1){
				return NULL;
			}
			
			Node* Newnode= new Node(nodes[idx]);
			cout<<Newnode->data << " ";
			
		    Newnode->left = buildBinaryTree(nodes, size);
			Newnode->right = buildBinaryTree(nodes, size);
			return Newnode;

		}

// preoder traversal
	void preOrder(Node* root){
	    if(root == NULL) {
	     	return;
     	}

	    cout << root->data << " ";
	    preOrder(root->left);
	    preOrder(root->right);
	    
	}

// inoder traversal
      void inOrder(Node* root){

	      if(root ==NULL){
	     	return;
     	  }

	    inOrder(root->left);
	    cout<<root->data<<" ";
	    inOrder(root->right);
	    
        }    

// postoder traversal
        void postOrder(Node* root){
	      if(root ==NULL){
	     	return;
     	   }

		postOrder(root->left);
	    postOrder(root->right);
	    cout<<root->data<<" ";
	    
	}  

// level oder traversal
     void levelOrder(Node* root){
     	if(root==NULL){
     		return ;
     	}

     	queue<Node* > q;
     	q.push(root);
     	q.push(NULL);

     	while(!q.empty()){

     		Node* temp = q.front();
			q.pop();

     		if(temp == NULL){
     			cout<<endl;
     			if(q.empty()) {
     				break;
     			} else {
     				q.push((NULL));
     			}
		}
     	else {

     		cout << temp->data;
     		if(temp->left!=NULL){
     			q.push(temp->left);
     		}
     		if(temp->right!=NULL){
     			q.push(temp->right);
     		}
     	}
	}

    }
};



int main(){
	
	int nodes[13]={1,2,4,-1,5,-1,-1,3,-1,6,-1,-1};
	
	Binarytree tree;
	Node* root= tree.buildBinaryTree(nodes, 12);
	 
    cout<<"preorder"<<endl;
    tree.preOrder(root);

	cout<<endl<< "inorder" <<endl;
    tree.inOrder(root);

	cout<<endl <<"postorder"<< endl;
    tree.postOrder(root);

	cout<<endl <<"levelordre" <<endl;
    tree.levelOrder(root);

}                 
