#define console(...) 20221107 /*14:21:41*/
#define READ
#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
const ll inf = 2e18, mod = 1e9 + 7, LOG = 32, maxN = 200005;
template<class T, class C = greater<T>> using heap = priority_queue<T, vector<T>, C>;

#define mp make_pair
#define x first
#define y second
ll n, T;

int dis(pair<int, int> p) {
    return (p.y - p.x) + 1;
}
struct cmp {
    bool operator () (pair<int, int> u, pair<int, int> v) {
        return dis(u) < dis(v);
    }
};
heap<pair<int, int>, cmp> Q;
set<pair<int, int>> sav;
void Push(pair<int, int> p) {
    sav.insert(p); Q.push(p);
}
int u;
void Split() {
    auto i = sav.upper_bound(mp(u, n)); --i;
    pair<int, int> seg = *i;
    console(seg);
    auto pre = i, nex = i;
    --pre, ++nex;
    if(seg.x == seg.y) {
        pair<int, int> p = mp(pre->x, nex->y);
        if(pre->y != -1) sav.erase(pre);
        if(nex->x != n + 1) sav.erase(nex);
        sav.erase(i);
        Push(p);
    }
    else if(seg.x == u) {
        pair<int, int> p = mp(pre->x, u), z = mp(u + 1, i->y);
        if(pre->y != -1) sav.erase(pre);
        sav.erase(i);
        Push(p), Push(z);
    }
    else if(seg.y == u) {
        pair<int, int> p = mp(i->x, u - 1), z = mp(u, nex->y);
        if(nex->x != n + 1) sav.erase(nex);
        sav.erase(i);
        Push(p), Push(z);
    }
    else {
        pair<int, int> p = mp(i->x, u - 1), z = mp(u + 1, i->y);
        sav.erase(i);
        Push(p), Push(mp(u, u)), Push(z);
    } 
}
void Get() {
    console(sav);
    while(Q.size() and sav.find(Q.top()) == sav.end()) Q.pop();
    cout << dis(Q.top()) << '\n';
}
signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    freopen("STEP.inp", "r", stdin), freopen("STEP.out", "w", stdout);
    cin >> n >> T;
    sav.emplace(1, -1); sav.emplace(n + 1, n); // Bien
    Push(mp(1, n));
    for(int i = 1; i <= T; ++i) { 
        cin >> u;
        Split();
        Get();
    }
}