#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long int lli;
class Graph
{
public:
	
	bool undirected;
	vector<vector<int>> adj;
 	vector<int> label, low;
 	int tiempo,n;
 	vector<vector<lli>> scc;
	int top;
	vector<int> pila;
	unordered_map<int,lli> nodoCosto;

	Graph(bool undirected,int n){
		adj.resize(n);
		this->n =n;
		this->undirected = undirected;
	}
	
	void addEdge(int u, int v){
		adj[u].push_back(v);
	}
	//mapeo del nodo con su costo
	void addCosto(int u,lli c){
		nodoCosto[u]=c;
	}

	
	void FuertementeConexo(int u) {
		label[u] = low[u] = ++tiempo;
		pila[++top] = u;
		for (int v : adj[u]) {
			if (!label[v]) 
				FuertementeConexo(v);
			low[u] = min(low[u], low[v]);
		}
		if (label[u] == low[u]) {
			vector<lli> componente;
			while (pila[top] != u) {
				//se introduce el costo del nodo, no el indice del nodo
				componente.push_back(nodoCosto[pila[top]]);
				low[pila[top--]] = n + 1;
			}
			componente.push_back(nodoCosto[pila[top--]]);
			//se hace un sort al vector para siempre agarrar los de valor mas bajo primero
			sort(componente.begin(), componente.end());
			scc.push_back(componente);
			low[u] = n + 1;
		}
	}

	void strong(){
		low.resize(n);
		label.resize(n);
		tiempo=0;
		scc.clear();
		top=-1;
		pila.resize(n);

		for(int u=0; u < n;u++)
			if(!label[u])
				FuertementeConexo(u);

		lli combinaciones = 1;
		lli res=0;
		// Res es para el minimo y combinaciones para las combinaciones posibles con ese res.
		for (int i = 0; i < scc.size(); ++i){
			lli p = 0,j=0;
			lli pasado = scc[i][0];
			// while para saber cuantos elementos hay con valor igual al primero, tambien se puede usar un upper_bound
			p = upper_bound(scc[i].begin(), scc[i].end(),scc[i][0]) - scc[i].begin();
			//la solucion debe ser modulada
			combinaciones= (combinaciones*p) % 1000000007;
			res+=scc[i][0];
		}
		cout << res << " "<<combinaciones << "\n";
	}


};
 



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,u,v;
	lli c;
	cin >> n;
	Graph *g = new Graph(false,n);
	for (int i = 0; i < n; ++i){
		cin >> c;
		g->addCosto(i,c);
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		g->addEdge(u-1,v-1);
	}
	g->strong();
 	return 0;
}