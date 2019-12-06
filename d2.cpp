#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int V = 0;
const int MX = 1.2e6;
vector<int> adj[MX], bipartite[2*MX];
bitset<2*MX> visited, incident;
int Left[MX], Right[MX];
bitset<MX> used;

bool tryKuhn(int u){
	if(used[u]) return false;
	used[u] = true;
	for(int v : adj[u]){
		if(Right[v] == -1 || tryKuhn(Right[v])){
			Right[v] = u;
			Left[u] = v;
			return true;
		}
	}
	return false;
}

void dfs(int u){
	visited[u] = true;
	for(int v : bipartite[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

map<int, vector<int>> mapeo;
vector<string> cadenas;
vector<int> personas;

bool isSub(int a, int b){
	if((a|b) == b) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(Left, -1, sizeof(Left));
	memset(Right, -1, sizeof(Right));
	int n, a;
	int idx;
	int cnt = 1;
	cin >> n;
	for(int t = 0; t < n; ++t){
		cin >> a;
		int num = 0;
		while(a--){
			cin >> idx;
			num |= (1 << idx);
		}
		//cout << "num sale " << num << endl;
		if(mapeo.find(num) == mapeo.end()){
			personas.pb(num);
		}
		mapeo[num].pb(t);
	}
	V = n;// si no hay repeticiones
	//creamos las aristas

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if(i == j) continue;
			if(isSub(personas[j],personas[i])){
				adj[i].pb(j);
			}
		}
	}

	for(int u = 0; u < V; ++u){
		tryKuhn(u);
		used.reset();
	}

	set<pair<int, int>> matching;
	for(int u = 0; u < V; ++u){
		if(Right[u] != -1){
			matching.emplace(Right[u], u);
			incident[Right[u]] = true;
			incident[u + V] = true;
		}
	}

	for(int i = 0; i < V; ++i){
		for(int v : adj[i]){
			if(matching.count({i, v})){
				bipartite[v + V].push_back(i);
			}else{
				bipartite[i].push_back(v + V);
			}
		}
	}

	visited.reset();
	for(int i = 0; i < V; ++i){
		if(!incident[i] && !visited[i]){
			dfs(i);
		}
	}

	set<int> VC;
	for(int i = 0; i < V; ++i){
		if(!visited[i]){
			VC.insert(i);
		}
	}
	for(int i = V; i < 2*V; ++i){
		if(visited[i]){
			VC.insert(i - V);
		}
	}

	vector<int> antichain;
	for(int i = 0; i < V; ++i){
		if(!VC.count(i)){
			antichain.push_back(i);
		}
	}

	assert(V - matching.size() == antichain.size());

	cout << "Hay " << V - matching.size() << " equipos:" << "\n";

	for(int i = 0; i < antichain.size(); ++i){
		cout << antichain[i] << endl;
	}

	return 0;
}
