#include <bits/stdc++.h>

using namespace std;
long long  n, a[4][3007], A, B, C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++)
            cin >> a[j][i];
    for (int i = 1 ; i <= n ; i++)
        A += a[1][i] , B += (a[2][i] - i + 1) , C += (a[3][i] - i + 1);
    cout << min({A , B , C});
    return 0;
}
