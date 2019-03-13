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
 	vector<vector<int>> scc;
	int top;
	vector<int> pila;
	//unordered_map<int,lli> nodoCosto;

	Graph(bool undirected,int n){
		adj.resize(n);
		this->n =n;
		this->undirected = undirected;
	}
	
	void addEdge(int u, int v){
		adj[u].push_back(v);
	}

	
	void FuertementeConexo(int u) {
		label[u] = low[u] = ++tiempo;
		pila[++top] = u;
		for (int v : adj[u]) {
			if (!label[v]) FuertementeConexo(v);
			low[u] = min(low[u], low[v]);
		}
		if (label[u] == low[u]) {
			vector<int> componente;
			while (pila[top] != u) {
				componente.push_back(pila[top]);
				low[pila[top--]] = n + 1;
			}
			componente.push_back(pila[top--]);
			scc.push_back(componente);
			low[u] = n + 1;
		}
	}

	vector<int> strong(){
		low = vector<int>(n);
		label = vector<int>(n);
		tiempo = 0, scc.clear();
		top = -1, pila = vector<int>(n);

		for(int u=0; u < n;u++)
			if(!label[u])
				FuertementeConexo(u);
		/*
		for (int i = 0; i < scc.size(); ++i)
		{
			for (int j = 0; j < scc[i].size(); ++j)
			{
				cout << scc[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n\n";
		*/
		vector<int> resultado;
		
		bool meter = false;
		for (int i = 0; i < scc.size(); ++i){
			for (int j = 0; j < scc[i].size(); ++j){
				int num = scc[i][j];
				//cout << "Num " << num << endl;
				//meter = false;
				for (int u : adj[num]){
					meter = false;
					for (int v: scc[i]){
						if(u == v)
							meter = true;
					}
					if(!meter)
						break;
				}
				if(!meter)
					break;
						
			}
			if(meter){
				for (int a = 0; a < scc[i].size(); ++a){
					resultado.push_back(scc[i][a]);
				}
			}
		}
		
		return resultado;
	}


};
 



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout.tie(0);
	int n,m,u,v;
	while(true){
		cin >> n;
		if(!n)
			break;
		cin >> m;
		Graph *g = new Graph(false,n);
		vector<int> outdegree(n,0);
		//cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> u >> v;
			g->addEdge(u-1,v-1);
			outdegree[u-1]++;
		}
		vector<int> resultado = g->strong();
		
		for (int i = 0; i < n; ++i){
			if(!outdegree[i])
				resultado.push_back(i);
		}
		sort(resultado.begin(), resultado.end());
		unordered_set<int> numeros;
		for (int i = 0; i < resultado.size(); ++i){
			if(!numeros.count(resultado[i])){
				cout << resultado[i]+1 << " ";
				numeros.insert(resultado[i]);
			}
		}
		cout << "\n";
	}
	
 	return 0;
}