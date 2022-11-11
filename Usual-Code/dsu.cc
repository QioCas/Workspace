#include "bits/stdc++.h" // QioCas
using namespace std; 

// Disjoint set
struct dsu{ 
    vector<int> par;
    dsu(int n = 0) {
        par.resize(n + 1);
        for(int i = 0; i <= n; ++i) par[i] = i;
    }
    int find(int u) {
        if(u == par[u]) return u;
        return par[u] = find(par[u]);
    }
    int unique(int u, int v) {
        if((u = find(u)) == (v = find(v))) return 0;
        if(par[v] < par[u]) swap(u, v); 
        par[v] = u;
        return 1;
    }
};