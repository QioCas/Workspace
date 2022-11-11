#include "bits/stdc++.h" // QioCas
using namespace std;


map<int, int> compress; vector<int> decompress = {0}; /* Compress number range [-2^64: 2^64-1] */
template<class T, class... U> void push(T &&a, U &&...b) { compress[forward<int>(a)] = 0; (int[]) {(compress[forward<int>(b)] = 0, 0)...}; }
void Compress() { for(auto &it : compress) it.second = decompress.size(), decompress.push_back(it.first); }
