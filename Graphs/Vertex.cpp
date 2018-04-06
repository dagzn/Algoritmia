#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	bool undirected;
	vector<vector<int>> adj;
	unordered_set<int> reach;
	//vector<int> nodes;

	Graph(bool undirected,int n){
		//this->undirected=undirected;
		adj.resize(n);
		//nodes.resize(n);
	}

	void addEdge(int u, int v){
		adj[u].push_back(v);
		//if(undirected)
			//adj[v].push_back(u);
	}
	void dfsvisit(int u){
		for (int i = 0; i < adj[u].size(); ++i){
			if(!reach.count(adj[u][i])){
				//nodes[adj[u][i]]++;
				reach.insert(adj[u][i]);
				dfsvisit(adj[u][i]);
			}
		}
	}

	void dfs(int s){
		//nodes.resize(adj.size(),0);
		//nodes[s]=1;
		reach.clear();
		dfsvisit(s);
		cout << adj.size()-reach.size();
		for (int i = 0; i < adj.size(); ++i)
		{
			if(!reach.count(i))
				cout << " " <<i+1;
		}
		cout << "\n";
	}
};

int main(){
	int n,a,b;
	//ios_base:: sync_with_stdio(false); cin.tie(0);
	while(cin >> n){
		if(n == 0)
			break;
		//cout << "agregamos a n\n";
		Graph *g = new Graph(false,n);
		while(cin >> a){
			if(a == 0)
				break;
			//cout << "leemos a a\n";
			while(cin >> b){
				if(b == 0)
					break;
				//cout << "metemos a la arista " << a << " " << b <<"\n";
				g->addEdge(a-1,b-1);
			}
		}
		cin >> a;
		for (int i = 0; i < a; ++i)
		{
			cin >> b;
			//cout << "hacemos query con " << b << "\n";
			g->dfs(b-1);
		}
	}
	return 0;
}