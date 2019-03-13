#include <bits/stdc++.h>
using namespace std;
struct node
{
	int rank;
	int p;
	int s;
};
//typedef element* node;


class Graph
{
public:
	bool undirected=true;
	vector<node> nodos;

	node makeset(int v){
		node aux;
		aux.rank = 0;
		aux.s=1;
		aux.p = v;
		return aux;
	}

	Graph(int n){
		nodos.resize(n);
		for (int i = 0; i < n; ++i)
			nodos[i]=makeset(i);
		
	}

	int findset(int v){
		if(v != nodos[v].p){
			(nodos[v]).p = findset(nodos[v].p);
		}
		return nodos[v].p;
	}
	
	void link(int u, int v){
		if(nodos[u].rank > nodos[v].rank){
			(nodos[v]).p = u;
			(nodos[u]).s += nodos[v].s;
		}
		else{
			(nodos[u]).p = v;
			(nodos[v]).s += nodos[u].s;
		}
		if(nodos[v].rank == nodos[u].rank)
			(nodos[v]).rank++;
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

	void addEdge(int u, int v){
		if(!sonConexos(u,v))
			union_set(u,v);
	}

	void query(int u){
		cout << nodos[findset(u)].s << "\n"; 
	}
	

};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n,m,u,v;
	char c;
	cin >> n >> m;
	Graph *g = new Graph(n);
	for (int i = 0; i < m; ++i){
		cin >> c;
		if(c == 'A'){
			cin >> u >> v;
			g->addEdge(u-1,v-1);
		}
		else{
			cin >> u;
			g->query(u-1);
		}
	}
 	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
struct element
{
	int index;
	int rank;
	int p;
	int s;
};
typedef element* node;
vector<node> nodos;

class Graph
{
public:
	bool undirected=true;
	

	node makeset(int v){
		node aux = new element();
		aux->rank = 0;
		aux->index = v;
		aux->s=1;
		aux->p = v;
		return aux;
	}

	Graph(int n){
		//adj->resize(n);
		nodos.resize(n,NULL);
		//this->undirected = undirected;
		//for (int i = 0; i < n; ++i)
			//nodos[i]=makeset(i);
	}

	node findset(node v){
		if(v->index != nodos[v->p]->index){
			//cout << "Son dif\n";
			v->p = findset(nodos[v->p])->index;
		}
		//cout << "regreso a mi padre que es: " << v->p->index << "\n";
		return nodos[v->p];
	}
	
	void link(node u, node v){
		if(u->rank > v-> rank){
			v->p = u->index;
			u->s += v->s;
		}
		else{
			u->p = v->index;
			v->s += u->s;
		}
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

	void addEdge(int u, int v){
		if(nodos[u] == NULL){
			//cout << "es nulo\n";
			nodos[u]=makeset(u);
		}
		if(nodos[v] == NULL){
			//cout << "es nulo\n";
			nodos[v]=makeset(v);
		}
		if(!sonConexos(u,v))
			union_set(nodos[u],nodos[v]);
	}

	void query(int u){
		cout << findset(nodos[u])->s << "\n"; 
	}
	

};

int main(){
	//ios_base::sync_with_stdio(0);
    //cin.tie(0);
	int n,m,u,v;
	char c;
	cin >> n >> m;
	Graph *g = new Graph(n);
	for (int i = 0; i < m; ++i){
		cin >> c;
		if(c == 'A'){
			cin >> u >> v;
			g->addEdge(u-1,v-1);
		}
		else{
			cin >> u;
			g->query(u-1);
		}
	}
 	return 0;
}
*/