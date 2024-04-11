#include<bits/stdc++.h>
using namespace std;

class Node {
    public: 
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//search in bst
bool searchInBST(Node* root, int val) {

    if(root == NULL) {
        return false;
    }

    if(root->data == val) {
        return true;
    }

    if(root->data > val) {
        searchInBST(root->left, val);
    } else  {
        searchInBST(root->right, val);
    }

}

Node* findInorderSuccessor(Node* root) {
    while(root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a Node
Node* deleteNode(Node* root, int val) {
    if(root == NULL) {
        return root;
    }
    if(root->data < val) {
        root->right = deleteNode(root->right, val);
    }
    else if(root->data > val) {
        root->left = deleteNode(root->left, val);
    }
    else {// voila
        //case 1 - leaf node
        if(root->left == NULL && root->right == NULL) {
            return NULL;
        }

        //case 2 -single child
         if(root->left == NULL) {
            return root->right;
        }
        else if(root->right == NULL) {
            return root->left;
        }

        // case 3 - both children
        Node* IS = findInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = deleteNode(root->right, IS->data);
    }
    return root;
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout<<(root->data)<<" ";
    inorder(root->right);
}

// print in Range
void printInRange(Node* root, int k1, int k2) {
    if(root == NULL) {
        return;
    }
    if(root->data >= k1 && root->data <= k2) {
        printInRange(root->left, k1, k2);
        cout<<root->data << " ";
        printInRange(root->right, k1, k2);
    }
    else if(root->data <k1) {
        printInRange(root->right, k1,k2);
    }
    else {
        printInRange(root->left,k1,k2);
    }
}

void printPath(vector<int> path) {
    for(auto i: path) {
        cout<<i<<" ";
    }
    cout<<endl;
}

// root to leaf path
void printRoot2Leaf(Node* root, vector<int> path) {
    if(root == NULL) {
        return;
    }

    path.push_back(root->data);
    if(root->left == NULL && root->right == NULL) {
        printPath(path);
    }
    printRoot2Leaf(root->left,path);
    printRoot2Leaf(root->right, path);
    path.pop_back();
}

// Validate bst
bool isValidBST(Node* root, Node* min, Node* max) {
    if(root == NULL) {
        return true;
    }

    if(min != NULL && root->data<= min->data) {
        return false;
    }
    else if(max != NULL && root->data >= max->data) {
        return false;
    }

    return isValidBST(root->left, min, root) 
        && isValidBST(root->right, root, max);
}

int main() {
    
    Node* root = new Node(8);

    root->left = new Node(5);
    root->right = new Node(10);

    root->left->left = new Node(3);
    root->left->right = new Node(6);

    root->right->right = new Node(11);

    root->left->left->left = new Node(1);
    root->left->left->right = new Node(4);

    root->right->right->right = new Node(14);

    // bool ans =  searchInBST(root, 5);
    // cout<<ans<<endl;


    // //delete a node in bst
    // inorder(root);
    // cout<<endl;
    // deleteNode(root,5);
    // cout<<endl;
    // inorder(root);

    // // print in Range
    // printInRange(root,6,10);

    // all paths. from root to leaf
    // vector<int> v;
    // printRoot2Leaf(root,v);


    if(isValidBST(root, NULL, NULL)) {
        cout<<"valid"<<endl;
    } else {
        cout<< "NOt valid" << endl;
    }  
}