#define K 25
#define MAXN 1000000
//Build: O(nlgn)
//Idempotent queries: O(1)
//Non-idempotent: O(lgn)
class SparseTable
{
public:
	int logaritmo[MAXN+1];
	int st[MAXN][K];

	SparseTable(int N, vector<int> &num){
		logaritmo[1]=0;
		for(int i =2; i <= MAXN; i++)
			logaritmo[i]=logaritmo[i/2]+1l;
		for(int i=0; i < N;i++)
			st[i][0]= num[i];
		for(int j =1; j <= K; j++)
			for(int i =0; i +(1<<j) <= N;i++)
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}

	int rmq(int L,int R){//Idempotent: Max,min,gcd
		int j = logaritmo[R-L+1];
		return min(st[L][j],st[R-(1<<j)+1][j]);
	}
	long long rsq(int L,int R){//Non-idempotent: sum
		long long sum=0;
		for(int j =K; j >=0; j--){
			if((1<<j) <= R-L+1){
				sum+= st[L][j];
				L+= 1<<j;
			}
		}
		return sum;
	}
};