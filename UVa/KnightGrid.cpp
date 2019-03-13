#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
bool check(int i,int j, vector<vector<bool>> &adj,int r,int c){
	if(i >= r || j >= c || i < 0 || j < 0)
		return false;
	if(adj[i][j])
		return false;
	return true;
}

pii knights(vector<vector<bool>> &adj,int r,int c,int m, int n){
	int even=0,odd=0;
	vector<pii> combinations={
		{m,n},{m,-n},
		{-m,n},{-m,-n},
		{n,m},{n,-m},
		{-n,m},{-n,-m}
	};
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			if(adj[i][j])
				continue;
			
			int res=0;
			for (pii p : combinations){
				if(check(i+p.first,j+p.second,adj,r,c))
					res++;
			}
			if(res == 0)
				continue;
			if(res%2 == 0)
				even++;
			else
				odd++;
		}
	}
	return pii(even,odd);
}
int main(){
	int t;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int r,c,m,n,w,u,v;
		cin >> r >> c >> m >> n;
		cin >> w;
		vector<bool> aux(c,false);
		vector<vector<bool>> adj(r,aux);
		for (int i = 0; i < w; ++i)
		{
			cin >> u >> v;
			adj[u][v]=true;
		}

		pii res= knights(adj,r,c,m,n);
		cout << "Case " << i+1 << ": " << res.first << " " << res.second << "\n";
	}
	

	return 0;
}