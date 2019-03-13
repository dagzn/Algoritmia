#include <bits/stdc++.h>
using namespace std;
vector<string> adj;

int deposits=0,n,m;

bool canGo(int i,int j,vector<vector<int>> &pos){
	if(i < 0 || i >= n || j < 0 || j >= m)
		return false;
	if(pos[i][j] || adj[i][j] == '*')
		return false;
	return true;
}
void dfsvisit(int a,int b, char c,vector<vector<int>> &pos){
	pos[a][b]=1;
	//cout << "estoy en la pos " << a << " " << b << "\n";
	//NORMALES
	if(canGo(a+1,b,pos)){
		dfsvisit(a+1,b,adj[a+1][b],pos);
	}
	if(canGo(a-1,b,pos)){
		dfsvisit(a-1,b,adj[a-1][b],pos);
	}
	if(canGo(a,b+1,pos)){
		dfsvisit(a,b+1,adj[a][b+1],pos);
	}
	if(canGo(a,b-1,pos)){
		dfsvisit(a,b-1,adj[a][b-1],pos);
	}
	//DIAGONALES
	if(canGo(a+1,b+1,pos)){
		dfsvisit(a+1,b+1,adj[a+1][b+1],pos);
	}
	if(canGo(a+1,b-1,pos)){
		dfsvisit(a+1,b-1,adj[a+1][b-1],pos);
	}
	if(canGo(a-1,b+1,pos)){
		dfsvisit(a-1,b+1,adj[a-1][b+1],pos);
	}
	if(canGo(a-1,b-1,pos)){
		dfsvisit(a-1,b-1,adj[a-1][b-1],pos);
	}
}

void dfs(vector<vector<int>> &pos){
	//cout << "khebergisisisisima\n";
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(adj[i][j] == '@' && !pos[i][j]){	
				//cout << "es un arroba \n";
				dfsvisit(i,j,adj[i][j],pos);
				deposits++;	
			}
		}
	}
	//cout << deposits << "\n";
}
int main(){
	//int n,m;
	//ios_base::sync_with_stdio(0);
	string s;
	//cin >> t;
	while(cin >> n >> m)
	{
		if(!n && !m)
			break;
		adj.resize(n);
		vector<int> aux(m,0);
		//pos.resize(n,aux);
		vector<vector<int>> pos(n,aux);
		for (int j = 0; j < n; ++j){
			cin >> s;
			adj[j]=s;
		}
		//cin >> p.first >> p.second;
		dfs(pos);
		cout << deposits << "\n";
		deposits=0;
	}
	
	return 0;
}