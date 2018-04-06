#include <bits/stdc++.h>
using namespace std;
class Graph
{
	unordered_map<char,vector<char>> adj;
	unordered_set<char> checked;
	unordered_map<char,int> degree;
	unordered_map<char,string> vertices;

public:
	unordered_map<char,int> pos;
	
	void addEdge(char u,char v){
		//cout << "Agregamos arista de " << u << " hacia " << v << endl;
		adj[u].push_back(v);
		if(!degree.count(u))
			degree[u]=0;
		degree[v]++;
	}

	/*
	void dfs(char u){
		//cout << "Visiting: " << u+1 << endl;	
		checked.insert(u);
		for (int v = 0; v < adj[u].size(); ++v)
		{
			if(!checked.count(adj[u][v]))
				dfs(adj[u][v]);		
		}
		//s.push(u);
	}
	*/
	bool dfsDirected(char u){
		vertices[u] = "grey";
		checked.insert(u);
		for (int i = 0; i < adj[u].size(); ++i)
		{
			if(vertices[adj[u][i]] == "black")
				continue;
			if(vertices[adj[u][i]] == "grey")
				return true;
			if(dfsDirected(adj[u][i]))
				return true;
		}
		vertices[u] = "black";
		return false;
	}

	bool hasCycle(){
		for (auto i = adj.begin(); i != adj.end(); ++i)
		{
			if(!checked.count(i->first)){
				if(dfsDirected(i->first))
					return true;
			}
		}
		return false;
	}

	void topological(char u,int cont){
		//cout << "Entro a topo con caracter " << u << endl;
		if(degree[u] == 0){
			cout << u;
			for (int i = 0; i < adj[u].size(); ++i){
				degree[adj[u][i]]--;
				//cout << "El nuevo degree de " << adj[u][i] << " es igual a " << degree[adj[u][i]] << endl;
				//cout << "El num " << adj[u][i] << " tiene una pos de " << pos[adj[u][i]] <<"y el contador es de " << cont << endl;;
				if(pos.count(adj[u][i])){
					if(pos[adj[u][i]] < cont && degree[adj[u][i]] == 0){
						//cout << adj[u][i];
						topological(adj[u][i],cont);
					}
				}
			}
		}
	}
};

int main(){
	unordered_set<char> letras;
	int n;
	string s,pasada;
	ios_base::sync_with_stdio(0);
	cin >> n;
	cin >> pasada;
	Graph *g = new Graph();
	bool iguales=true;
	for (int i = 0; i < n-1; ++i){
		cin >> s;
		for (int j = 0; j < pasada.size() && j < s.size(); ++j){
			if(pasada[j] != s[j]){
				g->addEdge(pasada[j],s[j]);
				letras.insert(pasada[j]);
				letras.insert(s[j]);
				iguales=false;
				break;
			}
		}
		if(iguales && pasada.size() > s.size()){
			cout << "Impossible\n";
			return 0;
		}
		iguales=true;
		pasada = s;
	}
	if(g->hasCycle()){
		cout << "Impossible\n";
		return 0;
	}
	int cont=0;
	for (char i = 'a'; i <= 'z'; ++i,cont++){
		g->pos[i]=cont;
		if(letras.count(i)){
			g->topological(i,cont);
		}
		else{
			cout << i;
		}
	}
	cout << "\n";
	return 0;
}