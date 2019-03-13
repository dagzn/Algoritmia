#include <bits/stdc++.h>
using namespace std;


class Graph
{
public:
	bool undirected;
	vector<vector<int>> adj;
	vector<string> vertices;
	vector<bool> checked;
	stack<int> s;

	Graph(bool undirected,int n){
		adj.resize(n);
		vertices.resize(n,"white");
		checked.resize(n,false);
		this->undirected = undirected;
	}

	void addEdge(int u, int v){
		adj[u].push_back(v);
		if(undirected)
			adj[v].push_back(u);
	}

private:

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

	bool hasCycle(){
		for (int i = 0; i < adj.size(); ++i)
		{
			if(vertices[i] == "white"){
				if(dfsDirected(i))
					return true;
			}
		}
		return false;
	}


	void dfs(int u){
		//cout << "Visiting: " << u+1 << endl;
		checked[u] = true;
		for (int v = 0; v < adj[u].size(); ++v)
		{
			if(!checked[adj[u][v]])
				dfs(adj[u][v]);		
		}
		s.push(u);
	}
public:
	void topological(){
		if(!hasCycle()){
			for (int i = 0; i < adj.size(); ++i){
				if(!checked[i])
					dfs(i);
			}
			while (!s.empty()){
				cout << s.top()+1 << "\n";
				s.pop();
			}
		}
		else{
			cout << "IMPOSSIBLE\n";
		}
	}
};

int main(){
	int n,m,u,v;
	ios_base::sync_with_stdio(0);
	while(cin >> n >> m){
		if(n == 0 && m == 0)
			break;
		Graph *g = new Graph(false,n);
		for (int i = 0; i < m; ++i){
			cin >> u >> v;
			g->addEdge(u-1,v-1);
		}
		g->topological();
	}
	
	return 0;
}

