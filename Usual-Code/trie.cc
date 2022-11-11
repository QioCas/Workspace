#include "bits/stdc++.h" // QioCas
using namespace std;

// Trie
struct trie {
    char base = 'a'; 
    trie* child[26];
    int end = 0; 
    trie() { for(int i = 0; i < 26; ++i) child[i] = NULL; }
    void add(string s) {
        trie* node = this;
        for(char c : s) {
            if(node->child[c - base] == NULL) node->child[c - base] = new trie();
            node = node->child[c - base];        
        }
        
    }
};