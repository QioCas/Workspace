#define console(...) 20221106 /*20:03:37*/
#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
const ll inf = 2e18, mod = 1e9 + 7, LOG = 32, maxN = 100005;

int n, Q;
int a[maxN];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> Q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int l = *min_element(a + 1, a + n + 1);
    int r = *max_element(a + 1, a + n + 1);
    for(int i = 1; i <= Q; ++i) {
        int c; cin >> c;
        if(l <= c and c <= r) cout << "Yes\n";
        else cout << "No\n";
    }     
}
