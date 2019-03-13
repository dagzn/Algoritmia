#include <bits/stdc++.h>
using namespace std;


class Graph
{
public:
	bool undirected;
	vector<vector<int>> adj;
	unordered_set<int> detectado;
	vector<bool> checked;
	vector<int> mcourses;
	unordered_set<int> ciclo;
	vector<char> color;
	queue<int> q;

	Graph(bool undirected,int n){
		adj.resize(n);
		//vertices.resize(n,"white");
		checked.resize(n,false);
		color.resize(n,'B');
		this->undirected = undirected;
	}

	void addEdge(int u, int v){
		adj[u].push_back(v);
		if(undirected)
			adj[v].push_back(u);
	}
	void addMain(int u){
		mcourses.push_back(u);
	}

private:


	void DetectarCiclo(int u, int p) {
		int retorno = this->undirected? 0: 1;
		color[u] = ciclo.empty()? 'G': 'N';
		for (int v : adj[u]) {
			if (v == p && !retorno++) 
				continue;
			if (ciclo.empty() && color[v] == 'G') {
				color[v] = 'A', ciclo.insert(v);
				if (u != v) 
					color[u] = 'R',
				ciclo.insert(u);
				detectado.insert(u);
			}
			if (color[v] != 'B') 
				continue;
			DetectarCiclo(v, u);
			if (color[u] == 'G' && color[v] == 'R'){
				color[u] = 'R', ciclo.insert(u);
				detectado.insert(u);
			}
		}
		if (color[u] == 'G') 
			color[u] = 'N';
	}

	vector<unordered_set<int>> DetectarCiclos() {
		vector<unordered_set<int>> ciclos;
		//color = vector<char>(n, 'B');
		for (int u = 0; u < adj.size(); ++u) {
			if (color[u] != 'B') 
				continue;
			ciclo.clear(); 
			DetectarCiclo(u, adj.size());
			//reverse(ciclo.begin(), ciclo.end());
			if (!ciclo.empty()){
				ciclos.push_back(ciclo);
			}
		}
		return ciclos;
	}


	void dfs(int u){
		//cout << "Visiting: " << u+1 << endl;
		checked[u] = true;
		for (int v = 0; v < adj[u].size(); ++v)
		{
			if(!checked[adj[u][v]])
				dfs(adj[u][v]);		
		}
		q.push(u);
	}
public:
	void topological(){
		vector<unordered_set<int>> cycles = DetectarCiclos();

		for (int i = 0; i < mcourses.size(); ++i){
			if(!checked[mcourses[i]])
				dfs(mcourses[i]);
		}

		int tamanio = q.size();
		vector<int> res;
		bool hasCycle = false;

		while (!q.empty()){
			int aux = q.front();
			//cout << "El frente es " << aux << "\n";
			for (int i = 0; i < cycles.size(); ++i){
				if(cycles[i].count(aux)){
					hasCycle=true;
					break;
				}
			}
			res.push_back(aux+1);
			q.pop();
		}
		if(!hasCycle){
			cout << tamanio << "\n";
			for (int i = 0; i < res.size(); ++i){
				cout << res[i] << " ";
			}
			cout << "\n";
		}
		else
			cout << "-1\n";
		
	}
};

int main(){
	int n,m,a,u,v;
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	Graph *g = new Graph(false,n);
	for (int i = 0; i < m; ++i){
		cin >> u;
		g->addMain(u-1);
	}
	for (int i = 0; i < n; ++i){
		cin >> a;
		for (int j = 0; j < a; ++j){
			cin >> u;
			g->addEdge(i,u-1);
		}
	}
	g->topological();
	
	return 0;
}

