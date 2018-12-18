#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long long Long;

vector<bool> es_primo;
vector<lli> primos;

// Exponenciacion binaria a^n mod m.
Long Exponenciar(Long a, Long n, Long m) {
	Long resultado = 1;
	for (; n; n >>= 1) {
		if (n & 1) resultado = (resultado * a) % m;
			a = (a * a) % m;
		}
	return resultado;
}

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
	if(n <= 31622){
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
	//ios_base::sync_with_stdio(0);
	criba(31622);
	lli n,res;
	while(true){
		cin >> n;
		if(n == 0ll)
			break;
		res = pow(2,n) - 1;//Exponenciar(2,n,1) - 1;
		if(isPrime(res)){
			res = pow(2,n-1) * (pow(2,n)-1);
			cout << "Perfect: " << res << "!" <<  endl;
		}
		else{
			if(isPrime(n)){
				cout << "Given number is prime. But, NO perfect number is available." << endl;
			}
			else{
				cout << "Given number is NOT prime! NO perfect number is available." << endl;
			}
		}
	}
	
	return 0;
}
