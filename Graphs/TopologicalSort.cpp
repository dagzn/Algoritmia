#include <bits/stdc++.h>
using namespace std;

bool undirected;
vector<vector<int>> adj;
vector<bool> checked;
stack<int> s;


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

void dfsvisit(int u){
	cout << "Visiting: " << u+1 << endl;
	checked[u] = true;
	for (int v = 0; v < adj[u].size(); ++v)
	{
		if(!checked[adj[u][v]])
			dfsvisit(adj[u][v]);		
	}
	s.push(u);
}

void dfs(){
	dfsvisit(rand()%8);
	for (int i = 0; i < adj.size(); ++i){
		if(!checked[i])
			dfsvisit(i);
	}
}



int main(){
	initialize(8,false);
	addEdge(0,2);
	addEdge(1,2);
	addEdge(1,3);
	addEdge(2,4);
	addEdge(3,5);
	addEdge(4,5);
	addEdge(5,6);
	addEdge(4,7);
	dfs();
	char aux;
	while(!s.empty()){
		aux = (char) (s.top()+65);
		cout << aux << endl;
		s.pop();
	}
	return 0;
}
