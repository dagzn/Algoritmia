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
		//cout << "Rompe en agregar\n";
		adj[u].push_back(CostoNodo(w,v));
		if(undirected)
			adj[v].push_back(CostoNodo(w,u));
		//cout << "NI IDEA\n";
	}
	// Algoritmo de dijkstra desde el nodo s.
	// Devuelve el vector de distancias a todos
	// los nodos desde s. Un valor INF indica que
	// no es posible ir de s al respectivo nodo.
	int Dijkstra(int s,int e) {
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
		
		return dist[e];
	}
};

int main(){
	int t,n,m,num=0,a;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout.tie(0);
	cin >> t;
	for(int k ; k < t ; k++){
		num = 0;
		//n filas y m columnas
		cin >> n >> m;
		vector<vector<int>> mat(n);
		int multi = n*m;
		//cout << "multi es " << multi << endl;
		Graph *g = new Graph(true,multi);
		//cout << "rompe en for\n";
		for (int i = 0; i < n; ++i){
			//cout << "Entra para el i "<< i << "\n";
			vector<int> aux(m);
			for (int j = 0; j < m; ++j){
				cin >> a;
				aux[j]=a;
				//cout << "Elemento " << j << endl;
				if(i != 0){
					//cout << "Entra 1\n";
					//cout << "Agregamos arista de " << num << " a " << num-m << " con peso de "<< a << endl;
					g->addEdge(num,num-m,a);
				}
				if(j != 0){
					//cout << "Entra 2\n";
					//cout << "Agregamos arista de " << num << " a " << num-1 << " con peso de "<< aux[j] << endl;
					g->addEdge(num,num-1,aux[j]);
				}
				num++;
			}
			//cout << "Sale bien\n";
			mat[i]=aux;
		}
		cout << g->Dijkstra(0,multi-1) + mat[0][0] << "\n";
		//t--;
	}
	return 0;
}