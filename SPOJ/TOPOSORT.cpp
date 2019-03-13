#include <bits/stdc++.h>
using namespace std;
/*
struct par
{
	int index;
	int d;
};
*/
class Graph
{
public:
	bool undirected;
	vector<vector<int>> adj;
	vector<bool> checked;
	vector<string> vertices;
	vector<int> degrees;
	stack<int> s;

	Graph(bool undirected,int n){
		adj.resize(n);
		checked.resize(n,false);
		vertices.resize(n,"white");	
		degrees.resize(n);
		this->undirected = undirected;
	}

	void addEdge(int u, int v){
		adj[u].push_back(v);
		degrees[v]++;
	}
	/*
	bool compare(par x, par y){
		if(x.d != y.d)
			return x.d < y.d;
		return x.index < y.index; 
	}
	*/
	bool dfsDirected(int u){
		vertices[u] = "grey";
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
		for (int i = 0; i < adj.size(); ++i)
		{
			if(vertices[i] == "white"){
				if(dfsDirected(i))
					return true;
			}
		}
		return false;
	}

	void dfs(int u){
		//cout << "Visiting: " << u+1 << endl;
		if(degrees[u]-- == 0)
			checked[u] = true;
		for (int v = 0; v < adj[u].size(); ++v)
		{
			if(!checked[adj[u][v]])
				dfs(adj[u][v]);		
		}
		if(degrees[u] == 0)
			s.push(u);
	}

	void topological(){
		
		vector<int> ceros;
		//sort(degrees.begin(), degrees.end(),compare);
		for (int i = 0; i < degrees.size(); ++i){
			if(degrees[i] == 0){
				//cout << "El nodo " << i << " tiene degree cero\n";
				ceros.push_back(i);
			}
		}

		sort(ceros.begin(), ceros.end());

		

		if(!hasCycle()){
			for (int i = 0; i < ceros.size(); ++i)
			{
				if(!checked[ceros[i]]){
					cout << ceros[i]+1 << " ";
					dfs(ceros[i]);
				}
				while(!s.empty()){
					cout << s.top()+1<< " ";
					s.pop();
				}
			}
			cout << "\n";
		}
		else{
			cout << "Sandro fails.\n";
		}
	}
	
};

int main(){
	int n,m,u,v;
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	Graph *g = new Graph(false,n);
	for (int i = 0; i < m; ++i){
		cin >> u >> v;
		g->addEdge(u-1,v-1);
	}
	g->topological();
	
	return 0;
}

