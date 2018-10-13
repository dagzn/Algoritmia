#include <bits/stdc++.h>
using namespace std;
int dp[105][105];

int adding(int num,int k){
	//cout << "Entramos con " << num << " y " << k << endl;
	if(k == 1){
		//cout << "regresamos 1\n";
		return 1;
	}
	if(dp[num][k] != 0)
		return dp[num][k]%1000000;
	for (int i = 0; i <= num; ++i){
		dp[num][k]+=(adding(num-i,k-1))%1000000;
	}
	return dp[num][k]%1000000;
}


int main(){
	int n,k;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//int res=0;
	while(cin >> n >> k){
		if(!n && !k)
			break;
		cout << adding(n,k) << "\n";
	}
	
	return 0;
}