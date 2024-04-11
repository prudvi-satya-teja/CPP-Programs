#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;    

class Node {
    public: 
    Node* children[26];   //'a' - 'z'
    bool eow = false;

    Node() {
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
    }

};

static Node* root= new Node();

void insert(string word) {//O(L)
    Node* curr = root;
    for(int level = 0; level<word.size(); level++)  {
    int  idx = word[level] - 'a';
    if(curr->children[idx] == NULL) {
        curr->children[idx] = new Node();
    }
    curr = curr->children[idx];
}
curr->eow = true;
}

bool search(string key) {//O(L)
    Node* curr = root;
    for(int level = 0; level<key.size(); level++)  {
    int  idx = key[level] - 'a';
    if(curr->children[idx] == NULL) {
        return false;
    }
    curr = curr->children[idx];
}
return curr->eow == true;
}

int countNodes(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int count  = 0;
    for(int i=0; i<26; i++) {
        if(root->children[i] != NULL) {
            count += countNodes(root->children[i]);
        }
    }
    return count+1;
}

int main() {

    string str = "ababa";  // ans = 10

    //suffix - insert in trie{
    for(int i=0; i<str.size(); i++){
        string suffix = str.substr(i);
        insert(suffix);
    }
    cout<<countNodes(root) << endl;
}