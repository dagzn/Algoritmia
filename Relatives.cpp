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
	if(n <= 31623){
		return es_primo[n];
	}else{
		for(lli & p : primos){
			if(p * p > n) break;
			if(n % p == 0) return false;
		}
		return true;
	}
}

lli eulersQuotient(lli n){
	double res= n;
	if(n%2 == 0){
		while(n%2 == 0){
			n= n/2;
			//cout << 2 << endl; 
		}
		res*= (1.0 - (1.0 / 2));
	}
	//cout << "rESUL " << res << endl; 
	for (lli i = 3; i*i <= n; i+=2)
	{
		if(n%i == 0){
			while(n%i == 0){
				n= n/i;
				//cout << i << endl; 
			}
			res*= (1.0 - (1.0 / i));
		}
	}
	//cout << "resul " << res << " y n es " << endl;
	if(n>1){
		res*= (1.0 - (1.0/ n));
		//cout << n<< endl;
	}
	return res;
}


int main(){
	ios_base::sync_with_stdio(0);
	lli n;

	criba(31623);

	while(true){
		cin  >> n;
		if(n == 0)
			break;
		if(isPrime(n)){
			cout << n-1 << endl;
		}
		else{
			if(n == 1)
				cout << "0" << endl;
			else
				cout << eulersQuotient(n) << endl;
		}
	}
	return 0;
}