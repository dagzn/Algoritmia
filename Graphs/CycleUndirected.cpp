#include <bits/stdc++.h>
using namespace std;

bool undirected;
vector<vector<int>> adj;
vector<bool> checked;

void initialize(int n, bool u){
	adj.resize(n);
	checked.resize(n,false);
	undirected = u;
}

void addEdge(int u, int v){
	adj[u].push_back(v);
	if(undirected)
		adj[v].push_back(u);
}

bool dfsvisit(int u, int parent){
	checked[u] = true;
	for (int v = 0; v < adj[u].size(); ++v)
	{
		if(adj[u][v] == parent){
			continue;
		}
		if(checked[adj[u][v]]){
			return true;
		}
		if(dfsvisit(adj[u][v],u)){
			return true;
		}
	}
	return false;
}

bool dfs(){
	for (int i = 0; i < adj.size(); ++i)
	{
		if(!checked[i]){
			if(dfsvisit(i,6)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	initialize(6,true);
	addEdge(0,1);
	addEdge(0,5);
	addEdge(1,2);
	addEdge(1,4);
	addEdge(2,3);
	addEdge(3,4);
	if(dfs())
		cout << "Tiene un ciclo \n";
	else
		cout << "No hay un ciclo\n";
	return 0;
}
