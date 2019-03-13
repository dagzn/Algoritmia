#include <bits/stdc++.h>
using namespace std;
typedef int Costo;
typedef pair<int, int> Arista;
const Costo INF = 1 << 30;
typedef pair<Costo, int> CostoNodo;
typedef pair<Costo, Arista> Ponderada;

class Graph
{
public:
	vector<vector<CostoNodo>> adj;
	vector<int> dst;
	int N;
	Graph(int n){
		adj.resize(n);
		dst.resize(n,INF);
		N = n;
	}
	
	void addEdge(int u,int v,int w){
		adj[u].push_back(CostoNodo(w,v));
	}

	bool BellmanFerrari(int s) {
	  queue<int> q;
	  vector<bool> en_cola(N);
	  vector<int> procesado(N);
	  for( int i = 0; i < N; i++ ) dst[i] = INF;
	  q.push(s), dst[s] = 0;
	  while (!q.empty()) {
	    int u = q.front();
	    q.pop(), en_cola[u] = false;
	    if (++procesado[u] == N) return true;
	    for (CostoNodo arista : adj[u]) {
	      int v = arista.second;
	      Costo p = arista.first;
	      if (dst[u] + p < dst[v]) {
	        if (!en_cola[v]) q.push(v);
	        dst[v] = dst[u] + p;
	        en_cola[v] = true;
	      }
	    }
	  }
	  return false;
	}
	
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,n,m,u,v,w;
	cin >> t;
	for (int k = 0; k < t; ++k){
		cin >> n >> m;
		Graph *g = new Graph(n);
		for (int i = 0; i < m; ++i){
			cin >> u >> v >> w;
			g->addEdge(u,v,w);
		}
		if(n == 1 && m == 0)
			cout << "not possible\n";
		else{
			if(g->BellmanFerrari(0))
				cout << "possible\n";
			else
				cout << "not possible\n";
		}
	}
	return 0;
}