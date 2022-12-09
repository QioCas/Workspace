#define console(...) void() // 2022/12/09-09:16:17
#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
const ll inf = ll(2e18), mod = 1000000009, LOG = ' ', maxN = 200005;

int n, Q;
ll a[maxN];
void Enter() {
    cin >> n >> Q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}
ll find(ll q) {
    ll id = upper_bound(a + 1, a + n + 1, q) - a - 1;
    return q + id;
}
void Solve() {
    sort(a + 1, a + n + 1);
    for(int  i = 2; i <= n; ++i) a[i] -= i - 1;
    for(int i = 1; i <= Q; ++i) {
        ll c; cin >> c;
        cout << find(c) << '\n';
    }
}
signed main() { 
    cin.tie(0)->sync_with_stdio(0);
    Enter();
    Solve();
}
