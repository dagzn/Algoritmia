#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int dp[100][2];

lli ktree(int w,int k,int d,int used){
	if(w < d && !used)
		return 0ll;
	if(w < 0)
		return 0ll;
	if(w == 0 && used)
		return 1ll;
	if(dp[w][used] != 0ll)
		return dp[w][used];
	lli res=0;
	for (int i = 1; i <= k; ++i){
		if(i >= d || used)
			res+=ktree(w-i,k,d,1)%1000000007;
		else
			res+=ktree(w-i,k,d,0)%1000000007;
	}
	return dp[w][used]=res%1000000007;
}

int main(){
	int n,k,d;
	cin >> n >> k >> d;
	cout << ktree(n,k,d,0);
	return 0;
}