#define console(...) 20221106 /*20:35:09*/
#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
const ll inf = 2e18, mod = 1e9 + 7, LOG = 32, maxN = 200005;

ll n;
ll mul(ll a, ll b) {
    ll r = 0; 
    while (b > 0) {
        if (b % 2 != 0) r = (r + a) % mod;
        a = a * 2 % mod;
        b = b / 2;
        }
    return r % mod;
}

void Solve() {
    ll ans = 0;
    for(ll i = 1; i * i <= n; ++i) {
        if(n % i == 0 and __gcd(i, n / i) == 1) ans = (ans + mul(n, i) + mul(n, n / i) ) % mod;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int Q; cin >> Q;
    while (Q--) {
        cin >> n;
        Solve();
    }
}