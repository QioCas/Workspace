#pragma GCC optimize("unroll-loops,02,no-stack-protector")
#include "bits/stdc++.h" // QioCas
#define int long long
using namespace std;
int n , d;
int a[2000006];
int Sum(int x) {
    return x * (x + 1) / 2LL;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> d; 
    int x; vector <int> Map (2000006 , 0);
    for(int i = 1; i <= n; ++i ) cin >> x , Map[x]++;
    for(int idx = 0, i = 1; i <= 1000000; ++i) 
        while(Map[i]--) a[++idx] = i;
    int ans = 0 , idx = 0;
    for(int i = 3; i <= n; ++i) {
        while(a[i] - a[idx+1] > d) idx++;
        ans += max(0LL , Sum(i - idx - 2));
    }

    cout << ans;
}
