#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
int m,n;
typedef pair<int,int> pii;
vector<pii> mov={{-1,0},{-1,-1},{-1,1}};

bool checar(int i,int j){
	if(i < 0 || i >= m)
		return false;
	if(j < 0 || j >= n)
		return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int contador=1;
	int t;
	cin >>t;
	while(t--){
		cin >> m >> n;
		int mat[2][n];
		for (int j = 0; j < n; ++j){
			cin >> mat[0][j];
		}

		int current=1,past=0;

		for (int i = 1; i < m; ++i){
			for (int j = 0; j < n; ++j){
				int x,mayor=0;
				cin >> x;
				for (int k = 0; k < mov.size(); ++k){
					int a = i+mov[k].first;
					int b = j+mov[k].second;
					if(checar(a,b)){
						mayor = max(mayor,x+mat[past][b]);
					}
				}
				mat[current][j]=mayor;
			}
			swap(current,past);
		}
		int res=0;
		for (int j = 0; j < n; ++j){
			res=max(res,mat[past][j]);
		}
		cout << res << "\n";
	}
	return 0;
}