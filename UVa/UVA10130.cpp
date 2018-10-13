#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
int n;
int s;
vector<int> v;
vector<int> w;
int dp[1005][105];

int knapsack(int peso,int pos){
	if(pos >= n || peso < 0)
		return 0;
	if(dp[pos][peso] != -1)
		return dp[pos][peso];
	int res;
	if(peso < w[pos])
		res= knapsack(peso,pos+1);
	else
		res=max(v[pos]+knapsack(peso-w[pos],pos+1),knapsack(peso,pos+1));
	dp[pos][peso]=res;
	return dp[pos][peso];
}

int bottomUpDP(int W){
        //int dp[][] = new int[n+1][s+1];
        for(int i=0; i <= n; i++){
            for(int j=0; j <= s; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                if(j - w[i-1] >= 0){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][s];
    }

void matrizClear(){
	for (int i = 0; i < 1005; ++i)
	{
		for (int j = 0; j < 105; ++j)
		{
			//cout << dp[i][j] << " ";
			dp[i][j]=-1;
		}
		//cout << "\n";
	}
}

int main(){
	int t;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		v.resize(n);
		w.resize(n);
		for (int i = 0; i < n; ++i){
			cin >> v[i] >> w[i];
		}
		int m;
		lli res=0ll;
		cin >> m;
		while(m--){
			matrizClear();
			cin >> s;
			//int aux=knapsack(s-1,0,0);
			int aux= knapsack(s,0);
			//cout << "Para " << s << " el res es de " << aux <<endl;
			res+= aux;
			
		}
		cout << res << endl;	
	}
	return 0;
}