#include <bits/stdc++.h>
using namespace std;
 
class Graph
{
public:
	
	bool undirected;
	vector<vector<int>> adj;
 	vector<int> label, low;
 	int tiempo,n;
 	vector<vector<int>> scc;
	int top;
	vector<int> pila;

	Graph(bool undirected,int n){
		adj.resize(n);
		this->n =n;
		//label.resize(n);
		//low.resize(n);
		this->undirected = undirected;
	}
	
	void addEdge(int u, int v){
		adj[u].push_back(v);
	}

	
	void FuertementeConexo(int u){
		tiempo++;
		label[u]=tiempo;
		low[u]=tiempo;
		top++;
		pila[top]=u;
		for(int v : adj[u]){
			if(!label[v])
				FuertementeConexo(v);
			low[u]=min(low[u],low[v]);
		}
		if(label[u]==low[u]){
			vector<int> componente;
			while(pila[top] != u){
				componente.push_back(pila[top]);
				top--;
				low[pila[top]]=n+1;
			}
			top--;
			componente.push_back(pila[top]);
			scc.push_back(componente);
			low[u]=n+1;
		}
	}

	void strong(){
		low.resize(n);
		label.resize(n);
		tiempo=0;
		scc.clear();
		top=-1;
		pila.resize(n);

		for(int u=0; u < n;u++)
			if(!label[u])
				FuertementeConexo(u);

		//int total=0;
		//vector<int> res;
		for (int i = 0; i < scc.size(); ++i){
			//if(scc[i].size() > 1){
				//total+=scc[i].size();
				cout << "SCC numero " << i+1 << endl;
				for (int j = 0; j < scc[i].size(); ++j){
					//res.push_back((scc[i][j])+1);
					cout << scc[i][j] << " ";
				}
				cout << "\n";
			//}
		}
		/*
		cout << total << "\n";
		for (int i = 0; i < total; ++i){
			cout << res[i] << " ";
		}
		cout << "\n";
		*/
	}


};
 
int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int n,m,u,v;
	cin >> n >> m;
	Graph *g = new Graph(false,n);
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		g->addEdge(u-1,v-1);
	}
	g->strong();
 	return 0;
}