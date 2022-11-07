#define console(...) 20221106 /*20:20:15*/
#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
const ll inf = 2e18, mod = 1e9 + 7, LOG = 32, maxN = 5e5 + 5;

#define mp make_pair
#define x first
#define y second

int n;
pair<ll, ll>  a[maxN], ps[maxN];
signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) ps[i] = mp(ps[i - 1].x + a[i].x, ps[i - 1].y + a[i].y);
    ll ans = -inf, rem = -inf;
    for(int i = 1; i <= n; ++i) {
        // for(int j = 1; j <= i; ++j) ans = max(ans, ps[i].y - ps[j - 1].y - (a[i].x - a[j].x));
        rem = max(rem , a[i].x - ps[i - 1].y);
        ans = max(ans, rem + ps[i].y - a[i].x);
    } 
    cout << ans;
}
