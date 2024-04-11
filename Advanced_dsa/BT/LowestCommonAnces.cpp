#include <iostream>
#include <vector>
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


// lowest common ancestor (Approach -1 )
bool getPath(Node* root, int n, vector<Node*>& path) {
    if (root == NULL)
        return false;

    path.push_back(root);
    if (root->data == n)
        return true;

    if (getPath(root->left, n, path) || getPath(root->right, n, path))
        return true;

    path.pop_back();
    return false;
}

Node* lca(Node* root, int n1, int n2) {
    vector<Node*> path1, path2;

    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
        return NULL;

    int i = 0;
    for (; i < path1.size() && i < path2.size(); i++) {
        if (path1[i] != path2[i])
            break;
    }
    return path1[i - 1];
}

// loweest commmon ancestor (approach - 2)
Node* lca2(Node* root, int n1, int n2) {
    if(root == NULL || root->data == n1 || root->data == n2 ) {
        return root;
    }

    Node* leftLca = lca2(root->left, n1, n2);
    Node* rightLca = lca2(root->right, n1, n2);

    // leftLCA = val rightlca = null
    if(rightLca == NULL) {
        return leftLca;
    }

    if(leftLca == NULL) {
        return rightLca;
    }

    return root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int n1 = 4, n2 = 7;
    // lowest commmon ancestor
    // Apprach - 1
    cout << lca(root, n1, n2)->data << endl;

    // Apprach - 2
    Node* result = lca2(root, n1, n2);
    if (result)
        cout << "LCA(" << n1 << ", " << n2 << ") = " << result->data << endl;
    else
        cout << "Keys not found in the tree." << endl;


    return 0;
}
