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
	  for( int i = 0; i < N; i++ ) 
	  	dst[i] = INF;

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
	int n,c,e,u,contador=1;
	while(true){
		cin >> n;
		if(n == -1)
			break;
		Graph *g = new Graph(n);
		vector<Arista> aristas;
		vector<int> energy(n);
		for (int i = 0; i < n; ++i){
			cin >> e >> c;
			energy[i]=e;
			for (int j = 0; j < c; ++j){
				cin >> u;
				u--;
				aristas.push_back(Arista(i,u));
			}
		}
		for (int i = 0; i < aristas.size(); ++i){
			Arista a = aristas[i];
			g->addEdge(a.first,a.second,-energy[a.second]);
			//g->addEdge(a.second,a.first,energy[a.first]);
		}
		bool ciclo =g->BellmanFerrari(0);
		int distancia = (g->dst[n-1]);
		if(ciclo){
			cout << "CICLO\n";
		}
		else{
			//cout << distancia << endl;
			if(100 - distancia > 0)
				cout << "winnable\n";
			else
				cout << "hopeless\n";
			//cout << distancia << endl;
		}
	}
	return 0;
}