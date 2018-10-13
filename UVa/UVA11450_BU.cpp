#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,m,c,k;
	cin >> t;
	while(t--){
		cin >> m >> c;
		vector<vector<int>> datos(c);
		for (int i = 0; i < c; ++i){
			cin >> k;
			vector<int> aux(k);
			for (int j = 0; j < k; ++j){
				cin >> aux[j];
			}
			datos[i]=aux;
		}
		//bool transition[2][m+1];
		vector<bool> falsos(m+1,false);
		vector<vector<bool>> transition(2,falsos);
		//Inicializamos la primera fila
		// cout << "INICIAL\n";
		for (int i = 0; i < datos[0].size(); ++i){
			int resta = m-datos[0][i];
			if(resta>=0){
				transition[0][resta]=true;
				// cout << "Ponemos a " << resta <<'\n';
			}
		}
		int past=0,current=1;
		for (int i = 1; i < c; ++i){
			// cout << "GARMENT "<< i << "\n";
			for (int j = 0; j < m; ++j){
				if(transition[past][j]){
					// cout << "Se puede desde " << j << '\n';
					for (int l = 0; l < datos[i].size(); ++l){
						int resta = j-datos[i][l];
						if(resta >= 0){
							transition[current][resta]=true;
							// cout << "Ponemos a " << resta << "\n";
						}
					} 
				}
			}
			for(int a=0;a < transition[past].size();a++)
				transition[past][a]=false;
			// transition[past].resize(m+1,false);
			swap(past,current);
		}
		bool flag=false;
		for (int i = 0; i < m; ++i){
			if(transition[past][i]){
				cout << m-i << '\n';
				flag=true;
				break;
			}
		}
		if(!flag)
			cout << "no solution\n";
	}
	return 0;
}