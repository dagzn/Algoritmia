#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define forn(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n,k;
void printm(vvi &a){
	forn(i,1,n+1){
		forn(j,1,n+1){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){__
	cin >> n >> k;
	vvi mat(n+5,vi(n+5));
	char c;
	forn(i,1,n+1)
		forn(j,1,n+1){
			cin >> c;
			if(c == 'B') mat[i][j]=1; else mat[i][j]=0;
		}
	vvi rows(n+5,vi(n+5));
	vi iswr(n+5),iswc(n+5);
	int totw=0;
	forn(i,1,n+1){
		forn(j,1,n+1){
			if(mat[i][j] == 1) rows[i][j] = 1;
			rows[i][j]+=rows[i][j-1];
		}
		if(rows[i][0] == rows[i][n] && rows[i][0] == 0){
			iswr[i]=1;
			totw++;
		}
	}
	printm(rows);
	vvi cols(n+5,vi(n+5));
	forn(j,1,n+1){
		forn(i,1,n+1){
			if(mat[i][j] == 1) cols[i][j] = 1;
			cols[i][j]+=cols[i-1][j];
		}
		if(cols[0][j] == cols[n][j] && cols[j][0] == 0){
			iswc[j]=1;
			totw++;
		}
	}
	printm(cols);
	//sliding window para rows
	int cont =0,currw =0;
	vvi res(n+5,vi(n+5,0));
	for(int j =1; j <=n; j++){
		if(j+k-1 > n) break;
		cont =0;
		for(int i =1; i <= k; i++){
			if(iswr[i])
				currw++;
			if((rows[i][j+k-1] - rows[i][j-1]) == (rows[i][n] - rows[i][0]))
				cont++;
		}
		res[1][j] +=(cont + totw - currw);
		for(int i =2; i <=n; i++){
			if(i+k-1 > n) break;
			//check past
			if(iswr[i-1])
				currw--;
			if((rows[i-1][j+k-1] - rows[i-1][j-1]) == (rows[i-1][n] - rows[i-1][0]))
				cont--;
			//check current
			if(iswr[i+k-1])
				currw++;
			if((rows[i+k-1][j+k-1] - rows[i+k-1][j-1]) == (rows[i+k-1][n] - rows[i+k-1][0]))
				cont++;
			res[i][j]+=cont + totw - currw;	
		}
	}
	//sliding para cols
	cont =0,currw = 0;
	for(int i =1; i <=n;i++){
		if(i+k-1 > n) break;
		cont =0;
		for(int j =1; j <=k; j++){
			if(iswc[j])
				currw++;
			if((cols[i+k-1][j] - cols[i-1][j]) == (cols[n][j] - cols[0][j]))
				cont++;
		}
		res[i][1] +=cont + totw - currw;
		for(int j =2; j <=n; j++){
			if(j+k-1 > n) break;
			if(iswc[j-1])
				currw--;
			if((cols[i+k-1][j-1] - cols[i-1][j-1]) == (cols[n][j-1] - cols[0][j-1]))
				cont--;
			if(iswc[j+k-1])
				currw++;
			if((cols[i+k-1][j+k-1] - cols[i-1][j+k-1]) == (cols[n][j+k-1] - cols[0][j+k-1]))
				cont++;
			res[i][j]+=cont + totw-currw;
		}
	}
	int ans = 0;
	forn(i,1,n+1)
		forn(j,1,n+1)
			ans = max(res[i][j],ans);
	cout << ans << endl;	
	return 0;
}
