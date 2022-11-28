#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
ll dig(ll c) {
    ll res = 0;
    while(c > 0) c /= 10, ++res;
    return res;
}
signed main() {
    ll w, m, k; cin >> w >> m >> k;
    ll ans = 0;
    for(ll i = m; true; ++i) {
        if(ans + dig(i) * k > w) return cout << i - m, 0;
        // console(ans, dig(i));
        ans += dig(i) * k;
    }
}