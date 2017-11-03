#include <bits/stdc++.h>
using namespace std;

bool undirected;
vector<vector<int>> adj;
vector<vector<int>> otro;
vector<vector<int>> cc;
vector<int> components;
vector<bool> checked;
stack<int> s;


void initialize(int n, bool u){
	adj.resize(n);
	checked.resize(n,false);
	otro.resize(n);
	undirected = u;
}

void addEdge(int u, int v){
	adj[u].push_back(v);
	otro[v].push_back(u);
	if(undirected)
		adj[v].push_back(u);
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
}

void dfsSecond(){
	int aux;
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

vector<vector<int>> reverseGraph(){
	for (int i = 0; i < checked.size(); ++i){
		checked[i] = false;
	}
	return otro;
}

int main(){
	initialize(11,false);
	addEdge(0,1);
	addEdge(1,2);
	addEdge(2,0);
	addEdge(1,3);
	addEdge(3,4);
	addEdge(4,5);
	addEdge(5,3);
	addEdge(6,5);
	addEdge(6,7);
	addEdge(7,8);
	addEdge(8,9);
	addEdge(9,6);
	addEdge(9,10);
	dfsFirst();
	adj = reverseGraph();
	dfsSecond();
	char car;
	for (int i = 0; i < cc.size(); ++i){
		cout << "Strongly CC number " << i+1 << endl;
		for (int j = 0; j < cc[i].size(); ++j){
			car = (char) (cc[i][j]+65);
			cout << car << endl;
		}
	}
	return 0;
}