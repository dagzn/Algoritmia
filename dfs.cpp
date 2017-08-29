#include <bits/stdc++.h>

using namespace std; 

const int MAXN = 505;

int N, M;
int Mapa[MAXN][MAXN];
int Visitados[MAXN][MAXN];
int K;
int SUM;

int movs[4][2] = {  {0, 1},
					{-1, 0},
					{1, 0},
					{0, -1}/*,
					{1, 1},
					{-1, 1},
					{-1, -1},
					{1, -1}*/
				};

void dfs(int y, int x){
	if(y >= N || y < 0 || x >= M || x < 0)
		return;
	if(Mapa[y][x] == 0)
		return;
	if(Visitados[y][x] > 0)
		return;
	Visitados[y][x] = K;
	SUM += Mapa[y][x];
	for(int i = 0; i < 4; i++)
		dfs(y + movs[i][0], x + movs[i][1]);
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> Mapa[i][j];
		}
	}

	K = 0;
	int ans = -1, region;

	for(int j = 0; j < M; j++){
		for(int i = 0; i < N; i++){
			if(!Visitados[i][j] && Mapa[i][j] != 0){
				K++;
				SUM = 0;
				dfs(i, j);
				if(ans < SUM){
					region = K;
					ans = SUM;
				}
			}
		}
	}
	cout << region << " " << ans << endl;
	return 0;
}
