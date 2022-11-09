#define console(...) 20221109 /*20:06:21*/
#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
const ll inf = 2e18, mod = 1e9 + 7, LOG = 32, maxN = 200005;

#define x first
#define y second

struct cmp {
    template<class T> bool operator() (const T& u, const T& v) const {
        return u.x + u.y < v.x + v.y;
    }
};

set<pair<int, int>, cmp> S;
signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    S.insert({2, 4});
    S.insert({3, 0});
    for(pair<int, int> i : S) cout << i.x << ' ' << i.y << '\n';  
}