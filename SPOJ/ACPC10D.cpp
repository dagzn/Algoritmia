#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
int m;
typedef pair<int,int> pii;
vector<pii> mov={{0,-1},{-1,-1},{-1,0},{-1,1}};

bool checar(int i,int j){
	if(i < 0 || i >= m)
		return false;
	if(j < 0 || j >= 3)
		return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int contador=1;
	while(true){
		cin >> m;
		if(!m)
			break;
		int mat[m][3];
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < 3; ++j){
				int menor=INF;
				cin >> mat[i][j];
				//cout << "tenemos al numero " << mat[i][j] << endl;
				if(i ==0 && j ==0){
					mat[0][0]=INF;
					continue;
				}
				for (int k = 0; k < mov.size(); ++k){
					int a = i+mov[k].first;
					int b =j+mov[k].second;
					if(checar(a,b)){
						//cout << "Nos movemos a "<< a << " , " << b << endl;
						if(mat[a][b] != INF){
							menor= min(menor,mat[a][b]+mat[i][j]);
						}
					}
				}
				if(menor != INF)
					mat[i][j]=menor;
			}
		}
		
		cout << contador << ". " << mat[m-1][1]<< "\n";
		contador++;
	}
	return 0;
}