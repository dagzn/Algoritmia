#include <bits/stdc++.h>
using namespace std;




class Graph
{
public:
	bool undirected;
	vector<vector<int>> adj;
	vector<vector<int>> otro;
	vector<vector<int>> cc;
	vector<int> components;
	vector<int> checked;
	stack<int> s;

	Graph(bool undirected, int n){
		adj.resize(n);
		checked.resize(n,false);
		otro.resize(n);
		this->undirected = undirected;
	}

	void addEdge(int u, int v){
		adj[u].push_back(v);
		otro[v].push_back(u);
		if(undirected)
			adj[v].push_back(u);
	}

	vector<vector<int>> reverseGraph(){
		for (int i = 0; i < checked.size(); ++i){
			checked[i] = false;
		}
		return otro;
	}

	void dfsvisit(int u, bool num){
		checked[u] = true;
		for (int v = 0; v < adj[u].size(); ++v)
		{
			if(!checked[adj[u][v]])
				dfsvisit(adj[u][v],num);		
		}
		if(num)
			s.push(u);
		else
			components.push_back(u);
	}

	void dfsFirst(){
		for (int i = 0; i < adj.size(); ++i){
			if(!checked[i])
				dfsvisit(i,true);
		}
		dfsSecond();
	}

	void dfsSecond(){
		int aux;
		adj = reverseGraph();
		for (int i = 0; i < adj.size(); ++i)
		{
			aux = s.top();
			s.pop();
			if(!checked[aux]){
				//components.push_back(aux);
				dfsvisit(aux,false);
				cc.push_back(components);
				components.clear();
			}
		}
	}
public:
	void printCC(){
		dfsFirst();
		char car;
		for (int i = 0; i < cc.size(); ++i){
			cout << "Strongly CC number " << i+1 << endl;
			for (int j = 0; j < cc[i].size(); ++j){
				car = (char) (cc[i][j]+65);
				cout << car << endl;
			}
		}
	}
	
};

int main(){
	Graph *g = new Graph(false,11);
	g->addEdge(0,1);
	g->addEdge(1,2);
	g->addEdge(2,0);
	g->addEdge(1,3);
	g->addEdge(3,4);
	g->addEdge(4,5);
	g->addEdge(5,3);
	g->addEdge(6,5);
	g->addEdge(6,7);
	g->addEdge(7,8);
	g->addEdge(8,9);
	g->addEdge(9,6);
	g->addEdge(9,10);
	g->printCC();
	return 0;
}
