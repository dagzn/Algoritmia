#include <bits/stdc++.h>
using namespace std;

struct element
{
	int index;
	int rank;
	element* p;
};

typedef element* node;
typedef pair<int,int> arista;
typedef pair<int,int> CostoNodo;
typedef pair<int,arista> pesoArista;

class UnionSet
{
public:
	vector<node> nodos;
	UnionSet(int n){
		nodos.resize(n);
	}
	
	node makeset(int v){
		node aux = new element();
		aux->rank = 0;
		aux->p = aux;
		aux->index = v;
		return aux;
	}

	node findset(node v){
		if(v->index != v->p->index)
			v->p = findset(v->p);
		return v->p;
	}

	void union_set(node u , node v){
		//link(findset(u), findset(v));
		if(u->rank > v-> rank)
			v->p = u;
		else
			u->p = v;
		if(v->rank == u->rank)
			v->rank++;
	}

	bool sonConexos(int u, int v){
		if(findset(nodos[u])->index == findset(nodos[v])->index)
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

	Graph(bool undirected,int n){
		adj.resize(n);
		this->undirected = undirected;
	}
	
	void addEdge(int u, int v, int w){
		adj[u].push_back(CostoNodo(v,w));
		if(undirected)
			adj[v].push_back(CostoNodo(u,w));
	}

	int Kruskal(){
		vector<pair<int,arista>> ordenadas;
		vector<pair<int,arista>> resultado;
		int max = 0;
		UnionSet *uni = new UnionSet(adj.size());
		for (int i = 0; i < adj.size() ; ++i){
			uni->nodos[i] = uni->makeset(i);
			for (int j = 0; j < adj[i].size(); ++j){
				ordenadas.push_back(pesoArista(adj[i][j].second,arista(i,adj[i][j].first)));
			}
		}
		
		sort(ordenadas.begin(),ordenadas.end());

		for (pair<int,arista> ponderada : ordenadas){
			int u = ponderada.second.first;
			int v = ponderada.second.second;
			if(!uni->sonConexos(u,v)){
				uni->union_set(uni->nodos[u],uni->nodos[v]);
				if(ponderada.first > max)
					max = ponderada.first;
				resultado.push_back(ponderada);
			}
		}
		//cout << "Hace kruskal bien" << endl;
		return max;
	}
};

int main(){
	//initialize(3,true);
	Graph *g = new Graph(true,6);
	
	g->addEdge(0,1,3);
	g->addEdge(1,2,3);
	g->addEdge(2,0,5);
	g->addEdge(2,3,4);
	g->addEdge(3,4,4);
	g->addEdge(3,5,3);
	g->addEdge(5,4,5);
	
	/*
	g->addEdge(0,1,1);
	g->addEdge(1,2,2);
	g->addEdge(2,0,3);
	*/
	cout << g->Kruskal() << endl;
 	return 0;
}
