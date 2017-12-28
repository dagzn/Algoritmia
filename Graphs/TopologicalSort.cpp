#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	bool undirected;
	vector<vector<int>> adj;
	vector<int> checked;
	stack<int> s;

	Graph(bool undirected,int n){
		this->undirected = undirected;
		adj.resize(n);
		checked.resize(n);
	}

	void addEdge(int u, int v){
		adj[u].push_back(v);
		if(undirected)
			adj[v].push_back(u);
	}

	void dfs(int u){
		cout << "Visiting: " << u+1 << endl;
		checked[u] = true;
		for (int v = 0; v < adj[u].size(); ++v)
		{
			if(!checked[adj[u][v]])
				dfs(adj[u][v]);		
		}
		s.push(u);
	}

	stack<int> topological(){
		//dfsvisit(rand()%8);
		for (int i = 0; i < adj.size(); ++i){
			if(!checked[i])
				dfs(i);
		}
		return s;
	}
	
};

int main(){
	char aux;

	Graph *g = new Graph(false,8);
	g->addEdge(0,2);
	g->addEdge(1,2);
	g->addEdge(1,3);
	g->addEdge(2,4);
	g->addEdge(3,5);
	g->addEdge(4,5);
	g->addEdge(5,6);
	g->addEdge(4,7);

	stack<int> s = g->topological();
	
	while(!s.empty()){
		aux = (char) (s.top()+65);
		cout << aux << endl;
		s.pop();
	}
	return 0;
}
