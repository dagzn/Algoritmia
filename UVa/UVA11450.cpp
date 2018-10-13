/*
	Wedding Shopping - UVA Online Judge
	DP
	Solved: 23/09/18
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
int mat[20+1][200+1];
vector<vector<int>> data;
int m,c,k;

void limpiar(){
	for (int i = 0; i < 21; ++i){
		for (int j = 0; j < 201; ++j){
			mat[i][j]=0;
		}
	}
}
int dp(int pos, int dinero){
	if(dinero > m)
		return 0;
	if(pos >= c)
		return dinero;
	if(mat[pos][dinero]!=0)
		return mat[pos][dinero];
	for (int i = 0; i < data[pos].size(); ++i){
		mat[pos][dinero]=max(dp(pos+1,dinero+data[pos][i]),mat[pos][dinero]);
	}
	return mat[pos][dinero];
}
int main(){
	int t;
	cin >> t;
		while(t--){
			cin >> m >> c;
		data.resize(c);
		for (int i = 0; i < c; ++i){
			cin >> k;
			vector<int> datos(k);
			for (int j = 0; j < k; ++j){
				cin >> datos[j];
			}
			data[i]=datos;
		}
		for (int i = 0; i < data[0].size(); ++i){
			mat[0][0]=max(dp(1,data[0][i]),mat[0][0]);
		}
		if(mat[0][0] == 0)
			cout << "no solution" << endl;
		else
			cout << mat[0][0] << endl;
		limpiar();
	}
	
	return 0;
}