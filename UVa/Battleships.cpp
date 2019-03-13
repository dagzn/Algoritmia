#include <bits/stdc++.h>
using namespace std;
vector<string> adj;

int ships=0,t,n;
bool sunk=true;

bool canGo(int i,int j,vector<vector<int>> &pos){
	if(i < 0 || i >= n || j < 0 || j >= n)
		return false;
	if(pos[i][j] || adj[i][j] == '.')
		return false;
	return true;
}
void dfsvisit(int a,int b, char c,vector<vector<int>> &pos){
	//cout << "kheberga\n";
	if(c == 'x'){
		//cout << "its an x\n";
		sunk = false;
	}
	pos[a][b]=1;
	if(canGo(a+1,b,pos)){
		//cout << "can go down\n";
		dfsvisit(a+1,b,adj[a+1][b],pos);
	}
	if(canGo(a-1,b,pos)){
		//cout << "can go up\n";
		dfsvisit(a-1,b,adj[a-1][b],pos);
	}
	if(canGo(a,b+1,pos)){
		//cout << "can go right\n";
		dfsvisit(a,b+1,adj[a][b+1],pos);
	}
	if(canGo(a,b-1,pos)){
		//cout << "can go left\n";
		dfsvisit(a,b-1,adj[a][b-1],pos);
	}
}

void dfs(vector<vector<int>> &pos){
	//cout << "khebergisisisisima\n";
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if(adj[i][j] == 'x' || adj[i][j] == '@'){
				if(!pos[i][j]){
					//cout << "kestapasandodrgarcia\n";
					dfsvisit(i,j,adj[i][j],pos);
					if(!sunk)
						ships++;
					sunk=true;
				}
			}
		}
	}
	//cout << ships << "\n";
}
int main(){
	//int n,m;
	//ios_base::sync_with_stdio(0);
	string s;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n;

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
		cout << "Case " << i+1 << ": " << ships << "\n";
		ships=0;
		sunk = true;
	}
	
	return 0;
}