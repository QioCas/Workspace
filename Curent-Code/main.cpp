#define console(...) void() // 2022/12/10-19:37:05
#define READ 
#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
const ll inf = ll(2e18), mod = 1000000009, LOG = ' ', maxN = 200005;

int n; 
ll a[maxN], ps[maxN];
ll dp[4][maxN];

void Enter() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
}

void Solve() {
    for(int i = 1; i <= 3; ++i) fill(dp[i] + 0, dp[i] + n + 1, -inf);
    for(int i = 1; i <= n; ++i) {
        dp[1][i] = max(dp[1][i - 1], 2 * ps[i]);
        dp[2][i] = max({dp[2][i - 1], dp[1][i - 1] - 2 * ps[i], 0 - 2 * ps[i]});
        dp[3][i] = max({dp[3][i - 1], dp[2][i - 1] + 2 * ps[i]});
    }
    ll ans = -inf;
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, dp[3][i] - ps[n]);
        console(dp[3][i], ps[n]);
    }
    cout << ans;
}

signed main() { 
    cin.tie(0)->sync_with_stdio(0);
    Enter();
    Solve();
}
