#include <bits/stdc++.h>
using namespace std;

bool undirected;
vector<vector<int>> adj;
vector<bool> checked;
//vector<vector<int>> connected;
vector<int> aux;

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

void dfsvisit(int v){
	checked[v] = true;
	//vector<int> aux;
	for (int i = 0; i < adj[v].size(); ++i){
		if(!checked[adj[v][i]]){
			//aux.push_back(adj[v][i]);
			dfsvisit(adj[v][i]);
		}
	}
}

int dfs(){
	int cont = 0;
	for (int i = 0; i < adj.size(); ++i){
		if(!checked[i]){
			cont++;	
			//aux.push_back(i);
			dfsvisit(i);
			//connected.push_back(aux);
			//aux.clear();
		}
	}
	return cont;
}

int main(){
	
	initialize(5,true);
	addEdge(0,1);
	addEdge(2,4);
	addEdge(1,3);
	
	/*
	initialize(2,true);
	addEdge(0,1);
	*/
	//initialize(3,true);
	cout << "El resultado es: " << dfs() << endl;
	for (int i = 0; i < connected.size(); ++i)
	{
		cout << "Lista " << i+1 << endl;
		for (int j = 0; j < connected[i].size(); ++j)
		{
			cout << connected[i][j] << endl;
		}
	}
	return 0;
}
