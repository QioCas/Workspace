#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool P[1000007];
ll Q[1000006],r=0;
int T,n;
void eratos(){
    fill(P,P+1000001,true);
    for(ll i=2;i<=1000000;++i){
        if(P[i]) Q[r+1]=Q[r]+i,r++;
        for(ll j=i*i;j<=1000000;j+=i)
        P[j]=false;
    }
}
void Process(){
    cin >> n;
    cout << Q[n]<<"\n";
}
int main(){
    freopen("nguyento.inp","r",stdin);
    freopen("nguyento.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    eratos();
    cin >> T;
    while(T--) Process();
}
