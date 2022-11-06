#define console(...) 20221106 /*20:06:20*/
#define READ
#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
const ll inf = 2e18, mod = 1e9 + 7, LOG = 32, maxN = 200005;

int Q;
int n, k;
string s;
int sav[30];
void Solve() {
    cin >> n >> k >> s;
    s = ' ' + s;
    for(int i = k + 1; i <= n / 2; ++i) 
        if(s[i] != s[n - i + 1]) return cout << "No\n", void();
    for(int i = 1; i <= 26; ++i) sav[i] = 0;
    console();
    console(s);
    for(int i = 1; i <= k; ++i) sav[s[n - i + 1] - 'a' + 1]++;
    for(int i = 1; i <= k; ++i) {
        if(sav[s[i] - 'a' + 1] == 0) return cout << "No\n", void();
        sav[s[i] - 'a' + 1]--;
    }
    cout << "Yes\n";
    for(int i = 1; i <= k; ++i) s[i] = s[n - i + 1];
    for(int i = 1; i <= n; ++i) cout << s[i];
    cout << '\n';
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> Q;
    for(int i = 1; i <= Q; ++i) Solve();
}