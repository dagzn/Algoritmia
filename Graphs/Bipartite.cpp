#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	bool undirected;
	vector<vector<int>> adj;

	Graph(bool undirected,int n){
		this->undirected=undirected;
		adj.resize(n);
	}

	void addEdge(int u, int v){
		adj[u].push_back(v);
		if(undirected)
			adj[v].push_back(u);
	}

	bool isBipartite(){
		unordered_map<int,int> color;
		for (int u = 0; u < adj.size(); ++u)
		{
			if(!color.count(u)){
				color[u]=0;
				queue<int> q;
				q.push(u);
				while(!q.empty()){
					int w = q.front();
					q.pop();
					for (int v : adj[w]){
						if(!color.count(v)){
							color[v] = !color[w];
							q.push(v);
						}
						if(color[v] == color[w])
							return false;
					}
				}
			}
		}
		return true;
	}
};

int main(){
	Graph *g = new Graph(true,4);
	g->addEdge(0,1);
	g->addEdge(1,2);
	g->addEdge(2,3);
	g->addEdge(3,0);
	if(g->isBipartite())
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}