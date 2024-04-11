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

bool startsWith(string prefix) {
    Node* curr = root;

    for(int i=0; i<prefix.size(); i++) {
        int idx = prefix[i]- 'a';
        if(curr->children[idx] == NULL) {
            return false;
        }
        curr = curr->children[idx];
    }

    return true;
}

int main() {
    string words[] = {"apple", "app", "mango","man", "woman"};
    string prefix1 = "app";
    string prefix2 = "moon";
    int n = sizeof(words)/sizeof(words[0]);

    for(int i=0; i<n; i++) {
        insert(words[i]);

    }
    
    cout<<(startsWith(prefix1))<<endl;
    cout<<(startsWith(prefix2))<<endl;
}