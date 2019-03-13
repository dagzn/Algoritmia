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
	
	bool undirected;
	vector<vector<CostoNodo>> adj;
 	int n;
 	

	Graph(bool undirected,int n){
		adj.resize(n);
		this->n =n;
		this->undirected = undirected;
	}
	
	void addEdge(int u, int v,int w){
		adj[u].push_back(CostoNodo(w,v));
		if(undirected)
			adj[v].push_back(CostoNodo(w,u));
	}
	// Algoritmo de dijkstra desde el nodo s.
	// Devuelve el vector de distancias a todos
	// los nodos desde s. Un valor INF indica que
	// no es posible ir de s al respectivo nodo.
	void Dijkstra(int s,int e) {
		vector<Costo> dist(n, INF);
		priority_queue<CostoNodo> pq;
		pq.push(CostoNodo(0, s)), dist[s] = 0;
		while (!pq.empty()) {
			Costo p = -pq.top().first;
			int u = pq.top().second; pq.pop();
			if (dist[u] < p) continue;
			for (CostoNodo arista : adj[u]) {
				int v = arista.second;
				p = dist[u] + arista.first;
				if (p < dist[v]) dist[v] = p,
				pq.push(CostoNodo(-p, v));
			}
		}
		if(dist[e] < INF)
			cout << dist[e] << "\n";
		else
			cout << "unreachable\n";
		//return dist[e];
	}


};


int main(){
	int t,n,m,s,e,u,v,w,cont=1;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m >> s >> e;
		Graph *g = new Graph(true,n);
		for (int i = 0; i < m; ++i){
			cin >> u >> v >> w;
			g->addEdge(u,v,w);
		}
		cout << "Case #" <<cont << ": "; 
		g->Dijkstra(s,e);
		cont++;
	}	
	return 0;
}