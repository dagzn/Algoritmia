#include <bits/stdc++.h>
using namespace std;
 
struct node
{
	int rank;
	int p;
	int s;
};
 
//typedef element* node;
typedef pair<int,int> arista;
typedef pair<int,int> coordenada;
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
		aux.s=1;
		nodos[v]=aux;
		//return aux;
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
 
class Graph
{
public:
	
	bool undirected;
	vector<vector<CostoNodo>> adj;
	vector<pesoArista> ordenadas;
	vector<pesoArista> resultado;
	int total=0;
	int sub=0;
 
	Graph(bool undirected,int n){
		adj.resize(n);
		this->undirected = undirected;
	}
	
	void addEdge(int u, int v, int w){
		adj[u].push_back(CostoNodo(v,w));
		//if(undirected)
			//adj[v].push_back(CostoNodo(u,w));
	}

	int KruskalSecond(int a,int b, int c){
		int sub = 0;
		bool saltado=true;
		UnionSet *uni = new UnionSet(adj.size());
		for (int i = 0; i < adj.size() ; ++i){
			uni->makeset(i);
		}
 
		for (pair<int,arista> ponderada : ordenadas){
			int u = ponderada.second.first;
			int v = ponderada.second.second;
			if(u == a && b == v && c == ponderada.first && saltado){
				//cout << "me la salto\n";
				saltado=false;
				continue;
			}
			if(!uni->sonConexos(u,v)){
				uni->union_set(u,v);
				sub+=ponderada.first;
			}
		}
		if(uni->tamano(0,adj.size()))
			return -1;
		return sub;
	}

	bool KruskalFirst(){
		
		//int sub=0;
		int inicio=0;
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
				uni->union_set(u,v);
				total+=ponderada.first;
				resultado.push_back(ponderada);
			}
		}
		if(uni->tamano(0,adj.size()))
			return false;
		return true;
		//return resultado;
	}

	void secondWay(){
		int min =1 << 30;
		if(KruskalFirst()){
			for(pesoArista ponderada : resultado){
				int u = ponderada.second.first;
				int v = ponderada.second.second;
				int w = ponderada.first;
				//cout << "Quitamos a la arista " << u << " " << v << " " << w << endl;
				int res = KruskalSecond(u,v,w);
				//cout << "El res fue de " << res << endl;
				if(res != -1){
					if(res != total){
					if(res < min)
						min = res;
						//break;
					}
				}
			}
			if(min > 0)
				cout << min << "\n";
			else
				cout << "No second way\n";
		}
		else
			cout << "No way\n";
		//return min;
	}


};
 
int main(){
	int n,m,x,y,w,T,cont=1;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int k = 0; k < T; ++k){
		cin >> n >> m;
		Graph *g = new Graph(true,n);
		for (int i = 0; i < m; ++i){
			cin >> x >> y >> w;
			g->addEdge(x-1,y-1,w);
		}
		cout << "Case #" << cont << " : ";
		if(n == 1 && m == 0){
			cout << "No second way\n";
			continue;
		}
		if(n > 1 && m == 0){
			cout << "No way\n";
			continue;
		}
		g->secondWay();
		cont++;
	}
 	return 0;
}