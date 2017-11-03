#include <bits/stdc++.h>
using namespace std;

bool undirected;
vector<string> vertices;
vector<vector<int>> adj;


void initialize(int n, bool u){
	adj.resize(n);
	vertices.resize(n,"white");
	undirected = u;
}

void addEdge(int u, int v){
	adj[u].push_back(v);
	if(undirected)
		adj[v].push_back(u);
}

bool dfsvisit(int u){
	vertices[u] = "grey";
	for (int i = 0; i < adj[u].size(); ++i)
	{
		if(vertices[adj[u][i]] == "black")
			continue;
		if(vertices[adj[u][i]] == "grey")
			return true;
		if(dfsvisit(adj[u][i]))
			return true;
	}
	vertices[u] = "black";
	return false;
}

bool dfs(){
	for (int i = 0; i < adj.size(); ++i){
		if(vertices[i] == "white"){
			if(dfsvisit(i))
				return true;
		}
	}
	return false;
}

int main(){
	initialize(6,false);
	addEdge(0,1);
	addEdge(0,2);
	addEdge(0,3);
	addEdge(1,2);
	addEdge(3,4);
	addEdge(4,5);
	addEdge(5,3);
	if(dfs())
		cout << "Has a cycle \n";
	else
		cout << "Doesnt have a cycle\n";
	return 0;
}