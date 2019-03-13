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
	vector<int> dist;
	int N;
	Graph(int n){
		adj.resize(n);
		dist.resize(n,INF);
		N = n;
	}
	
	void addEdge(int u,int v,int w){
		adj[u].push_back(CostoNodo(w,v));
	}
	
	bool BellmanFerrari(int s) {
	  	queue<int> q;
	  	vector<bool> en_cola(N);
	  	vector<int> procesado(N);
	  	vector<int> anteriores;
	  	for( int i = 0; i < N; i++ ) 
	  		dist[i] = INF;
	  	q.push(s), dist[s] = 0;
	  	while (!q.empty()) {
	    	int u = q.front();
	    	q.pop(), en_cola[u] = false;
	    	procesado[u]++; 
	    	if (procesado[u] == N){ 
	    		anteriores = dist;
	    	}
	    	else{
	    		if(procesado[u] == 2*N){
	    			for (int i = 0; i < N; ++i){
	    				if(anteriores[i] != dist[i])
	    					dist[i]=0;
	    			}
	    			return true;
	    		}
	    	}

	    	for (CostoNodo arista : adj[u]) {
		      	int v = arista.second;
		      	Costo p = arista.first;
		      	if (dist[u] + p < dist[v]) {
		        	if (!en_cola[v]){
		        		q.push(v);
		        		en_cola[v] = true;
		        	} 
		        	dist[v] = dist[u] + p;
		      	}
	    	}
	  	}
	  	return false;
	}
	
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,n,m,u,v,w,q,k=0;
	while(cin >> n){
		cout << "Set #" << k+1 <<"\n";
		Graph *g = new Graph(n);
		vector<int> costos(n);
		for (int i = 0; i < n; ++i){
			cin >> u;
			costos[i]=u;
		}
		
		cin >> m;
		for (int i = 0; i < m; ++i){
			cin >> u >> v;
			u--;
			v--;
			int aux = costos[v]-costos[u];
			aux = aux*aux*aux;
			//cout << "El costo del source es de " << costos[u] << endl;
			//cout << "El costo del destino es de " << costos[v] << endl;
			//cout << "Arista de " << u << " a " << v << " tiene peso de " << aux << endl;
			g->addEdge(u,v,aux);
		}
		//g->BellmanFerrari(0);
		g->BellmanFerrari(0);
		cin >> q;
		//vector<int> query(q);
		//cout << "El infinito es de " << INF << endl;
		for (int i = 0; i < q; ++i){
			cin >> u;
			u--;
			if(g->dist[u] < 3 || g->dist[u] >= INF )
				cout << "?\n";
			else
				cout << g->dist[u] << "\n";
		}
		k++;
	}
	return 0;
}