#include <bits/stdc++.h>
using namespace std;


pair<int,int> p;
int area,maxi=0,n,m;
bool notThere=true;
char land;

bool canGo(int i,int j,vector<string> &adj,vector<vector<int>> &pos){
	if(i < 0 || i >= n || j < 0 || j >= m)
		return false;
	if(pos[i][j] || adj[i][j] != land)
		return false;
	return true;
}
void dfsvisit(int a,int b,vector<string> &adj,vector<vector<int>> &pos){
	if(a == p.first && b == p.second)
		notThere = false;
	pos[a][b]=1;
	area++;
	if(canGo(a+1,b,adj,pos)){
		dfsvisit(a+1,b,adj,pos);
	}
	if(canGo(a-1,b,adj,pos)){
		dfsvisit(a-1,b,adj,pos);
	}
	if(canGo(a,b+1,adj,pos)){
		if(b+1 == adj[a].size())
			dfsvisit(a,0,adj,pos);
		else
			dfsvisit(a,b+1,adj,pos);
	}
	if(canGo(a,b-1,adj,pos)){
		if(b-1 < 0)
			dfsvisit(a,adj[a].size()-1,adj,pos);
		else
			dfsvisit(a,b-1,adj,pos);
	}
}

void dfs(vector<string> &adj,vector<vector<int>> &pos){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(adj[i][j] == land && !pos[i][j]){
				dfsvisit(i,j,adj,pos);
				if(area > maxi && notThere)
					maxi = area;
				area =0;
				notThere=true;
			}
		}
	}
	cout << maxi << "\n";
}
int main(){
	//int n,m;
	ios_base::sync_with_stdio(0);
	string s;
	while(cin >> n >> m){
		vector<string> adj(n);
		//area.resize(n);
		vector<int> aux(m,0);
		vector<vector<int>> pos(n,aux);
		//pos.resize(n,aux);
		for (int i = 0; i < n; ++i){
			cin >> s;
			adj[i]=s;
		}
		cin >> p.first >> p.second;
		land= adj[p.first][p.second];
		dfs(adj,pos);
		area=0;
		maxi=0;
		notThere=true;
	}
	
	return 0;
}