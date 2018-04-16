#include <bits/stdc++.h>
using namespace std;

struct node
{
	int rank;
	int p;
};

//typedef element* node;
typedef pair<int,int> arista;
typedef pair<int,int> CostoNodo;
typedef pair<int,arista> pesoArista;

class UnionSet
{
public:
	vector<node> nodos;
	UnionSet(int n){
		nodos.resize(n);
		/*
		for (int i = 0; i < n; ++i)
			nodos[i]=makeset(i);
		*/
	}
	
	void makeset(int v){
		node aux;
		aux.rank = 0;
		aux.p = v;
		nodos[v]=aux;
		//return aux;
	}

	int findset(int v){
		if(v != nodos[v].p)
			nodos[v].p = findset(nodos[v].p);
		return nodos[v].p;
	}

	void link(int u, int v){
		if(nodos[u].rank > nodos[v].rank)
			nodos[v].p = u;
		else
			nodos[u].p = v;
		if(nodos[v].rank == nodos[u].rank)
			nodos[v].rank++;
	}

	void union_set(int u , int v){
		link(findset(u), findset(v));
	}

	bool sonConexos(int u, int v){
		if(findset(u) == findset(v))
			return true;
		else
			return false;
	}
};

class Graph
{
public:
	
	bool undirected;
	vector<vector<CostoNodo>> adj;
	unordered_set<int> visited;
	int total=0;
	int sub=0;

	Graph(bool undirected,int n){
		adj.resize(n);
		this->undirected = undirected;
	}
	
	void addEdge(int u, int v, int w){
		adj[u].push_back(CostoNodo(v,w));
		if(undirected)
			adj[v].push_back(CostoNodo(u,w));
		total+= w;
	}

	int Kruskal(){
		vector<pair<int,arista>> ordenadas;
		//vector<pair<int,arista>> resultado;
		int max = 0;
		UnionSet *uni = new UnionSet(adj.size());
		for (int i = 0; i < adj.size() ; ++i){
			uni->makeset(i);
			for (int j = 0; j < adj[i].size(); ++j){
				ordenadas.push_back(pesoArista(adj[i][j].second,arista(i,adj[i][j].first)));
			}
		}
		
		sort(ordenadas.begin(),ordenadas.end());

		for (pair<int,arista> ponderada : ordenadas){
			int u = ponderada.second.first;
			int v = ponderada.second.second;
			if(!uni->sonConexos(u,v)){
				if(!visited.count(u))
					visited.insert(u);
				if(!visited.count(v))
					visited.insert(v);

				uni->union_set(u,v);
				sub+=ponderada.first;
				//if(ponderada.first > max)
					//max = ponderada.first;
				//resultado.push_back(ponderada);
			}
		}
		//if(visited.size() != adj.size())
			//max=-1;
		//cout << "Hace kruskal bien" << endl;
		return total-sub;
	}
};

int main(){
	//initialize(3,true);
	int n,m,u,v,w;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(true){
		cin >> n >> m;
		if(!n && !m)
			break;
		Graph *g = new Graph(true,n);
		for (int i = 0; i < m; ++i){
			cin >> u >> v >> w;
			g->addEdge(u,v,w);
		}
		cout << g->Kruskal() << "\n";
		
	}
 	return 0;
}
