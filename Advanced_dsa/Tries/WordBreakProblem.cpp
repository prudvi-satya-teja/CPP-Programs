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


// Word Break Problem
bool wordBreak(string key) {
    int sz = key.size();
        if(sz == 0) {
            return true;
        }
    for(int i=1; i<=sz; i++) {
        //substring(beg idx, last idx)
    

       if(search(key.substr(0, i ))  && 
       wordBreak(key.substr(i)))  {
        return true;


       }
    }
    return false;
}

int main() {
    string arr[] = {"i", "like", "sam","samsung", "mobile", "ice"};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++) {
        insert(arr[i]);

    }
    
    string key = "ilike";
    cout<<(wordBreak(key))<<endl;
}