#include <bits/stdc++.h> 
using namespace std;
typedef int Costo;
typedef pair<int, int> Arista;
typedef pair<int,char> nodoCaracter;
const Costo INF = 1 << 30;
typedef pair<Costo, nodoCaracter> CostoNodo;
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
	
	void addEdge(int u, int v,string w){
		adj[u].push_back(CostoNodo(w.size(),nodoCaracter(v,w[0])));
		if(undirected)
			adj[v].push_back(CostoNodo(w.size(),nodoCaracter(u,w[0])));
	}
	// Algoritmo de dijkstra desde el nodo s.
	// Devuelve el vector de distancias a todos
	// los nodos desde s. Un valor INF indica que
	// no es posible ir de s al respectivo nodo.
	int Dijkstra(int s,int e) {

		vector<Costo> dist(n, INF);
		
		priority_queue<CostoNodo> pq;

		pq.push(CostoNodo(0, nodoCaracter(s,'\0'))), dist[s] = 0;
		while (!pq.empty()) {
			Costo p = -pq.top().first;
			
			int u = pq.top().second.first;
			char anterior = pq.top().second.second;
			//cout << "Trabajamos con el nodo " << u <<  " y el char anterior fue " << anterior << endl; 
			pq.pop();
			if (dist[u] < p) 
				continue;
			for (CostoNodo arista : adj[u]) {

				int v = arista.second.first;
				char c= arista.second.second;
				if(c == anterior)
					continue;
				//cout << "Tomamos a la arista " << u << "-> " << v << " con caracter " << c << endl;
				p = dist[u] + arista.first;
				if (p < dist[v]){
					//cout << "Nueva distancia para " << v << " que es de " << p << endl; 
					dist[v] = p;
				}
				pq.push(CostoNodo(-p, nodoCaracter(v,c)));
			}

		}
		return dist[e];
	}


};


int main(){
	int n,source,end;
	string u,v,w;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(true){
		cin >> n;
		if(!n)
			break;
		unordered_map<string,int> idiomas;
		int contador =0;
		Graph *g = new Graph(true,n+n+5);
		cin >> u >> v;

		idiomas[u]=contador;
		source = contador;
		//cout << u << " " << contador<<endl;
		contador++;
		idiomas[v]=contador;
		//cout << v << " " << contador<<endl;
		end = contador;
		contador++;

		for (int i = 0; i < n; ++i){
			cin >> u >> v >> w;
			if(!idiomas.count(u)){
				idiomas[u]=contador;
				//cout << u << " " << contador<<endl;
				contador++;
			}
			if(!idiomas.count(v)){
				idiomas[v]=contador;
				//cout << v << " " << contador<<endl;
				contador++;
			}
			g->addEdge(idiomas[u],idiomas[v],w);
		}
		int res1 = g->Dijkstra(source,end);
		int res2 = g->Dijkstra(end,source);
		if((res1 == res2) && res1 != INF)
			cout << res1 << "\n";
		else{
			if(res1 == res2)
				cout << "impossivel\n";
			else
				cout << min(res1,res2) << "\n";
		}
		//cout << "res1 " << res1 << " res2 " << res2 << endl;
	}
	return 0;
}