#define console(...) void() // 2022/11/20-21:57:07
#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
const ll inf = ll(2e18), mod = 1e8 + 7, LOG = ' ', maxN = 5e5 + 5;


ll Hash[maxN], revHash[maxN], power[maxN];
ll gethash(int l, int r) {
    return (Hash[r] - Hash[l - 1] * (power[r - l + 1]) + mod * mod) % mod;
}
ll getrevhash(int l, int r) {
    return (revHash[l] - revHash[r + 1] * (power[r - l + 1]) + mod * mod) % mod;
}
bool Palindrome(int l, int r) {
    return gethash(l, r) == getrevhash(l, r);
}
int n; string s;
int ans = 0;
signed main() { 
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s; s = ' ' + s;
    assert(n <= 5000);
    power[0] = 1;
    for(int i = 1; i <= n; ++i) {
        Hash[i] = (Hash[i - 1] * 26 + s[i] - 'a') % mod;
        power[i] = (power[i - 1] * 26) % mod;
    }
    for(int i = n; i >= 1; --i) 
        revHash[i] = (revHash[i + 1] * 26 + s[i] - 'a') % mod;
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; j += 2) {
            if(s[i + 1] != s[j]) break;
            if(Palindrome(i, j)) ++ans;
            if(Palindrome(i, j + 1) == true) ++ans;
        }
        console(ans);
    }
    cout << ans + n;
}
