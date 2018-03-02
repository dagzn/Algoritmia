#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
	int n,q,stop;
	cin >> n;
	vector<int> a(n);
	//vector<pii> groups(q);
	vector<vector<pii>> groups(ceil(n/sqrt(n)));
	int aux;
	for (int i = 0; i < n; ++i){
		cin >> aux;
		a[i]= aux;
	}
	cin >> q;
	int aux2,grupo;
	for (int i = 0; i < q; ++i)
	{
		cin >> aux >> aux2;
		groups[ceil(aux/sqrt(n))-1].push_back(pii(aux2,aux));
	}


	for (int cont = 0; cont < groups.size(); ++cont){
		int res = 0;
		unordered_map<int,int> numbers;
		
		int l,r,currentl,currentr;

		if(groups[cont].size() == 0)
			continue;

		sort(groups[cont].begin(),groups[cont].end());

		//Solo el primero se hace individual
		l = groups[cont][0].second;
		r = groups[cont][0].first;
		//cout << "El primero es la pareja: " << l << " " << r << endl;
		for (int i = l-1; i < r; ++i){
			int num = a[i];
			if(numbers.count(num)){
				numbers[num]++;
			}
			else{
				//cout << "agregamos a " << num << endl;
				numbers[num]=1;
			}
		}

		cout << numbers.size() << endl;
		
		currentl = l-1;
		currentr = r-1;
		
		int num=0;

		for (int i = 1; i < groups[cont].size(); ++i){

			l = groups[cont][i].second-1;
			r = groups[cont][i].first-1;
			//cout << "pareja " << l+1 << " " << r+1 <<endl;
			while(true){
				if(currentl > l){
					//cout << "Movemos l a la izquierda\n";
					if(currentl == l)
						break;
					num = a[currentl--];
					//cout << "El l es: " << currentl << "  y num es: " << a[currentl] << "\n";
					if(numbers.count(num))
						numbers[num]++;
					else
						numbers[num]=1;
				}
				else{
					//cout << "Movemos l a la derecha\n";
					if(currentl == l)
						break;
					num = a[currentl];
					//cout << "El l es: " << currentl << "  y num es: " << a[currentl] << "\n";
					
					numbers[num]--;
					if(numbers[num] == 0){
						//cout << "quitamos\n";
						numbers.erase(num);
					}
					currentl++;
				}
				//cin >> stop;
			}

			while(true){
				if(currentr > r){
					//cout << "Movemos r a la izquierda\n";
					if(currentr == r)
						break;
					num = a[currentr];
					//cout << "El r es: " << currentr << "  y num es: " << a[currentr] << "\n";
					
					numbers[num]--;
					if(numbers[num] == 0){
						//cout << "quitamos\n";
						numbers.erase(num);
					}
					currentr--;
				}
				else{
					//cout << "Movemos r a la derecha\n";
					if(currentr == r)
						break;
					currentr++;
					num = a[currentr];
					//cout << "El r es: " << currentr << "  y num es: " << a[currentr] << "\n";
					
					if(numbers.count(num)){
						//cout << "ya esta\n";
						numbers[num]++;
					}
					else{
						//cout << "agregamos\n";
						numbers[num]=1;
					}
				}
				//cin >> stop;
			}
			cout << numbers.size() << endl;
		}
	}
	
	
	return 0;
}