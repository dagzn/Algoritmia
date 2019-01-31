#define K 25
#define MAXN 1000000
class LCA
{
public:
	int logaritmo[MAXN+1];
	int st[MAXN][K],idx[MAXN][K];
	vector<int> height, euler, first;
	vector<bool> visited;
	vector<vector<int>> adj;
	
	LCA(int n){
		adj.resize(n);
	    height.resize(n);
	    first.resize(n);
	    euler.reserve(n * 2);
	    visited.assign(n, false);
	}

	void dfs(int node, int h = 0) {
	    visited[node] = true;
	    height[node] = h;
	    first[node] = euler.size();
	    euler.push_back(node);
	    for (auto to : adj[node]) {
	        if (!visited[to]) {
	            dfs(to, h + 1);
	            euler.push_back(node);
	        }
	    }
	}

	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void sparseTable(){
		int N= euler.size();
		logaritmo[1]=0;
		for(int i =2; i <= MAXN; i++)
			logaritmo[i]=logaritmo[i/2]+1l;
		for(int i=0; i < N;i++){
			st[i][0]= height[euler[i]];
			idx[i][0] = euler[i];
		}

		for(int j =1; j <= K; j++){
			for(int i =0; i +(1<<j) <= N;i++){
				if(st[i][j-1] < st[i+(1<<(j-1))][j-1]){
					st[i][j]=st[i][j-1];
					idx[i][j]=idx[i][j-1];
				}
				else{
					st[i][j]=st[i+(1<<(j-1))][j-1];
					idx[i][j]=idx[i+(1<<(j-1))][j-1];
				}
			}
		}
	}

	int rmq(int L,int R){
		int j = logaritmo[R-L+1];
		if(st[L][j] < st[R-(1<<j)+1][j])
			return idx[L][j];
		return idx[R-(1<<j)+1][j];
	}

	int getLCA(int u, int v) {
	    int left = first[u], right = first[v]; 
	    if (left > right)
	        swap(left, right);
	    return rmq(left,right);
	}
};