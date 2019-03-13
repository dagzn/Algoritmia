#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
struct node
{
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
		for (int i = 0; i < n; ++i){
			makeset(i);
		}
	}
	void makeset(int v){
		node aux;
		aux.rank = 0;
		aux.p = v;
		aux.s=1;
		nodos[v]=aux;
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

	bool tamano(int v, int n){
		if(nodos[findset(v)].s != n)
			return true;
		return false;
	}
};

int main(){
	int u,v,maximo=-1;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout.tie(0);
	vector<pii> query;
	while(cin >> u){
		if(u == -1){
			UnionSet *uni= new UnionSet(100005);
			int res=0;
			for (int i = 0; i < query.size(); ++i){
				pii aux = query[i];
				if(!uni->sonConexos(aux.first,aux.second)){
					uni->union_set(aux.first,aux.second);
				}
				else{
					res++;
				}
			}
			cout << res << "\n";
			maximo =-1;
			query.clear();
		}
		else{
			maximo= max(u,maximo);
			cin >> v;
			maximo= max(v,maximo);
			query.push_back(pii(u,v));
		}
	}
	return 0;
}