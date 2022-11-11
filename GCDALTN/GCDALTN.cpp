#define console(...) 20221111 /*19:52:56*/
#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
const ll inf = 2e18, mod = 1e9 + 7, LOG = 32, maxN = 200005;

ll a, b, n, ans = 1;
ll Cal(ll &a, ll &b, ll u, ll res = 1, ll res2 = 1) {
    while(a % u == 0) res *= u, a /= u;
    res *= n;
    while(b % u == 0) res2 *= u, b /= u;
    return min(res, res2);
}
signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> a >> b >> n;
    if(b % a == 0 and a != 1) return cout << b, 0;
    for(ll i = 2; i * i <= b; ++i) if(b % i == 0) {
        ll rem = b;
        if(a % i == 0) ans *= Cal(a, b, i);
        ll temp = rem / i;
        if(a % temp == 0) ans *= Cal(a, b, temp);
    }
    cout << ans;
}