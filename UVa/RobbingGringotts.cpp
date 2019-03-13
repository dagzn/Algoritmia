#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
#define EPS 1e-9

struct vault
{
	vector<lli> L,R;
};

// Definiciones iniciales.
typedef int Flujo;
// Ajustable.
typedef vector<int> Lista;
typedef pair<int, int> Par;
typedef pair<lli, lli> pii;
typedef vector<Flujo> Flujo1D;
typedef vector<Flujo1D> Flujo2D;
const Flujo FINF = 1 << 30;

// Nodos indexados de 0 a n - 1.
class Bipartito {
public:
	int n; Lista pareja;
	vector<Lista> aristas;
	vector<bool> lado, visitado;
	Bipartito(int N){
		lado.resize(N);
		pareja.resize(N);
		visitado.resize(N);
		aristas.resize(N);
		n = N;
	}

	void addEdge(int u, int v) {
		aristas[u].push_back(v);
		aristas[v].push_back(u);
	}
	void addLeft(int u) { lado[u] = true; }
	void addRight(int u) { lado[u] = false; }

	lli CaminoIncremental(lli u) {
		visitado[u] = true;
		for (int i = 0; i < aristas[u].size(); ++i)
			if (pareja[aristas[u][i]] == -1)
				return pareja[aristas[u][i]] = u;
		for(int i = 0; i < aristas[u].size(); ++i){
			lli v = aristas[u][i];
			if (visitado[pareja[v]]) 
				continue;
			if (CaminoIncremental(pareja[v]) != -1)
				return pareja[v] = u;
		}
		return -1;
	}

	int MaxEmparejamiento(vector<lli> &dementores) {
		fill(pareja.begin(), pareja.end(), -1);

		vector<pii> orden(dementores.size());
		for (int i = 0; i < dementores.size(); ++i){
			orden[i].first=dementores[i];
			orden[i].second=i;
		}
		
		sort(orden.begin(), orden.end());

		for (int i = orden.size()-1; i >= 0; --i) {
			if (!lado[orden[i].second]) 
				continue;
			CaminoIncremental(orden[i].second);
			fill(visitado.begin(),visitado.end(), false);
		}

		lli resultado =0;
		vector<int> indices;
		for (int i = 0; i < n; ++i){
			if (!lado[i] && pareja[i] != -1){
				//resultado++;
				//indices.push_back(pareja[i]);
				resultado+= dementores[pareja[i]];
			}
		}
		return resultado;//Cardinalidad =pares.size()
	}
};


void combine(int a, int b, vector<lli> &ans,vector<lli> &A){
	ans.push_back(0);
	for(int i = a; i <= b; i++){
		int size = ans.size();
		for(int j = 0; j < size; j++){
			ans.push_back(ans[j] + A[i]);
		}
	}
	sort(ans.begin(), ans.end());
}

vault getCombinations(lli n, vector<lli> &numbers){
	vector<lli> left;
	vector<lli> right;
	combine(0, (n - 1) / 2, left,numbers);
	combine((n - 1) / 2 + 1, n - 1, right,numbers);
	vault aux;
	aux.L = left;
	aux.R = right;
	return aux;
}
bool checkCapacity(vault v,lli a){
	vector<lli> left = v.L;
	vector<lli> right = v.R;
	bool exists=false;
	for (int i = 0; i < left.size(); ++i){
		//auto it = equal_range(right.begin(), right.end(),a-left[i]);
		lli exacto = a-left[i];
		int p = lower_bound(right.begin(), right.end(),exacto) - right.begin();
		if(p >= right.size() || right[p] != exacto)
			continue;
		//cout << "Encontramos a "<< left[i] << " y a " << right[p] << " que dan a " << a << endl;
		exists = true;
		break;
	}
	return exists;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,n,m,a,u;
	cin >> t;
	for (int k = 0; k < t; ++k){
		cin >> n >> m;
		Bipartito *g = new Bipartito(n+m);
		//Introducir datos
		vector<lli> dementores(n);
		for (int i = 0; i < n; ++i){
			cin >> a;
			dementores[i]=a;
		}
		vector<vector<lli>> bovedas(m);
		vector<vault> combinaciones(m);
		for (int i = 0; i < m; ++i){
			cin >> a;
			for (int j = 0; j < a; ++j){
				cin >> u;
				bovedas[i].push_back(u);
			}
		}

		//Hacer las combinaciones con el subset sums y guardar los dos vectores
		for (int i = 0; i < m; ++i){
			vault aux= getCombinations(bovedas[i].size(),bovedas[i]);
			combinaciones[i]=aux;
		}

		//Vamos a agregar aristas
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				//cout << "Hacemos al dementor " << i << " con la combinacion " << j << endl;
				if(checkCapacity(combinaciones[j],dementores[i])){
					//cout << "metemos arista de " << i << " hacia " << j+n << endl;
					g->addEdge(i,j+n);
				}
			}
		}

		for (int i = 0; i < n; ++i)
			g->addLeft(i);
		for (int i = n; i < n+m; ++i)
			g->addRight(i);
		
		cout << g->MaxEmparejamiento(dementores) << "\n";
	}
	return 0;
}