#include <bits/stdc++.h>
using namespace std;

struct node
{
	int index;
	int rank;
	int p;
	int s;
};

class UnionSet
{
public:
	vector<node> nodos;
	UnionSet(int n){
		nodos.resize(n);
		for (int i = 0; i < n; ++i)
			nodos[i]=makeset(i);		
	}
	
	node makeset(int v){
		node aux;
		aux.rank = 0;
		aux.p = v;
		aux.s=1;
		aux.index = v;
		return aux;
	}

	int findset(int v){
		if(v != nodos[v].p)
			nodos[v].p = findset(nodos[v].p);
		return nodos[v].p;
	}

	void link(int u, int v){
		if(nodos[u].rank > nodos[v].rank){
			nodos[v].p = u;
			nodos[u].s+=nodos[v].s;
		}
		else{
			nodos[u].p = v;
			nodos[v].s+=nodos[u].s;
		}
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

	void addEdge(int u,int v){
		if(!sonConexos(u,v))
			union_set(u,v);
	}
	int query(int u){
		return nodos[findset(u)].s;
	}
};

int main(){
	//initialize(3,true);
	int n,m,u,v;
	char c;
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	cin >> n >> m;
	UnionSet *uni = new UnionSet(n);
	for (int i = 0; i < m; ++i){
		cin >> c;
		if(c == 'A'){
			cin >> u >> v;
			uni->addEdge(u-1,v-1);
		}
		else{
			cin >> u;
			cout << uni->query(u-1) << "\n";
		}
	}
 	return 0;
}
