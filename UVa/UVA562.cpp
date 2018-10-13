#include <bits/stdc++.h>
using namespace std;
int m,total=0;
int mon[100];
int tabla[100][50001];

int dp(int pos,int sum){
	if(pos == m)
		return abs(sum-(total-sum));
	if(tabla[pos][sum] !=-1)
		return tabla[pos][sum];
	tabla[pos][sum] = min(dp(pos+1,sum+mon[pos]),dp(pos+1,sum));
	return tabla[pos][sum];
}
void iniciar(){
	total=0;
		for (int i = 0; i < 100; ++i){
			mon[i]=0;
			for (int j = 0; j < 50001; ++j){
				tabla[i][j]=-1;
			}
		}
}
int main(){
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while(n--){
		iniciar();
		cin >> m;
		//vector<int> mon(m,0);
		for (int i = 0; i < m; ++i){
			cin >> mon[i];
			total+=mon[i];		
		}
		//vector<vector<int>> tabla(m,vector<int>(total,0));
		cout << dp(0,0) << endl;	
	}
	
	return 0;
}