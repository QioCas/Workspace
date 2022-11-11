#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;

ll inv(ll a, ll b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
