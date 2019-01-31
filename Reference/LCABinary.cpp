typedef pair<int,int> CostoNodo;
typedef long long int lli;
class tree{
public:
	vector<lli> parent, level, weight;
	vector<vector<lli>> dists, DP;
	vector<vector<CostoNodo>> adj;
	int n, root;

	tree(int n,int root){
		this->n=n;
		this->root = root;
		adj.resize(n);
		parent.resize(n);
		level.resize(n);
		weight.resize(n);
		dists.resize(n,vector<lli>(20));
		DP.resize(n,vector<lli>(20));
		parent[root]=root;
	}

	void addEdge(int u,int v,lli w=1){
		adj[u].push_back(CostoNodo(w,v));
		adj[v].push_back(CostoNodo(w,u));
	}

	void dfs(int u){
		for(CostoNodo curr : adj[u]){
			int v = curr.second;
			int w = curr.first;
			if(v != parent[u]){
				parent[v] = u;
				weight[v] = w;
				level[v] = level[u] + 1;
				dfs(v);
			}
		}
	}

	void pre(){
		dfs(root);
		for(int u = 0; u < n; u++){
			DP[u][0] = parent[u];
			dists[u][0] = weight[u];
		}
		for(int i = 1; (1 << i) <= n; ++i){
			for(int u = 0; u < n; ++u){
				DP[u][i] = DP[DP[u][i - 1]][i - 1];
				dists[u][i] = dists[u][i - 1] + dists[DP[u][i - 1]][i - 1];
			}
		}
	}
	//Get the node k levels above you.
	int ancestor(int p, int k){
		if(k < 0)
			return -1;
		int h = level[p] - k;
		if(h < 0) return -1;
		int lg;
		for(lg = 1; (1 << lg) <= level[p]; ++lg);
		lg--;
		for(int i = lg; i >= 0; --i){
			if(level[p] - (1 << i) >= h){
				p = DP[p][i];
			}
		}
		return p;
	}
	//Get the Lowest Common Ancestor of two nodes, p and q
	int lca(int p, int q){
		if(level[p] < level[q]) swap(p, q);
		int lg;
		for(lg = 1; (1 << lg) <= level[p]; ++lg);
		lg--;
		for(int i = lg; i >= 0; --i){
			if(level[p] - (1 << i) >= level[q]){
				p = DP[p][i];
			}
		}
		if(p == q) return p;
	 
		for(int i = lg; i >= 0; --i){
			if(DP[p][i] != -1 && DP[p][i] != DP[q][i]){
				p = DP[p][i];
				q = DP[q][i];
			}
		}
		return parent[p];
	}
	//Get the total distance of the path between two nodes in a tree
	lli dist(int p, int q){
		if(level[p] < level[q]) swap(p, q);
		int lg;
		for(lg = 1; (1 << lg) <= level[p]; ++lg);
		lg--;
		lli sum = 0;
		for(int i = lg; i >= 0; --i){
			if(level[p] - (1 << i) >= level[q]){
				sum += dists[p][i];
				p = DP[p][i];
			}
		}
		if(p == q) return sum;
	 
		for(int i = lg; i >= 0; --i){
			if(DP[p][i] != -1 && DP[p][i] != DP[q][i]){
				sum += dists[p][i] + dists[q][i];
				p = DP[p][i];
				q = DP[q][i];
			}
		}
		sum += dists[p][0] + dists[q][0];
		return sum;
	}
	//Get the k-th element from the path starting at a and ending at b
	int kthelement(int a,int b,int k){
		int w = lca(a,b);//O(lg)
		if(k <= (level[a]-level[w]+1))//O(1)
			return ancestor(a,k-1);//O(klg)
		int izquierdo = level[a]-level[w]+1;//Elementos del lado izq y raiz
		int derecho = level[b]-level[w];//Elementos lado derecho
		int new_k = k-izquierdo;
		int retornar = derecho-new_k;
		return ancestor(b,retornar);//O(klg)
	}
};