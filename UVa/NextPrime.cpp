#include <bits/stdc++.h>
using namespace std;
//typedef __int128 Intsote;

typedef long long int lli;

vector<bool> es_primo;
vector<lli> primos;

void criba(lli n){
	es_primo.resize(n + 1, true);
	es_primo[0] = es_primo[1] = false;
	es_primo[2] = true;
	primos.push_back(2);
	for(lli i = 4; i <= n; i += 2){
		es_primo[i] = false;
	}
	lli limit = sqrt(n);
	for(lli i = 3; i <= n; i += 2){
		if(es_primo[i]){
			primos.push_back(i);
			if(i <= limit){
				for(lli j = i * i; j <= n; j += 2 * i){
					es_primo[j] = false;
				}
			}
		}
	}
}

bool isPrime(lli n){
	if(n <= 63246){
		return es_primo[n];
	}else{
		for(lli & p : primos){
			if(p * p > n) break;
			if(n % p == 0) return false;
		}
		return true;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	lli buscar;

	criba(63246);

	cin  >> n;
	for (int k = 0; k < n; ++k)
	{
		cin >> buscar;
		if((buscar&1) == 0 && buscar != 2)
			buscar+=1;
		if(buscar == 1)
			buscar = 2;
		//cout << "Segundo bsucar: " << buscar << endl;
		for (lli i = buscar; i < 5000000000; i+=2)
		{
			lli aux = i;
			if(isPrime(aux)){
				cout << aux;
				break;
			}
		}
		if(k != n-1)
			cout << "\n";
	}
	return 0;
}
