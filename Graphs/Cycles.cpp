#include <bits/stdc++.h>
using namespace std;


class Graph
{
public:
	bool undirected;
	vector<vector<int>> adj;
	vector<string> vertices;
	vector<bool> checked;

	Graph(bool undirected,int n){
		adj.resize(n);
		if(undirected)
			checked.resize(n,false);
		else
			vertices.resize(n,"white");
		this->undirected = undirected;
	}

	void addEdge(int u, int v){
		adj[u].push_back(v);
		if(undirected)
			adj[v].push_back(u);
	}

private:
	bool dfsUndirected(int u, int parent){
		checked[u] = true;
		for (int v = 0; v < adj[u].size(); ++v)
		{
			if(adj[u][v] == parent){
				continue;
			}
			if(checked[adj[u][v]]){
				return true;
			}
			if(dfsUndirected(adj[u][v],u)){
				return true;
			}
		}
		return false;
	}

	bool dfsDirected(int u){
		vertices[u] = "grey";
		for (int i = 0; i < adj[u].size(); ++i)
		{
			if(vertices[adj[u][i]] == "black")
				continue;
			if(vertices[adj[u][i]] == "grey")
				return true;
			if(dfsDirected(adj[u][i]))
				return true;
		}
		vertices[u] = "black";
		return false;
	}
public:
	bool dfs(){
		for (int i = 0; i < adj.size(); ++i)
		{
			if((!checked[i] && undirected)){
				if(dfsUndirected(i,-1)){
					return true;
				}
			}
			else if(vertices[i] == "white" && !undirected){
				if(dfsDirected(i))
					return true;
			}
		}
		return false;
	}
	
};

int main(){
	Graph *g = new Graph(true,6);
	g->addEdge(0,1);
	g->addEdge(0,5);
	g->addEdge(1,2);
	g->addEdge(1,4);
	g->addEdge(2,3);
	g->addEdge(3,4);
	if(g->dfs())
		cout << "Tiene un ciclo \n";
	else
		cout << "No hay un ciclo\n";
	return 0;
}


