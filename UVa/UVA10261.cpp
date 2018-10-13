#include <bits/stdc++.h>
using namespace std;
int ferry;
int n;
vector<int> tam;
int dp[105][10005];

int floading(int pos,int izq,int der,int cont){
	cout << "Llegamos pos " << pos << " con izq de " << izq << " y der " << der << " con un cont " << cont << endl;
	if(pos >= n){
		cout << "Acabamos num reg " << cont << endl;
		return cont;
	}
	int dif = abs(izq-der);
	cout << "Tenemos dif de " << dif << endl;
	if(dp[pos][dif] != 0)
		return dp[pos][dif];

	if(izq > ferry || der > ferry){
		cout << "regre un cero\n";
		return 0;
	}
	int res=cont;
	if(izq+tam[pos] <= ferry)
		dp[pos][dif]=max(cont,floading(pos+1,izq+tam[pos],der,cont+1));
	if(der+tam[pos] <=ferry)
		dp[pos][dif]=max(cont,floading(pos+1,izq,der+tam[pos],cont+1));
	return dp[pos][dif];
}

int main(){
	cin >> ferry;
	cin >> n;
	tam.resize(n);
	for (int i = 0; i < n; ++i){
		cin >> tam[i];
	}
	cout << floading(0,0,0,0) << endl;
	return 0;
}