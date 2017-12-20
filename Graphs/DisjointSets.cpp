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
bool undirected;
vector<vector<CostoNodo>> adj;
vector<node> nodos;



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

void link(node u, node v){
	if(u->rank > v-> rank)
		v->p = u;
	else
		u->p = v;
	if(v->rank == u->rank)
		v->rank++;
}

void union_set(node u , node v){
	link(findset(u), findset(v));
}

bool sonConexos(int u, int v){
	if(findset(nodos[u])->index == findset(nodos[v])->index)
		return true;
	else
		return false;
}




void initialize(int n,bool u){
	adj.resize(n);
	nodos.resize(n);
	undirected = u;
}

void addEdge(int u, int v, int w){
	adj[u].push_back(CostoNodo(v,w));
	if(undirected)
		adj[v].push_back(CostoNodo(u,w));
}



vecttor<pair<int,arista>> Kruskal(){
	vector<pair<int,arista>> ordenadas;
	vector<pair<int,arista>> resultado;
	for (int i = 0; i < adj.size() ; ++i){
		nodos[i] = makeset(i);
		for (int j = 0; j < adj[i].size(); ++j){
			ordenadas.push_back(pesoArista(adj[i][j].second,arista(i,adj[i][j].first)));
		}
	}
	
	sort(ordenadas.begin(),ordenadas.end());
	for (pair<int,arista> ponderada : ordenadas){
		int u = ponderada.second.first;
		int v = ponderada.second.second;
		if(!sonConexos(u,v)){
			union_set(nodos[u],nodos[v]);
			//if(ponderada.first > max)
				//max = ponderada.first;
			resultado.push_back(ponderada);
		}
	}
	//cout << "Hace kruskal bien" << endl;
	return max;
}

int main(){
	initialize(3,true);
	/*
	addEdge(0,1,3);
	addEdge(1,2,3);
	addEdge(2,0,5);
	addEdge(2,3,4);
	addEdge(3,4,4);
	addEdge(3,5,3);
	addEdge(5,4,5);
	*/
	addEdge(0,1,1);
	addEdge(1,2,2);
	addEdge(2,0,3);
	cout << Kruskal() << endl;
 	return 0;
}