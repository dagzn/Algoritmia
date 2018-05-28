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

class GFlujo
{
public:
	int n;
	vector<Lista> aristas;
	Flujo2D cap, flujo;
	Lista padre,dist;
	vector<char> numeros;

	GFlujo(int n){
		this->n = n;
		dist.resize(n);
		padre.resize(n);
		aristas.resize(n);
		Flujo1D aux(n);
		cap.resize(n,aux);
		flujo.resize(n,aux);

	}

	void addEdge(int u, int v ,Flujo c){
		flujo[v][u]+=c;// Solo dirigidas!
		cap[u][v]+=c, cap[v][u] += c;
		aristas[u].push_back(v);
		aristas[v].push_back(u);
	}

	// Flujo maximo mediante Edmonds-Karp O(VE^2).
	Flujo ActualizarFlujo(int u, Flujo f) {
		int p = padre[u];
		if (p == u) return f;
		f = ActualizarFlujo(p, min(f,
		cap[p][u] - flujo[p][u]));
		flujo[p][u] += f;
		flujo[u][p] -= f;
		return f;
	}

	Flujo AumentarFlujo(int s, int t) {
		fill(padre.begin(), padre.end(), -1);
		queue<int> q; q.push(s); padre[s] = s;
		while (!q.empty()) {
			int u = q.front();
			q.pop(); if (u == t) break;
			for(int i=0; i<aristas[u].size(); ++i){
				int v = aristas[u][i];
				if (flujo[u][v] == cap[u][v] || padre[v] != -1) 
					continue;
				padre[v] = u, q.push(v);
			}
		}
		if (padre[t] == -1) 
			return 0;
		return ActualizarFlujo(t, FINF);
	}

	Flujo EdmondsKarp(int s, int t) {
		Flujo flujo_maximo = 0, f;
		while (f = AumentarFlujo(s, t))
			flujo_maximo += f;
		return flujo_maximo;
	}
};


int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int n;
	while(cin >> n){
		string s;
		vector<string> matriz(n);
		vector<int> filas(n,1);
		vector<int> columnas(n,1);
		for (int i = 0; i < n; ++i){
			cin >> s;
			matriz[i]=s;
			for (int j = 0; j < n; ++j){
				if(s[j] == 'X'){
					if(j+1 < n && j != 0){
						if(s[j+1] != 'X'){
							if(j == 0)
								filas[i]++;
							else{
								if(s[j-1] != 'X')
									filas[i]++;
								else
									if(j-1 != 0)
										filas[i]++;
							}
						}
					}
				}
			}
		}

		for (int j = 0; j < n; ++j){
			for (int i = 0; i < n; ++i){
				string aux = matriz[i];
				if(aux[j] == 'X'){
					if(i+1 < n && i != 0){
						if(matriz[i+1][j] != 'X'){
							if(i == 0)
								columnas[j]++;
							else{
								if(matriz[i-1][j] != 'X')
									columnas[j]++;
								else
									if(i-1 != 0)
										columnas[i]++;
							}
						}
					}
				}
			}
		}
		/*
		cout << "Valores para filas\n";
		for (int i = 0; i < n; ++i){
			cout << filas[i] << " ";
		}
		cout << "\nValores para columnas\n";
		for (int i = 0; i < n; ++i){
			cout << columnas[i] << " ";
		}
		cout << "\n";
		*/
		GFlujo *g = new GFlujo(202);
		int source = 0,end =201;
		for (int i = 0; i < n; ++i){
			//Para el source con las filas
			g->addEdge(source,i+1,filas[i]);
			//Para las columas con el end
			g->addEdge(i+101,end,columnas[i]);
		}
		//para unir a las filas con las columnas
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if(matriz[i][j] != 'X'){
					g->addEdge(i+1,j+101,FINF);
				}
			}
		}

		cout << g->EdmondsKarp(source,end) << "\n";
	}
	
	
	return 0;
}

