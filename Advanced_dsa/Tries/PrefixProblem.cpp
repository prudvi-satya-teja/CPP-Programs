#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node* children[26];
    int freq;

    Node() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        freq = 0;
    }
};

static Node* root = new Node();

// Function to insert a word into the trie
void insert(string word) {
    Node* curr = root;
    for(char c : word) {
        int idx = c - 'a';
        if(curr->children[idx] == NULL) {
            curr->children[idx] = new Node();
        }
        curr = curr->children[idx];
        curr->freq++;
    }
}

// Function to find the shortest unique prefix for a word
string findShortestUniquePrefix(string word) {
    Node* curr = root;
    string prefix;
    for(char c : word) {
        int idx = c - 'a';
        prefix += c;
        curr = curr->children[idx];
        if(curr->freq == 1) {
            break;
        }
    }
    return prefix;
}

// Function to find shortest unique prefixes for all words
vector<string> findShortestUniquePrefixes(vector<string>& words) {
    vector<string> result;
    for(string word : words) {
        result.push_back(findShortestUniquePrefix(word));
    }
    return result;
}

int main() {
    vector<string> words = {"zebra", "do", "duck", "dove"};
    
    // Insert words into the trie
    for(string word : words) {
        insert(word);
    }
    
    // Find shortest unique prefixes for all words
    vector<string> prefixes = findShortestUniquePrefixes(words);
    
    // Print the result
    for(int i = 0; i < words.size(); i++) {
        cout << words[i] << ": " << prefixes[i] << endl;
    }
    
    return 0;
}



// #include<bits/stdc++.h>

// using namespace std;

// class Node {
//     public :
//     Node* children[26];
//     bool eow = false;
//     int freq = 0;

     
//         Node() {
//             for(int i=0; i<26; i++) {
//                 children[i] = NULL;
//             }
//             freq = 1;
//         }
// };
// static Node* root = new Node();

// void insert(string word) {
//     Node* curr = root;
//     for(int i=0; i<word.size(); i++) {
//         int idx = word[i] - 'a';
//         if(curr->children[idx] == NULL) {
//             curr->children[idx] = new Node();
//         } else {
//             curr->children[idx].freq++;
//         }
//     }
//     curr = curr->children[idx];
// }
// int main() {

//     string arr[] = {"zebra", "dog", "duck", "dove"};

// }