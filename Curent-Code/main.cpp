#pragma GCC optimize("unroll-loops,02,no-stack-protector")
#include "bits/stdc++.h" // QioCas
#define int long long
#define pii pair <int,int> 
#define x first
#define y second
using namespace std;
int n , m;
int a[1003][1003];
map <int , bool> check;
vector < vector <int> > dp(1003 , vector <int> (1003 , 1e9));
int dx[] = {0 , 1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 0 , 1 , -1};
map <int , vector <pii> > same;
pii start , finish;

struct Point { 
    int val; pii p;
    Point(int _val , pii _p) : val(_val), p(_p) {};
};
struct cmp {
    bool operator () (Point &u, Point &v) {
        return u.val > v.val or (u.val == v.val and u.p > v.p);
    } 
};
signed main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> m >> n;
    cin >> start.x >> start.y >> finish.x >> finish.y;
    for(int i = 1; i <= m; ++i) 
        for(int j = 1; j <= n; ++j) cin >> a[i][j] , same[a[i][j]].push_back({i,j});
    dp[start.x][start.y] = 0;
    priority_queue <Point , vector <Point> , cmp > Q;
    Q.emplace(0,start);
    while(Q.size()) {
        pii u = Q.top().p; Q.pop();
        if(u == finish) break;
        for(int i = 1; i <= 4; ++i) {
            int x = u.x + dx[i];
            int y = u.y + dy[i];
            if(x < 0 or y < 0 or x > m or y > n or a[x][y] == 0) continue;
            if(dp[x][y] > dp[u.x][u.y] + 1)
                Q.emplace(dp[x][y] = dp[u.x][u.y] + 1,pii(x,y));
        }
        if(check[a[u.x][u.y]]) continue;
        check[a[u.x][u.y]] = true;
        for(pii v : same[a[u.x][u.y]])
            if(dp[v.x][v.y] > dp[u.x][u.y] + 1) 
                Q.emplace(dp[v.x][v.y] = dp[u.x][u.y] + 1 , pii(v.x,v.y));
    }
    cout << dp[finish.x][finish.y];
}