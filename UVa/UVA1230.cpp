#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;


lli exp(lli x,lli y,lli m){
	lli res =1ll;
	while(y > 0){
		if(y & 1)
			res = (res*x)%m;
		y >>= 1;
		x=(x*x)%m;
	}
	return res;
}

int main(){
	int t;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		lli x,y,m;
		cin >> x >> y >> m;
		cout << exp(x,y,m) << endl;
	}
	return 0;
}
