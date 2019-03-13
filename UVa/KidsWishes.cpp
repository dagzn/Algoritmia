#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pii;
struct node
{
	lli rank;
	lli p;
	lli s;
};
 
class UnionSet
{
public:
	unordered_map<lli,node> nodos;
	UnionSet(lli n){
		//nodos.resize(n);
		/*
		for (lli i = 0; i < n; ++i){
			makeset(i);
		}*/
	}
	void makeset(lli v){
		node aux;
		aux.rank = 0;
		aux.p = v;
		aux.s=1;
		nodos[v]=aux;
	}
 
	lli findset(lli v){
		if(v != nodos[v].p)
			nodos[v].p = findset(nodos[v].p);
		return nodos[v].p;
	}
 
	void link(lli u, lli v){
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
	void union_set(lli u , lli v){
		link(findset(u), findset(v));
	}
 
	bool sonConexos(lli u, lli v){
		if(nodos[u].s == 0)
			makeset(u);
		if(nodos[v].s == 0)
			makeset(v);
		
		if(findset(u) == findset(v))
			return true;
		else
			return false;
		
	}

	lli tamano(lli v){
		/*
		if(nodos[findset(v)].s != n)
			return true;
		return false;
		*/
		return nodos[findset(v)].s;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout.tie(0);
	lli n,m,u,v;
	bool terminar;
	while(true){
		unordered_map<lli,lli> contador;
		map<pii,bool> query;
		terminar = false;
		cin >> n >>m;
		if(!n && !m)
			break;
		if(m == 0){
			terminar=false;
		}
		UnionSet *uni = new UnionSet(n);
		//terminar = false;
		for (int i = 0; i < m; ++i){
			cin >> u >> v;
			u--,v--;
			if(u == v)
				continue;

			if(!query.count(pii(u,v))){
				query[pii(u,v)] = true;
				query[pii(v,u)] = true;
			}
			else
				continue;

			contador[u]++;
			contador[v]++;

			if(contador[u] >2 || contador[v] > 2)
				terminar=true;
			
			if(uni->sonConexos(u,v)){
				if(uni->tamano(u) != n){
					terminar = true;
				}
			}
			else{
				uni->union_set(u,v);		
			}
		}
		if(!terminar)
			cout << "Y\n";
		else
			cout << "N\n";
	}
	return 0;
}