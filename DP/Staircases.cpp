#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli staircases(lli k, lli a, vector<vector<lli>> &adj){
	if(k == 0)
		return 1;
	if(k <= a){
		//cout << "k es menor a A: " << k << " " << a <<"\n";
		return 0;
	}
	if(adj[k][a] != 0)
		return adj[k][a];
	for (lli i = 1; i < k; ++i){
		if(k-a-i < 0)
			break;
		//cout <<"Mando recursiva con k " << k-a-i << " y con a " << a+i << "\n";

		adj[k][a]+=staircases(k-a-i,a+i,adj);
	}
	return adj[k][a];
}
int main(){
	lli n;
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	cin >> n;
	vector<lli> aux(n+5,0);
	vector<vector<lli>> adj(n+5,aux);
	lli res=0;
	for (lli i = 1; i <= n/2; ++i)
	{
		//cout << "Desde main mandamos a k con " << n-i << " y a A con " << i << endl;
		res+=staircases(n-i,i,adj);
	}
	cout << res ;
	return 0;
}