#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
	vector<vector<int>> adj;
	int max=-1;
	int nodoMax=-1;
	unordered_set<int> visited;

	Graph(int n){
		adj.resize(n);
	}

	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void dfsvisit(int u, int d){
		visited.insert(u);
		if(d > max){
			max=d;
			nodoMax=u;
		}
		for (int v : adj[u]){
			if(!visited.count(v))
				dfsvisit(v,d+1);
		}
	}

	int dfs(int w,bool first){
		visited.clear();
		if(first){
			dfsvisit(w,0);
			return nodoMax;
		}
		else{
			max=-1;
			nodoMax=-1;
			dfsvisit(w,0);
			return max;
		}
	}
	
};
int main(){
	int n,m,u,v;
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	Graph *g = new Graph(n);
	for (int i = 0; i < n-1; ++i)
	{
		cin >> u >> v;
		g->addEdge(u-1,v-1);
	}
	int nodo = g->dfs(0,true);
	cout << g->dfs(nodo,false) << endl;
	return 0;
}