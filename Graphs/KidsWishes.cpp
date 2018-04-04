#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<vector<lli>> adj;
lli n,w;
bool bi=true;
void addEdge(int u, int v){
	//if(find(adj[u].begin(), adj[u].end(), v) == adj[u].end())
		adj[u].push_back(v);
	//if(find(adj[v].begin(), adj[v].end(), u) == adj[v].end())
		adj[v].push_back(u);
}

// Detecta ciclos en un grafo o multigrafo.
// Llamar a DetectarCiclos() devuelve un
// vector de vectores; cada vector interno es
// una lista que representa un ciclo del grafo.
// NOTA: Solo detecta un ciclo por componente.
vector<lli> ciclo;
vector<char> color;
void DetectarCiclo(int u, int p) {
	int retorno = bi? 0: 1;
	color[u] = ciclo.empty()? 'G': 'N';
	for (int v : adj[u]) {
		if (v == p && !retorno++) 
			continue;
		if (ciclo.empty() && color[v] == 'G') {
			color[v] = 'A', ciclo.push_back(v);
			if (u != v) color[u] = 'R',
			ciclo.push_back(u);
		}
		if (color[v] != 'B') 
			continue;
		DetectarCiclo(v, u);
		if (color[u] == 'G' && color[v] == 'R')
			color[u] = 'R', ciclo.push_back(u);
	}
	if (color[u] == 'G') 
		color[u] = 'N';
}

vector<vector<lli>> DetectarCiclos() {
	vector<vector<lli>> ciclos;
	color.resize(n, 'B');
	for (int u = 0; u < n; ++u) {
		if (color[u] != 'B') 
			continue;
		ciclo.clear(); 
		DetectarCiclo(u, n);
		//reverse(ciclo.begin(), ciclo.end());
		if (!ciclo.empty())
			ciclos.push_back(ciclo);
	}
	return ciclos;
}

int main(){
	//lli n,w;
	lli u=0ll,v=0ll;
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	while(true){
		cin >> n >> w;
		if(!n && !w)
			break;
		if(w == 0ll){
			cout << "Y\n";
		}
		else{
			bool flag = false;
			unordered_map<int,int> cont;
			adj.resize(n);
			for (int i = 0; i < w; ++i){
				cin >> u >> v;
				if(u == v)
					flag = true;
				if(find(adj[u].begin(), adj[u].end(), v) == adj[u].end())
					cont[u]++;
				if(find(adj[v].begin(), adj[v].end(), u) == adj[v].end())
					cont[v]++;
				if(cont[u] > 2 || cont[v] > 2)
					flag = true;
				addEdge(u-1,v-1);
			}
			if(flag){
				cout << "N\n";
			}
			else{
				vector<vector<lli>> ciclos = DetectarCiclos();
				if(ciclos.size() > 1){
					cout << "N\n";
				}
				else{
					if(ciclos.size() == 0)
						cout << "Y\n";
					else{
						if(ciclos[0].size() == n)
							cout << "Y\n";
						else
							cout << "N\n";
					}
				}
			}
		}	
	}
	return 0;
}
