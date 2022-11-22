#include <bits/stdc++.h>
using namespace std;
const int oo = 1e5+7;
#define N 100000
int n,Q[oo],S[oo],a[oo],L,R,T;
bool Prime[oo];
void Enter(){
    scanf("%d",&n);
    for(int i=1,r;i<=n;++i) scanf("%d",&r) , a[r]++;
}
void Eratos(){
    fill(Prime+2,+Prime+N+1,true);
    for(int i=2;i<=N;++i) if(Prime[i]){
        if(a[i]) Q[i]+=a[i];
        for(int j=i+i;j<=N;j+=i){
                Prime[j]=false;
                if(a[j]) Q[i]+=a[j];
            }
    }
}

void Set(){
    for(int i=2;i<=N;++i)
        S[i]=S[i-1]+Q[i];
}

void Process(){
    scanf("%d%d",&L,&R);
    if(R>N) R=N;
    printf("%d\n",S[R]-S[L-1]);
}
//void Test(){
//    for(int i=2;i<=100;++i)
//        printf("%d\t",S[i]);
//}
int main(){
    freopen("PRIME.inp","r",stdin);
    freopen("PRIME.out","w",stdout);
    Enter();
    Eratos();
    Set();
    scanf("%d",&T);
    while(T--) Process();
    //Test();
}
