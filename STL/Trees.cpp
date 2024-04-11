#include<iostream>

using namespace std;


void KLevel(Node* root, int level, int k) {
    if(root == NULL) {
        retun;
    }

    if(level == k) {
        cout<< root->data << " ";
        return;
    }

    KLevel(root->left, level+1, k);
    KLevel(root->right, level+1, k);
}

int main {

}