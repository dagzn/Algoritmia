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

	int isBipartite(){
		vector<int> color(adj.size(),0);
		unordered_set<int> used;
		int resultado=0;
		int solitos=0;
		for (int u = 0; u < adj.size(); ++u)
		{
			int red=1,blue=0;
			if(!used.count(u)){
				used.insert(u);
				if(adj[u].size() == 0){
					solitos++;
				}
				else{
					queue<int> q;
					q.push(u);
					while(!q.empty()){
						int w = q.front();
						q.pop();
						for (int v : adj[w]){
							if(!used.count(v)){
								color[v] = !color[w];
								if(!color[v]){
									//cout << "insertamos en rojo a " << v << endl;
									red++;
									//red.insert(v);
								}
								else{
									//cout << "insertamos en azul a " << v << endl;
									blue++;
									//blue.insert(v);
								}
								q.push(v);
								used.insert(v);
							}
							if(color[v] == color[w])
								return -1;
						}
					}
					resultado += min(red,blue);
				}
			}
		}
		resultado+=solitos;
		return resultado;
	}
};

int main(){
	int t,n,m,u,v;
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int i = 0; i < t; ++i){
		cin >> n >> m;
		Graph *g = new Graph(true,n);
		for (int j = 0; j < m; ++j){
			cin >> u >> v;
			g->addEdge(u,v);
		}
		cout << g->isBipartite() << "\n";
	}
	return 0;
}