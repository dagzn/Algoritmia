#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli Exponenciar(lli a, lli n, lli m) {
	lli resultado = 1;
	for (; n; n >>= 1) {
		if (n & 1) resultado = (resultado * a) % m;
		a = (a * a) % m;
	}
	return resultado;
}

int main(){
	lli A,C,M,K;
	cin >> A >> C >> M;
	for (int x = 0; x <= M; ++x)
	{
		if(Exponenciar(A,x,M) == C){
			cout << x << endl;
			break;
		}
	}
}