#include <bits/stdc++.h>
using namespace std;
int n,a,b,res,cnt;
int main(){
	cin >> n;
	while(n--){
		cin >> a  >> b;
		cnt=cnt-a+b;
		res=max(res,cnt);
	}
	cout << res;
}
