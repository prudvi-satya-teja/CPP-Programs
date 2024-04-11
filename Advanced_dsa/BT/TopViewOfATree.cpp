#include <bits/stdc++.h>
#include <queue>
#include <map>

using namespace std;

//--------------------------------------------------------------------------
// top view of a tree
// Definition of a Node in a binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Info {
public:
    Node* node;
    int hd;

    Info(Node* node, int hd) {
        this->node = node;
        this->hd = hd;
    }
};


void Topview(Node* root) {
    queue<Info> q;
    map<int, Node*> mp;

    int mn = 0, mx = 0;
    q.push(Info(root, 0));
    q.push(Info(NULL, 0));

    while (!q.empty()) {
        Info curr = q.front();
        q.pop();

        if (curr.node == NULL) {
            if (q.empty()) {
                break;
            }
            else {
                q.push(Info(NULL, 0));
            }
        }
        else {
            if (mp.find(curr.hd) == mp.end()) {
                mp[curr.hd] = curr.node;
            }

            if (curr.node->left != NULL) {
                q.push(Info(curr.node->left, curr.hd - 1));
                mn = min(mn, curr.hd - 1);
            }

            if (curr.node->right != NULL) {
                q.push(Info(curr.node->right, curr.hd + 1));
                mx = max(mx, curr.hd + 1);
            }
        }
    }

    for (int i = mn; i <= mx; i++) {
        if (mp.find(i) != mp.end()) {
            cout << mp[i]->data << " ";
        }
    }
}

int main() {

    // root node creation
    Node* root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Topview(root);
}
