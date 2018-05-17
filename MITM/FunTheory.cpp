#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pii;
#define mod 1000000000+7
lli Exponenciar(lli a, lli n, lli m) {
	lli resultado = 1;
	for (; n; n >>= 1) {
		if (n & 1) resultado = (resultado * a) % m;
		a = (a * a) % m;
	}
	return resultado;
}

lli BabyGiant(lli a, lli c, lli m, lli k){
	int s = ceil(sqrt(m));
	//vector<pii> G(s);
	unordered_map<lli,lli> G;
	vector<pii> B(s);
	//Llenar a B
	//cout << "Llenamos a B\n";
	for (int i = 0; i < s; ++i){
		B[i]= pii((c*Exponenciar(a,i,m)) % m,i);
		//cout << "Salio " << B[i].first << " y " << B[i].second << endl;
	}
	sort(B.begin(), B.end());
	//Llenar a G
	//cout << "Llenamos a G\n";
	for (int i = 0; i < s; ++i){
		lli aux = (i+1)*(s-1);
		lli res = Exponenciar(a,aux,m);
		G[res]=aux;
		//cout << "Salio " << res << " y " << G[res] << endl;
	}
	lli resultado=0;
	//Hacer Binaria
	for (int i = 0; i < B.size(); ++i){
		if(k == 0)
			break;
		if(G.count(B[i].first)){
			cout << "Tenemos un resultado que es " << G[B[i].first] - B[i].second << endl;
			resultado+= (G[B[i].first] - B[i].second) % (mod);
			k--;
		}
	}
	return resultado;
}
int main(){
	lli t,a,c,m,k;
	cin >> t;
	for (int k = 0; k < t; ++k){
		cin >> a >> c >> m >> k;
		cout << BabyGiant(a,c,m,k)<< "\n";
	}
	return 0;
}
