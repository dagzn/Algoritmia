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
	if(n <= 50000){
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
	lli a,b;
	
	criba(50000);
	
	while(cin >> a >> b){
		//cin >> a >> b;
		//if(a==0 && b==0)
		//	break;

		lli left=0,right=0;
		pair<lli,lli> menores;
		pair<lli,lli> mayores;
		bool der=false;

		for (lli i = a; i <= b; ++i)
		{
			if(isPrime(i)){
				if(left == 0 && !der){
					left = i;
					der = true;
				}
				else{
					if(left != 0 && der){
						right = i;
						a = i;
						break;
					}
				} 
			}
		}
		if(left ==0 || right == 0){
			cout << "There are no adjacent primes." << endl;
		}
		else{
			menores.first = left;
			menores.second = right;
			mayores.first = left;
			mayores.second = right;

			left = a;
			for (lli i = a+2; i <= b; i+=2)
			{
				if(isPrime(i)){
					right = i;
					if(right - left > mayores.second-mayores.first){
						mayores.first = left;
						mayores.second = right;
					}
					if(right - left < menores.second-menores.first){
						menores.first = left;
						menores.second = right;
					}
					left = right;
				}
			}
			cout << menores.first << "," << menores.second << " are closest, "<< mayores.first << "," << mayores.second << " are most distant."<<endl;
		}	
	}
	return 0;
}
