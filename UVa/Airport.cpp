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
	vector<vector<int>> adj;
 	int n;
 	
	Graph(int n){
		adj.resize(n);
		this->n =n;
	}
	
	void addEdge(int u, int v){
		adj[u].push_back(v);
	}
	// Algoritmo de dijkstra desde el nodo s.
	// Devuelve el vector de distancias a todos
	// los nodos desde s. Un valor INF indica que
	// no es posible ir de s al respectivo nodo.
	int Dijkstra(int s,int d,unordered_set<int> &a) {
		vector<Costo> dist(n, INF);
		priority_queue<CostoNodo> pq;
		dist[s] = 0;
		if(!a.count(s))
			dist[s]++;
		pq.push(CostoNodo(dist[s], s));
		int weight;
		while (!pq.empty()) {
			Costo p = -pq.top().first;
			int u = pq.top().second; 
			pq.pop();

			if (dist[u] < p) 
				continue;

			for (int v : adj[u]) {
				//int v = arista.second;
				if(!a.count(v))
					weight=1;
				else
					weight=0;
				p = dist[u] + weight;
				if (p < dist[v]) dist[v] = p,
				pq.push(CostoNodo(-p, v));
			}
		}
		if(dist[d] >= INF)
			return -1;
		return dist[d];
	}


};


int main(){
	int t,n,m,q,u,v,k,cont=1;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m >> k ;
		Graph *g = new Graph(n);
		unordered_set<int> air;
		for (int i = 0; i < k; ++i){
			cin >> u;
			u--;
			air.insert(u);
		}
		for (int i = 0; i < m; ++i){
			cin >> u >> v;
			u--;
			v--;
			g->addEdge(u,v);
			g->addEdge(v,u);
		}
		cin >> q;
		cout << "Case " <<cont << ":\n";
		for (int i = 0; i < q; ++i){
		 	cin >> u >> v;
		 	u--,v--;
		 	if(u == v)
		 		cout << "0\n";
		 	else{
		 		int res = g->Dijkstra(u,v,air);
			 	cout << res << "\n";
		 	}
		} 
		cout << "\n";
		cont++;
	}	
	return 0;
}