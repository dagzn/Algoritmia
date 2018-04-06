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
		if(v< adj.size()){
			adj[u].push_back(v);
			if(undirected)
				adj[v].push_back(u);
		}
	}

	int isBipartite(){
		unordered_set<int> used;
		vector<int> color(adj.size(),0);
		int resultado=0;
		bool bipartite=true;
		//unordered_set<int> red,blue;
		for (int u = 0; u < adj.size(); ++u)
		{
			
			if(!used.count(u)){
				int red =1,blue=0;
				used.insert(u);
				queue<int> q;
				q.push(u);
				bool bipartite=true;
				while(!q.empty()){
					int w = q.front();
					q.pop();
					for (int v : adj[w]){
						if(!used.count(v)){
							color[v] = !color[w];
							if(!color[v])
								red++;
							else
								blue++;
							q.push(v);
							used.insert(v);
						}
						if(color[v] == color[w])
							bipartite=false;
					}
				}
				if(bipartite)
					resultado+=max(red,blue);	
			}	
		}
		return resultado;
	}
};

int main(){
	int t,n,m,u,v;
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int i = 0; i < t; ++i){
		cin >> n;
		Graph *g = new Graph(true,n);
		for (int j = 0; j < n; ++j){
			cin >> m;
			for (int k = 0; k < m; ++k){
				cin >> u;
				//if(u-1 < n)
				g->addEdge(j,u-1);
			}
		}
		cout << g->isBipartite() << "\n";
	}
	return 0;
}