#include<bits\stdc++.h>
#include<queue>

using namespace std;

//node creation
class Node {
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


int main(){
	
	Node* root = new Node(1);
	root->right = new Node(2);
	root->left = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	
	// cout<<(height(root));
	// cout << diameter(root)<<endl;

    Info a =  diameter2(root);
    cout<< a.diam << " " << a.ht << endl;

}