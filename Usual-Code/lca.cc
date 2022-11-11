#include "bits/stdc++.h" // QioCas
using namespace std;
const int maxN = 0, LOG = 0;


// Lca
int depth[maxN], parent[maxN];
int up[maxN][LOG];
vector<int> G[maxN];
void DFS(int u, int pre) {
    for(int v : G[u]) if(v != pre) {
        depth[v] = depth[u] + 1;
        up[v][0] = parent[v] = u;
        for(int k = 1; k < LOG; ++k) up[v][k] = up[up[v][k - 1]][k - 1];
        DFS(v, u);
    }
}
int LCA(int u, int v) {
    if(depth[u] < depth[v]) return LCA(v, u);
    int diff = depth[u] - depth[v];
    for(int k = LOG - 1; k >= 0; --k) 
        if(diff & (1 << k)) u = up[u][k];
    if(u == v) return u;
    for(int k = LOG - 1; k >= 0; --k) 
        if(up[u][k] != up[v][k]) u = up[u][k], v = up[v][k];
    return parent[u];
}