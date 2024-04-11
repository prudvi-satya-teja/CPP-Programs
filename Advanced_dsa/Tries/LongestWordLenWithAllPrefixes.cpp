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

static string ans = "";
void longestWord(Node* root, string temp) {
    if(root == NULL) {
        return;
    }

    for(int i=0; i<26; i++) {  // a, b, c, d,e                  //for(int i=25; i>=0; i--) {
        if(root->children[i] != NULL && root->children[i]->eow == true) {
            char ch = i + 'a';
            temp += ch;
            if(temp.length() > ans.size()) {
                ans = temp + "";
            }

            longestWord(root->children[i],temp);
            temp.pop_back();  // bracktrack
        }
    }
}

int main() {
    string words[] = {"a", "banana", "app","appl", "ap", "apply","apple"};
    int n = sizeof(words)/sizeof(words[0]);

    for(int i=0; i<n; i++) {
        insert(words[i]);

    }
    
    string key = "ilike";
    longestWord(root, "");
    cout << ans<<endl;
}