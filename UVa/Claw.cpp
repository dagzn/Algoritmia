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
	int n,m,u,v;
	while(cin >> n){
		if(n == 0)
			break;
		Graph *g = new Graph(true,n);
		while(cin >> u >> v){
			if(!u && !v)
				break;
			g->addEdge(u-1,v-1);
		}
		if(g->isBipartite())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}