class DisjointSparseTable
{
public:
	vector<vector<int>> left, right;
	int K, N;

	DisjointSparseTable(vector<int> & arr){
		N = arr.size();
		K = log2(N) + 2;
		left.assign(K + 1, vector<int>(N));
		right.assign(K + 1, vector<int>(N));
		for(int j = 0; (1 << j) <= N; ++j){
			int mask = (1 << j) - 1;
			int acum = 0; //neutral
			for(int i = 0; i < N; ++i){
				acum += arr[i]; //Operacion
				left[j][i] = acum;
				if((i & mask) == mask) acum = 0; //neutral
			}
			acum = 0; //neutral
			for(int i = N-1; i >= 0; --i){
				acum += arr[i]; //Operacion
				right[j][i] = acum;
				if((i & mask) == 0) acum = 0; //neutral
			}
		}
	}

	int query(int l, int r){
		if(l == r) return left[0][l];
		int i = 31 - __builtin_clz(l^r);
		return left[i][r] + right[i][l]; //Operacion
	}
	
};