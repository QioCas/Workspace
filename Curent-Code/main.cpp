#define console(...) void() // 2022/11/18-18:48:48
#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
const ll inf = ll(2e18), mod = 1000000009, LOG = ' ', maxN = 200005;

int n, tt;
ll a[maxN], ps[maxN];
pair<int, int> Q[maxN];
mt19937 rd(time(NULL));
int range(int left, int right) {
    return uniform_int_distribution<int>(left, right) (rd); 
}
void Enter() {
    // cin >> n >> tt;
    n = range(1, 100), tt = range(1, 100);
    for(int i = 1; i <= n; ++i) {
        // cin >> a[i];
        a[i] = range(int(-2e9), int(2e9));
    } 
    for(int i = 1; i <= tt; ++i) {
        // cin >> Q[i].first >> Q[i].second;
        Q[i].first = range(1, n);
        Q[i].second = (n, Q[i].first + range(1, n));
    }
}
ll Full(int l, int r) { // O(Q * n)
    ll total = 0;
    for(int i = l; i <= r; ++i) total += a[i];
    return total; 
}
ll Check(int l, int r) { // O(Q * 1)
    return ps[r] - ps[l - 1];
}
void Solve() {
    for(int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + a[i];
    for(int i = 1; i <= tt; ++i) {
        ll ansCheck = Check(Q[i].first, Q[i].second);
        ll ansFull = Check(Q[i].first, Q[i].second);
        cerr << ansCheck << ' ' <<  ansFull << '\n';
        assert(ansCheck == ansFull);
    }
}
signed main() { 
    cin.tie(0)->sync_with_stdio(0);
    for(int rep = 0; rep <= 1000; ++rep) {
        cerr << "Case " << rep << '\n';
        Enter();    
        Solve();
    }
}
