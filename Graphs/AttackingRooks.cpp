#include <bits/stdc++.h>
using namespace std;
// Definiciones iniciales.
typedef int Flujo;
// Ajustable.
typedef vector<int> Lista;
typedef pair<int, int> Par;
typedef vector<Flujo> Flujo1D;
typedef vector<Flujo1D> Flujo2D;
const Flujo FINF = 1 << 30;

// Nodos indexados de 0 a n - 1.
class Bipartito {
public:
	int n; Lista pareja;
	vector<Lista> aristas;
	vector<bool> lado, visitado;
	unordered_map<int,int> cantidad;
	Bipartito(int N){
		lado.resize(N);
		pareja.resize(N);
		visitado.resize(N);
		aristas.resize(N);
		//cantidad.resize(101);
		n = N;
	}

	void addEdge(int u, int v) {
		aristas[u].push_back(v);
		aristas[v].push_back(u);
	}

	void addCantidad(int u,int c){
		cantidad[u+100]=c;
	}

	void addLeft(int u) { lado[u] = true; }
	void addRight(int u) { lado[u] = false; }

	int CaminoIncremental(int u) {
		visitado[u] = true;
		cout << "Ahora conocemos al " << u << endl;
		for (int i = 0; i < aristas[u].size(); ++i){
			int v = aristas[u][i];			
			if (pareja[v] == -1){
				cout << "Le asignamos directo a " << v << " a " << u << endl;
				return pareja[v] = u;
			}
			else{
				if(cantidad[v] > 1){
					cout << "La cantidad de " << v << " es de "<< cantidad[v] << endl;
					cantidad[v]--;
					return pareja[v] = u;
				}
			}
		}
			
		for(int i = 0; i < aristas[u].size(); ++i){
			int v = aristas[u][i];
			if (visitado[pareja[v]]){
				cout << "Ya esta visitado el " << pareja[v] << endl; 
				continue;
			}
			if (CaminoIncremental(pareja[v]) != -1){
				cout << "Nos retorno algo el camino de " << pareja[v] << endl;
				return pareja[v] = u;
			}
		}
		return -1;
	}

	int MaxEmparejamiento(int maxL) {
		int resultado=0;
		fill(pareja.begin(), pareja.end(), -1);
		for (int i = 0; i <= maxL; ++i) {
			if (!lado[i]) 
				continue;
			CaminoIncremental(i);
			fill(visitado.begin(),visitado.end(), false);
		}
		//vector<Par> pares;
		for (int i = 0; i < n; ++i)
			if (!lado[i] && pareja[i] != -1){
				cout << "Encontramos a " << pareja[i] << " con " << i-100 << endl;
				resultado++;
			}
		return resultado;//Cardinalidad =pares.size()
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n,m,u,v,a;
	cin >> t;
	for (int k = 0; k < t; ++k){
		cin >> n;
		int maxL=0;
		Bipartito *g = new Bipartito(205);
		for (int i = 0; i < n; ++i){
			cin >> u >> v;
			g->addEdge(u,v+100);
			g->addLeft(u);
			g->addRight(v+100);
			maxL= max(u,maxL);
		}
		cin >> m;
		for (int i = 0; i < m; ++i){
			cin >> u >> a;
			g->addCantidad(u,a);
		}
		cout << g->MaxEmparejamiento(maxL) << endl;
	}																																													
		
	return 0;
}