#include<bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    unordered_map<char,int> mp;

    for(int i=0; i<s.size(); i++) {
        char ch = s[i];
        if(mp.find(ch) != mp.end()) {
            mp[ch]++;
        } else {
            mp[ch] = 1;
        }
    }

    for(int i=0; i<t.size(); i++) {
        char ch = t[i];
        if(mp.find(ch) != mp.end()) {
            if(mp[ch] == 1) {
                mp.erase(ch);
            } else {
                mp[ch]--;
            }
        } else {
            return false;
        }
    }
     return mp.empty();

}

int main() {
    string s = "racle";
    string t = "care";


    cout<< isAnagram(s,t)<<endl;

}