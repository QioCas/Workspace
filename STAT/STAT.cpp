#define console(...) void() // 2022/11/15-07:12:44
#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
const ll inf = ll(2e18), mod = 1000000009, LOG = ' ', maxN = 1e5 + 5;

int n;
int a[maxN];
map<int, int> compress, cnt; int m = 0;
signed main() { 
    cin.tie(0)->sync_with_stdio(0);
    freopen("STAT.inp", "r", stdin), freopen("STAT.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], cnt[a[i]] ++;
    for(auto&[idx, val] : cnt) m += val, compress[idx] = m;
    for(int i = 1; i <= n; ++i) 
        cout << compress[a[i]] - cnt[a[i]] << ' ' << m - compress[a[i]] << '\n';
}