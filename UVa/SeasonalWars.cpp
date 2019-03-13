#include <bits/stdc++.h>
using namespace std;
vector<string> adj;

int eagles=0,n,m;

bool canGo(int i,int j,vector<vector<int>> &pos){
	if(i < 0 || i >= n || j < 0 || j >= n)
		return false;
	if(pos[i][j] || adj[i][j] == '0')
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
		for (int j = 0; j < n; ++j){
			if(adj[i][j] == '1' && !pos[i][j]){	
				//cout << "es un arroba \n";
				dfsvisit(i,j,adj[i][j],pos);
				eagles++;	
			}
		}
	}
	//cout << eagles << "\n";
}
int main(){
	//int n,m;
	ios_base::sync_with_stdio(0);
	string s;
	int cont=0;
	//cin >> t;
	while(cin >> n)
	{
		cont++;
		adj.resize(n);
		vector<int> aux(n,0);
		//pos.resize(n,aux);
		vector<vector<int>> pos(n,aux);
		for (int j = 0; j < n; ++j){
			cin >> s;
			adj[j]=s;
		}
		//cin >> p.first >> p.second;
		dfs(pos);
		cout << "Image number " << cont << " contains "<<eagles << " war eagles.\n";
		eagles=0;
	}
	
	return 0;
}